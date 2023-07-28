
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
import pickle
sys.path.append("JPyPlotRatio");

import JPyPlotRatio
import matplotlib.ticker as plticker

from matplotlib import rc



data = {
	"vn_pp_14":ROOT.TFile("data/fout_vn_28jun2023.root","read"), # pp 1<pT<4 GeV
	"vn_pPb_v0a_14":ROOT.TFile("data/fout_vn_28jun2023.root","read"),  # pPb 1<pT<4 GeV
}

plotParams = {
	"vn_pp_14":{"color":"r","fmt":"o","markersize":5.5,"label":"pp $\\sqrt{s}$ = 13 TeV","labelLegendId":0},
	"vn_pPb_v0a_14":{"color":"b","fmt":"s","mfc":"none","markersize":5.5,"label":"p--Pb $\\sqrt{s_{\\rm NN}} = 5.02$ TeV","labelLegendId":0},
}	
#Histogran names corresponding to system and experiment
histNames = ["pp_14","pPb_14"];

#XXX for this plotter, font size 14 roughly corresponds to the text size.

# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(0,65),(0,65)];
ylimits = [(-0.01,0.185)];
rlimits = [(0.5,1.6),(0.,4.5)];

# add labels for each pad
plables = [ "", ""]

xtitle = ["$N_\\mathrm{ch}(|\eta|<0.5)$",""];
ytitle = ["$v_{2}$","$v_{3}$"];

# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(4,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	#panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(-0.015,0.10)},
	majorTickMultiple=10,
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	#legendPanel={0:0,1:0,2:0},
	legendPanel={0:0,1:1,2:0},
	#legendLoc={0:(0.68,0.34),1:(0.49,0.5),2:(0.68,0.14)},
	legendLoc={0:(0.64,0.34),1:(0.5,0.16),2:(0.60,0.14)},
	axisLabelSize=11,tickLabelSize=11,legendSize=8.5,xlabel=xtitle[0],ylabel=ytitle,ylabelRight=ytitle[1]);

plot.EnableLatex(True);

#--- hydro calculation -------------------------------------
#pPb_hydro_mult = np.array([171.9,74.0,65.9,54.1,44.1,32.8,25.4,19.6,14.7,10.6]); #fine bins
for si,(s,color,label) in enumerate([
	("results_QM2018_pPb_502.root","green","MAP(QM2018), $m=6$"),
	("results_dual_MAP_pPb_502.root","deeppink","MAP(2021), $m=6$")]):
	fh = ROOT.TFile("data/{}".format(s),"read")
	pPb_hydro_mult = np.array([171.9,54.1,44.1,32.8,25.4,19.6,14.7,10.6]);
	pPb_hydro_mult_avg = 0.5*(pPb_hydro_mult[:-1]+pPb_hydro_mult[1:])
	for i,n in enumerate(range(2,4)):
		gr = fh.Get("gr_v{}_QC".format(n));
		_,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr);
		plot.Add(i,(pPb_hydro_mult_avg[1:],y[1:],yerr[1:]),linecolor=color,linestyle="dashdot",color=color,plotType="theory",alpha=0.4,label="T\\raisebox{-.5ex}{R}ENTo"+", {}, p--Pb 5.02 TeV".format(label),labelOrder=1,labelLegendId=1);
	fh.Close();

with open("data/hydroschenke/schenke_SmallSystem.pkl","rb") as f:
	schenkeDict = pickle.load(f);
for i,n in enumerate(range(2,4)):
	for s,label,color in [
		(('pPb5020','v{}'.format(n),'1_4'),"IP-Glasma $\\eta/s=0.12$, $\\zeta/s(T)$, p--Pb 5.02 TeV","royalblue"),
		(('pp13TeV','v{}'.format(n),'1_4'),"IP-Glasma $\\eta/s=0.12$, $\\zeta/s(T)$, pp 13 TeV","darkorange")]:
		d = schenkeDict[s];
		plot.Add(i,(d["mult"],d["y"],d["yerr"]),plotType="theory",linecolor=color,color=color,alpha=0.4,label=label,labelOrder=2,labelLegendId=1);

#GubsHyd Farid's
color = ["coral","red"]
#gubparam=["$\\sigma_{r}$ = 0.40[fm]$, \\chi \\sigma_{\\epsilon}$ = 0.097",
#		"$\\sigma_{r}$ = 0.62[fm]$, \\chi \\sigma_{\\epsilon}$ = 0.086"]
gubparam=["param0",
		"param1"]
for i,p in enumerate([0,1]):
	d = np.loadtxt("data/GubsHyd/gubshyd_param{}.dat".format(p));
	plot.Add(0,(d[:,0],d[:,1]),linestyle=["--","-"][i],linecolor=color[i],color=color[i],plotType="theory",alpha=0.4,labelLegendId=2,label="GubsHyd, {}, pp 13 TeV".format(gubparam[p]));
#GubsHyd pPb
gubparamPb = "GubsHyd, $\\sigma_{r}$ = 0.72[fm]$, \\chi \\sigma_{\\epsilon}$ = 0.11, p--Pb 5.02 TeV";
gubparamPb = "GubsHyd, param2, p--Pb 5.02 TeV";
d = np.loadtxt("data/GubsHyd/gubshyd_pPb_param2.dat");
plot.Add(0,(d[:,0],d[:,1]),linestyle="-",linecolor="deepskyblue",color="deepskyblue",plotType="theory",alpha=0.4,labelLegendId=2,label=gubparamPb);

plotMatrix = np.empty((nrow,ncol),dtype=int);

for i in range(0,2):
	plot.GetAxes(i).yaxis.set_major_locator(plticker.MaxNLocator(7));
##plot.ax.flat[0].yaxis.set_ticks_position('both');

plotsV2 = {};
plotsV3 = {};

nmeas=4;
for i,s in enumerate(data):
	print(s)
	for vi in range(0,2):
		name = "{}_{}".format(histNames[i],"v3_" if vi > 0 else ("v2_" if i == 1 else ""));
		print("  {}{}".format(name,"stat"));
		gr = data[s].Get("{}{}".format(name,"stat"));
		grsyst = data[s].Get("{}{}".format(name,"syst"));
		x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch
		plotsV2[s] = plot.Add(vi,(x,y,yerr),**plotParams[s]); # to replace with ATLAS converted Nch
		plot.AddSyst(plotsV2[s],grsyst);

plot.GetPlot().text(0.14,0.80,"ALICE",fontsize=14);
plot.GetPlot().text(0.33,0.755,"$1.6<|\Delta\eta|<1.8$\n$1<p_\\mathrm{T}<4\\,\\mathrm{GeV}/c$",fontsize=12);

rc('font',**{'family':'serif','serif':['Helvetica']})
#rc('font',**{'family':'serif','serif':['Times']})
#rc('text', usetex=True)

#-----------------------------------------------------------

plot.Plot();

plot.GetAxes(1).yaxis.tick_right();

for a in plot.ax.flat[1:]: #hack
	a.yaxis.set_ticks_position('both');

plot.Save("figures/FIG7_v2Mult_allSystems_Hydro.pdf");
plot.Save("figures/FIG7_v2Mult_allSystems_Hydro.png");
plot.Show();

