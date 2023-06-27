
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");


import JPyPlotRatio

fpPb = ROOT.TFile("data/Final_Items.root","read");

f = ROOT.TFile("data/Final_Items.root","read");
dataTypePlotParams = [
	{'plotType':'data','color':'k','fmt':'o','markersize':5.0},
	{'plotType':'data','color':'b','fmt':'s','fillstyle':'none','markersize':5.0},
	{'plotType':'data','color':'r','fmt':'s','fillstyle':'none','markersize':5.0},
	{'plotType':'theory','facecolor':'k','edgecolor':'k','alpha':0.5,'linestyle':'dotted','linecolor':'k'},
	{'plotType':'theory','facecolor':'b','edgecolor':'b','alpha':0.5,'linestyle':'solid','linecolor':'b'},
	{'plotType':'theory','facecolor':'r','edgecolor':'r','alpha':0.5,'linestyle':'dashed','linecolor':'r'},
	{'plotType':'theory','facecolor':'C3','edgecolor':'C3','alpha':0.5,'linestyle':'dashdot','linecolor':'C3'},
];


# define panel/xaxis limits/titles
nrow = 1;
ncol = 1;
xlimits = [(0,4)];
ylimits = [(-0.005,0.195)];
rlimits = [(0.,4.5),(0.,4.5)];


# add here the histogram names for each pad
histnames = ["NearJet","Acceptance_d"];
histnameAway = ["AwayJet_d"];

# add labels for each pad
plables = [ "", ""
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];
# model names : for histonames in ROOT file
centrality =["ALICE near $|\\Delta\\eta|<$1.3","PYTHIA 8 Tune 4C near, $|\\Delta\\eta|<$1.3",
	"ALICE away $\\times$ 2, Template fit, $|\\Delta\\eta|<$1.3", "PYTHIA 8 Tune 4C away $\\times$ 2, $|\\Delta\\eta|<$1.3"];

#xtitle = ["$p_\\mathrm{T,trig(assoc)} (\\mathrm{GeV}/c)$"];
xtitle = ["$N_\\mathrm{ch} (|\eta|<0.5)$",""];
#xtitle = ["$N_\\mathrm{ch}$",""];
ytitle = ["$V_{2}$"," $2Y_\\mathrm{frag}^\\mathrm{away}/Y_\\mathrm{frag}^\\mathrm{near}$"];


# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];
#dataDetail = ["","$1.6 < |\\Delta\\eta| < 1.8$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel=0,
	legendLoc=(0.4,0.75),legendSize=12,xlabel=xtitle[0],ylabel=ytitle[0]);

plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

plot.GetAxes(0).set_xticks([0,15, 30, 45,60]);
plot.GetAxes(0).xaxis.set_ticks_position('both');
plot.GetAxes(0).yaxis.set_ticks_position('both');



gr = f.Get("pp_14_stat");
data = plot.Add(0,gr,**dataTypePlotParams[0],labelLegendId=0,label="$1 < p_\\mathrm{T} < 4 \\,\\mathrm{GeV}/c$");
grsyst = f.Get("pp_14_syst");
_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
plot.AddSyst(data,syst);

#gr1 = f.Get("pPb_stat");
#data1 = plot.Add(0,gr1,**dataTypePlotParams[1],labelLegendId=0,label="p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV");
#grsyst1 = f.Get("pPb_syst");
#_,_,_,syst1 = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst1));
#plot.AddSyst(data1,syst1);


#gr1 = f.Get("pPb_v2_zna_stat");
#data1 = plot.Add(0,gr1,**dataTypePlotParams[1],labelLegendId=0,label="p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, ZNA");
#grsyst1 = f.Get("pPb_v2_zna_syst");
#_,_,_,syst1 = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst1));
#plot.AddSyst(data1,syst1);

gr2 = fpPb.Get("pp_stat");
data2 = plot.Add(0,gr2,**dataTypePlotParams[2],labelLegendId=0,label="$1 < p_\\mathrm{T} < 2 \\,\\mathrm{GeV}/c$");
grsyst2 = fpPb.Get("pp_syst");
_,_,_,syst2 = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst2));
plot.AddSyst(data2,syst2);




f.Close();

plot.GetPlot().text(0.19,0.8,"ALICE Work in progress",fontsize=14);
plot.GetPlot().text(0.55,0.2,"pp $\\sqrt{s}$ = 13 TeV",fontsize=14);
plot.GetPlot().text(0.55,0.28,"$1.6<|\Delta\eta|<1.8$",fontsize=14);


#plot.GetPlot().text(0.19,0.14,dataDetail[0],fontsize=11);


plot.Plot();

plot.Save("figs/Fig6_v2Mult_pp.pdf");
plot.Save("figs/Fig6_v2Mult_pp.png");
plot.Show();

