
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
	"vn_pPb_v0a_14":ROOT.TFile("data/fout_v2_pPb_v2.root","read"),  # pPb 1<pT<4 GeV
}

plotParams = {
	"vn_pp":{"color":"k","fmt":"o","markersize":5.5,"label":"pp 13 TeV, $1<p_\\mathrm{T}<2.0\\,\\mathrm{GeV}/c$","labelLegendId":0},
	"vn_pp_14":{"color":"r","fmt":"o","mfc":"none","markersize":5.5,"label":"pp 13 TeV, $1<p_\\mathrm{T}<4.0\\,\\mathrm{GeV}/c$","labelLegendId":0},
	"vn_pPb_v0a_14":{"color":"b","fmt":"s","mfc":"none","markersize":5.5,"label":"p$-$Pb 5.02 TeV, $1<p_\\mathrm{T}<4.0\\,\\mathrm{GeV}/c$","labelLegendId":0},
}	
#Histogran names corresponding to system and experiment
histNames = ["pp","pp_14","pPb_14"];
#histNames = ["pp_14","pPb_14"];

#XXX for this plotter, font size 14 roughly corresponds to the text size.

# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(5,52),(7,52)];
ylimits = [(-0.01,0.13),(-0.01,0.13)];
rlimits = [(0.5,1.6),(0.,4.5)];

# add labels for each pad
plables = [ "$n = 2$", "$n = 3$" ];

xtitle = ["$N_\\mathrm{ch}(|\eta|<0.5)$",""];
ytitle = ["$v_{2}$","$v_{3}$"];

# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];

plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(4,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(-0.01,0.07)},
	majorTickMultiple=5,
	systPatchWidth=0.02,
	panelLabelLoc=(0.7,0.90),panelLabelSize=12,panelLabelAlign="left",
	#legendPanel={0:0,1:0,2:0},
	legendPanel={0:0,1:0},
	#legendLoc={0:(0.68,0.34),1:(0.49,0.5),2:(0.68,0.14)},
	legendLoc={0:(0.55,0.20),1:(0.45,0.17)},
	axisLabelSize=11,tickLabelSize=10,legendSize=10,xlabel=xtitle[0],ylabel=ytitle,ylabelRight=ytitle[1]);

plot.EnableLatex(True);

plot.GetAxes(0).yaxis.set_major_locator(plticker.MaxNLocator(7));
plot.GetAxes(1).yaxis.set_major_locator(plticker.MaxNLocator(7));

plotsV2 = {};

nmeas=4;
for i,s in enumerate(data):
	print(s)
	for vi in range(0,2):
		name = "{}_{}".format(histNames[i],"v3_" if vi > 0 else ("v2_" if i > 1 else ""));
		print("  {}{}".format(name,"stat"));
		gr = data[s].Get("{}{}".format(name,"stat"));
		grsyst = data[s].Get("{}{}".format(name,"syst"));
		x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch
		plotsV2[s] = plot.Add(vi,(x,y,yerr),**plotParams[s]); # to replace with ATLAS converted Nch
		plot.AddSyst(plotsV2[s],grsyst);

plot.Ratio(plotsV2["vn_pp_14"],plotsV2["vn_pp"]);

#plot.GetPlot().text(0.18,0.80,"ALICE",fontsize=12);
plot.GetPlot().text(0.15,0.80,"ALICE Preliminary",fontsize=12);
#plot.GetPlot().text(0.45,0.58,"$1.6<|\Delta\eta|<1.8$",fontsize=9);
plot.GetPlot().text(0.35,0.47,"$1.6<|\Delta\eta|<1.8$",fontsize=10);

#-----------------------------------------------------------

plot.Plot();

plot.GetAxes(1).yaxis.tick_right();

for a in plot.ax.flat[1:]: #hack
	a.yaxis.set_ticks_position('both');

plot.Save("figs/Fig6_v2Mult_allSystems_Data.pdf");
plot.Save("figs/Fig6_v2Mult_allSystems_Data.png");
#plot.Show();

