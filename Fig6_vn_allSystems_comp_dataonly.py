
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
	"vn_pp":ROOT.TFile("data/Final_Items.root","read"), # pp 1<pT<2 GeV
	"vn_pp_14":ROOT.TFile("data/Final_Items.root","read"), # pp 1<pT<4 GeV
	"vn_pPb_v0a":ROOT.TFile("data/fout_v2_pPb_v1.root","read"),  # pPb 1<pT<2 GeV
	"vn_pPb_v0a_14":ROOT.TFile("data/fout_v2_pPb_v1.root","read")  # pPb 1<pT<4 GeV
}

plotParams = {
	"vn_pp":{"color":"k","fmt":"o","markersize":5.0,"label":"pp 13 TeV, $1 < p_\\mathrm{T} < 2.0 \\,\\mathrm{GeV}/c$","labelLegendId":0},
	"vn_pp_14":{"color":"r","fmt":"o","mfc":"none","markersize":5.0,"label":"pp 13 TeV","labelLegendId":0},
	"vn_pPb_v0a":{"color":"k","fmt":"*","markersize":5.0,"label":"p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV ","labelLegendId":0},
	"vn_pPb_v0a_14":{"color":"b","fmt":"D","mfc":"none","markersize":5.0,"label":"p$-$Pb 5.02 TeV","labelLegendId":0}	
}	
#Histogran names corresponding to system and experiment
histNames = ["pp","pp_14","pPb_v2_v0a","pPb_14"];

# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(0,65),(0,65)];
ylimits = [(-0.02,0.185)];
rlimits = [(0.5,1.6),(0.,4.5)];

# add labels for each pad
plables = [ "", ""
		 ];

xtitle = ["$N_\\mathrm{ch}(|\eta|<0.5)$",""];
ytitle = ["$v_{2}$","$v_{3}$"];
#labelList = ["pp $\\sqrt{s}$ = 13 TeV our","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV our","pp $\\sqrt{s}$ = 13 TeV","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV"]


# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];

plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	#panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(-0.010,0.10)},
	majorTickMultiple=10,
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	#legendPanel={0:0,1:0,2:0},
	legendPanel={0:0,1:1,2:0},
	#legendLoc={0:(0.68,0.34),1:(0.49,0.5),2:(0.68,0.14)},
	legendLoc={0:(0.68,0.34),1:(0.40,0.17),2:(0.68,0.14)},
	legendSize=9,xlabel=xtitle[0],ylabel=ytitle,ylabelRight=ytitle[1]);

plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

for i in range(0,2):
	plot.GetAxes(i).xaxis.set_ticks_position('both');
	plot.GetAxes(i).yaxis.set_ticks_position('both');
	plot.GetAxes(i).yaxis.set_major_locator(plticker.MaxNLocator(7));

plotsV2 = {};
plotsV3 = {};

for i,s in enumerate(data):
	print(i,s)
	print(histNames[i])
	gr = data[s].Get("{}_stat".format(histNames[i]));
	grsyst = data[s].Get("{}_syst".format(histNames[i]));
	x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch
	plotsV2[s] = plot.Add(0,(x,y,yerr),**plotParams[s]); # to replace with ATLAS converted Nch
	plot.AddSyst(plotsV2[s],grsyst);

	#v3
	if(i<2):
		gr = data[s].Get("{}_v3_stat".format(histNames[i]));
		grsyst = data[s].Get("{}_v3_syst".format(histNames[i]));
		x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch
		plotsV3[s] = plot.Add(1,(x,y,yerr),**plotParams[s]); # to replace with ATLAS converted Nch
		plot.AddSyst(plotsV3[s],grsyst);
#plot.Ratio(plots["vn_pp_14"], plots["vn_pp"]);
#plot.Ratio(plots["vn_pPb_v0a_14"], plots["vn_pPb_v0a"]);

plot.GetPlot().text(0.14,0.80,"ALICE",fontsize=12);
plot.GetPlot().text(0.15,0.20,"$1.6<|\Delta\eta|<1.8$\n$1.0<p_\\mathrm{T}<4.0\\,\\mathrm{GeV}$",fontsize=9);

#-----------------------------------------------------------

plot.Plot();

plot.GetAxes(1).yaxis.tick_right();

plot.Save("figs/Fig6_vnMult_allSystemsDataOnly.pdf");
plot.Save("figs/Fig6_vnMult_allSystemsDataOnly.png");
plot.Show();

