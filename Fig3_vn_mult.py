
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
	{'plotType':'theory','facecolor':'C0','edgecolor':'C0','alpha':0.5,'linestyle':'dotted','linecolor':'C0'},
	{'plotType':'theory','facecolor':'C1','edgecolor':'C1','alpha':0.5,'linestyle':'solid','linecolor':'C1'},
	{'plotType':'theory','facecolor':'C2','edgecolor':'C2','alpha':0.5,'linestyle':'dashed','linecolor':'C2'},
	{'plotType':'theory','facecolor':'C3','edgecolor':'C3','alpha':0.5,'linestyle':'dashdot','linecolor':'C3'},
];


# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(0,4),(0,3)];
ylimits = [(-0.005,0.1)];
rlimits = [(0.,4.5),(0.,4.5)];


# add here the histogram names for each pad
histnames = ["v2_mult","v3_mult"];
# add labels for each pad
plables = [ "$V_{2}$", "$V_{3}$"
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];
# model names : for histonames in ROOT file
centrality =["ALICE, $1.6 < |\\Delta\\eta| < 1.8$"];

#xtitle = ["$p_\\mathrm{T,trig(assoc)} (\\mathrm{GeV}/c)$"];
xtitle = ["",""];
ytitle = ["$v_{n}$"];


# Following two must be added
toptitle = "pp $\\sqrt{s}$ = 13 TeV"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];
#dataDetail = ["","$1.6 < |\\Delta\\eta| < 1.8$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel=0,
	legendLoc=(0.38,0.38),legendSize=10,xlabel={0:xtitle[0],1:xtitle[1]},ylabel=ytitle[0]);



plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

for i in range(0,nrow):
	for j in range(0,ncol):
		index = i*ncol+j; # for each panel 
		plot.GetAxes(index).set_xticks([0,1,2,3]);
		if (j==1):
			plot.GetAxes(index).set_xticks([0,1,2]);
		plot.GetAxes(index).xaxis.set_ticks_position('both');
		plot.GetAxes(index).yaxis.set_ticks_position('both');
		gr = f.Get("{}_stat".format(histnames[index]));
		gr.Print();
		data = plot.Add(index,gr,**dataTypePlotParams[0],label=centrality[0]);
		grsyst = f.Get("{}_syst".format(histnames[index]));
		_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
		plot.AddSyst(data,syst);



f.Close();

plot.GetPlot().text(0.55,0.77,"ALICE Preliminary",fontsize=12);
plot.GetPlot().text(0.54,0.62,toptitle,fontsize=11);
plot.GetPlot().text(0.17,0.24,dataDetail[0],fontsize=11);

plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5],
	xticklabels=[ "0$-$0.1%  ","1$-$5%   ","5$-$20%  ","20$-$60% "]);

plot.GetAxes(1).set(xticks=[0.5,1.5,2.5],
        xticklabels=[ "0$-$0.1%  ","1$-$5%   ","5$-$20%  " ]);

for tick in plot.GetAxes(0).get_xticklabels():
	tick.set_rotation(15)
for tick in plot.GetAxes(1).get_xticklabels():
        tick.set_rotation(15)


#plot.GetAxes(0).xticks(rotation=45)
plot.Plot();


plot.Save("figs/Fig3_Plot_v2Mult.pdf");
plot.Save("figs/Fig3_Plot_v2Mult.png");
plot.Show();

