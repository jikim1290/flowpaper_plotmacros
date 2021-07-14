
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");


import JPyPlotRatio


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
nrow = 2;
ncol = 1;
xlimits = [(0,4)];
ylimits = [(0.055,0.165),(0.6,1.0)];
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
xtitle = ["",""];
ytitle = ["$Y_\\mathrm{frag}$"," $2Y_\\mathrm{frag}^\\mathrm{away}/Y_\\mathrm{frag}^\\mathrm{near}$"];


# Following two must be added
toptitle = "pp $\\sqrt{s}$ = 13 TeV"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];
#dataDetail = ["","$1.6 < |\\Delta\\eta| < 1.8$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(6,4),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0,1],
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel={0:0,1:1},
	legendLoc={0:(0.7,0.81),1:(0.75,0.2)},legendSize=9,xlabel={0:xtitle[0],1:xtitle[1]},ylabel={0:ytitle[0],1:ytitle[1]},fontsize=1);


plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

plot.GetAxes(0).set_xticks([0,1,2,3]);
plot.GetAxes(0).xaxis.set_ticks_position('both');
plot.GetAxes(0).yaxis.set_ticks_position('both');
gr = f.Get("{}_stat".format(histnames[0]));
data = plot.Add(0,gr,**dataTypePlotParams[0],labelLegendId=0,label=centrality[0]);
grsyst = f.Get("{}_syst".format(histnames[0]));
_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
plot.AddSyst(data,syst);

grMC = f.Get("{}_MC".format(histnames[0]));
dataMC = plot.Add(0,grMC,**dataTypePlotParams[3],labelLegendId=0,label=centrality[1]);

gr = f.Get("{}_stat".format(histnameAway[0]));
data = plot.Add(0,gr,**dataTypePlotParams[1],labelLegendId=0,label=centrality[2]);
grsyst = f.Get("{}_syst".format(histnameAway[0]));
_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
plot.AddSyst(data,syst);
grMC = f.Get("{}_MC".format(histnameAway[0]));
dataMC = plot.Add(0,grMC,**dataTypePlotParams[4],labelLegendId=0,label=centrality[3]);



plot.GetAxes(1).set_xticks([0,1,2,3]);
plot.GetAxes(1).xaxis.set_ticks_position('both');
plot.GetAxes(1).yaxis.set_ticks_position('both');
gr = f.Get("{}_stat".format(histnames[1]));
data = plot.Add(1,gr,**dataTypePlotParams[2],labelLegendId=1,label="ALICE");
grsyst = f.Get("{}_syst".format(histnames[1]));
_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
plot.AddSyst(data,syst);

grMC = f.Get("{}_MC".format(histnames[1]));
dataMC = plot.Add(1,grMC,**dataTypePlotParams[5],labelLegendId=1,label="PYTHIA 8 Tune 4C");



f.Close();

plot.GetPlot().text(0.16,0.826,"ALICE Preliminary",fontsize=12);
plot.GetPlot().text(0.16,0.78,toptitle,fontsize=11);
plot.GetPlot().text(0.16,0.14,dataDetail[0],fontsize=11);

plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5],
	xticklabels=[ "", "", "", "" ]);

plot.GetAxes(1).set(xticks=[0.5,1.5,2.5,3.5],
        xticklabels=[ "0$-$0.1%  ","1$-$5%   ","5$-$20%  ","20$-$60% " ]);

for tick in plot.GetAxes(0).get_xticklabels():
	tick.set_rotation(15)
for tick in plot.GetAxes(1).get_xticklabels():
        tick.set_rotation(15)


#plot.GetAxes(0).xticks(rotation=45)
plot.Plot();


plot.Save("figs/Fig5_Plot_v2Mult.pdf");
plot.Save("figs/Fig5_Plot_v2Mult.png");
plot.Show();

