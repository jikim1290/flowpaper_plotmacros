
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
import pickle
sys.path.append("JPyPlotRatio");

import JPyPlotRatio
import matplotlib.ticker as plticker

data = {
	"vn_pPb_v0a_14":ROOT.TFile("data/fout_v2_pPb_v1.root","read"),  # pPb 1<pT<4 GeV
}

plotParams = {
	"vn_pPb_v0a_14":{"color":"b","fmt":"D","mfc":"none","markersize":5.0,"label":"p$-$Pb 5.02 TeV","labelLegendId":0},
}	
histNames = ["pPb_14"];
histNamesAtlas = ["pPb"];
NremoveAtlas =[3,5]

# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(0,65),(0,65)];
#ylimits = [(-0.005,0.170)];
#rlimits = [(0.5,1.6),(0.,4.5)];

xtitle = ["$N_\\mathrm{ch}(|\eta|<0.5)$",""];
#ytitle = ["$V_{2}$","$V_{2}\\{4\\}$"];
ytitleVnEcc = ["$v_{2}/\\varepsilon_{2}$","$v_{3}/\\varepsilon_{3}$"];
ytitleEcc = ["$\\varepsilon_{2}$","$\\varepsilon_{3}$"];
#labelList = ["pp $\\sqrt{s}$ = 13 TeV our","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV our","pp $\\sqrt{s}$ = 13 TeV","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV"]

plotVnEcc = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	#rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	#ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	#panelPrivateRowBounds={1:(0.01,0.10)},
	majorTickMultiple=10,
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel={0:1},#,1:1},
	legendLoc={0:(0.6,0.8)},
	legendSize=9,xlabel=xtitle[0],ylabel=ytitleVnEcc,ylabelRight=ytitleVnEcc[1]);

plotEcc = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds={0:(0.420-0.13,0.420)},  # for nrow
	colBounds=xlimits,  # for ncol
	#panelLabel=plables,  # nrowxncol
	#ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(0.330-0.13,0.330)},
	majorTickMultiple=10,
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	#legendPanel={0:0,1:0,2:0},
	legendPanel={0:1},#,1:1},
	#legendLoc={0:(0.63,0.22),1:(0.6,0.8),2:(0.75,0.12)},
	legendLoc={0:(0.6,0.8)},
	legendSize=9,xlabel=xtitle[0],ylabel=ytitleEcc,ylabelRight=ytitleEcc[1]);

plotVnEcc.EnableLatex(True);
plotEcc.EnableLatex(True);

eccArrays = [];
#--- hydro calculation -------------------------------------
for si,(s,color,label) in enumerate([
	("results_QM2018_pPb_502.root","blue","{T\\raisebox{-.5ex}{R}ENTo}(QM2018)"),
	("results_dual_MAP_pPb_502.root","slateblue","MAP(2021), m=6")]):
	fh = ROOT.TFile("data/{}".format(s),"read")
	pPb_hydro_mult = np.array([171.9,54.1,44.1,32.8,25.4,19.6,14.7,10.6]);
	pPb_hydro_mult_avg = 0.5*(pPb_hydro_mult[:-1]+pPb_hydro_mult[1:])
	for i,n in enumerate(range(2,4)):
		gr = fh.Get("gr_v{}_QC".format(n));
		_,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr);
		#----
		gr = fh.Get("gr_ecc{}".format(n));
		xecc,yecc,_,yerrEcc = JPyPlotRatio.TGraphErrorsToNumpy(gr);
		plotVnEcc.Add(i,JPyPlotRatio.RatioSamples((pPb_hydro_mult_avg[1:],y[1:],yerr[1:]),(xecc,yecc,yerrEcc)),linecolor=color,linestyle=":",color=color,plotType="theory",alpha=0.4,label="Hydro/"+label,labelOrder=1,labelLegendId=0);
		plotEcc.Add(i,(xecc,yecc,yerrEcc),linecolor=color,linestyle=":",color=color,plotType="theory",alpha=0.4,label=label,labelOrder=1,labelLegendId=0);
		eccArrays.append((xecc,yecc,yerrEcc));
	fh.Close();

for plot in [plotVnEcc,plotEcc]:
	for i in range(0,2):
		plot.GetAxes(i).xaxis.set_ticks_position('both');
		plot.GetAxes(i).yaxis.set_ticks_position('both');
		plot.GetAxes(i).yaxis.set_major_locator(plticker.MaxNLocator(7));

for i,s in enumerate(data):
	print(s)

	gr = data[s].Get("{}_stat".format(histNames[i]));
	grsyst = data[s].Get("{}_syst".format(histNames[i]));
	x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch

	if s == "vn_pPb_v0a_14":
		a = JPyPlotRatio.RatioSamples((x,y,yerr),eccArrays[0]);
		plotVnEcc.Add(0,a,color="red",edgecolor="red",linecolor="red",alpha=0.5,plotType="theory",label="Data/{T\\raisebox{-.5ex}{R}ENTo}(QM2018)"); # to replace with ATLAS converted Nch

for plot in [plotVnEcc,plotEcc]:
	plot.GetPlot().text(0.35,0.38,"$1.6<|\Delta\eta|<1.8$\n$1.0<p_\\mathrm{T}<4.0\\,\\mathrm{GeV}$",fontsize=12);
	plot.Plot();
	plot.GetAxes(1).yaxis.tick_right();

plotVnEcc.Save("figs/Fig6_vn_ecc.pdf");
plotEcc.Save("figs/Fig6_ecc.pdf");
#plotVnEcc.Show();
plotVnEcc.Show();

