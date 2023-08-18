
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
	{'plotType':'theory','facecolor':'k','edgecolor':'k','alpha':0.,'linestyle':'dotted','linecolor':'k'},
	{'plotType':'theory','facecolor':'b','edgecolor':'b','alpha':0.,'linestyle':'solid','linecolor':'b'},
	{'plotType':'theory','facecolor':'r','edgecolor':'r','alpha':0.,'linestyle':'dashed','linecolor':'r'},
	{'plotType':'theory','facecolor':'C3','edgecolor':'C3','alpha':0.5,'linestyle':'dashdot','linecolor':'C3'},
];


# define panel/xaxis limits/titles
nrow = 1;
ncol = 1;
xlimits = [(0,4)];
#ylimits = [(0.055,0.155)];
ylimits = [(0.03,0.135)];
rlimits = [(0.12,0.59)];


# add here the histogram names for each pad
histnames = ["NearJet","Acceptance"]; #_d means x2
histnameAway = ["AwayJet_d"];	      # w.o _d mean x1

# add labels for each pad
plables = [ "", ""
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];
# model names : for histonames in ROOT file
centrality =["ALICE Near side","PYTHIA 8 Tune 4C Near side",
	"ALICE Away side ($\\times$ 2), Template fit", "PYTHIA 8 Tune 4C Away side ($\\times$ 2)"];

#xtitle = ["$p_\\mathrm{T,trig(assoc)} (\\mathrm{GeV}/c)$"];
xtitle = ["V0M Event classes",""];
ytitle = ["$Y_\\mathrm{frag}$"," away/near$"];


# Following two must be added
toptitle = "ALICE pp $\\sqrt{s}$ = 13 TeV"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n$1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];
#dataDetail = ["","$1.6 < |\\Delta\\eta| < 1.8$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
#	ratioSystPlot=True,
	panelLabelLoc=(0.85,0.85),panelLabelSize=14,panelLabelAlign="left",
	legendPanel={0:0},
	axisLabelSize=13,legendLoc={0:(0.42,0.20)},legendSize=11,xlabel={0:xtitle[0]},ylabel={0:ytitle[0]},ylabelRatio="away/near",fontsize=1);


plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

#plot.GetAxes(0).set_xticks([0,1,2,3]);
plot.GetAxes(0).xaxis.set_ticks_position('both');
plot.GetAxes(0).yaxis.set_ticks_position('both');
gr_near = f.Get("{}_stat".format(histnames[0]));
data_near = plot.Add(0,gr_near,**dataTypePlotParams[0],labelLegendId=0,label=centrality[0]);
grsyst_near = f.Get("{}_syst".format(histnames[0]));
_,_,_,syst_near = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst_near));
plot.AddSyst(data_near,syst_near);

grMC_near = f.Get("{}_MC".format(histnames[0]));
dataMC_near = plot.Add(0,grMC_near,**dataTypePlotParams[3],labelLegendId=0,label=centrality[1]);

gr_away = f.Get("{}_stat".format(histnameAway[0]));
data_away = plot.Add(0,gr_away,**dataTypePlotParams[1],labelLegendId=0,label=centrality[2]);
grsyst_away = f.Get("{}_syst".format(histnameAway[0]));
_,_,_,syst_away = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst_away));
plot.AddSyst(data_away,syst_away);
grMC_away = f.Get("{}_MC".format(histnameAway[0]));
dataMC_away = plot.Add(0,grMC_away,**dataTypePlotParams[4],labelLegendId=0,label=centrality[3]);



#plot.GetAxes(1).set_xticks([0,1,2,3]);
#plot.GetAxes(1).xaxis.set_ticks_position('both');
#plot.GetAxes(1).yaxis.set_ticks_position('both');
gr = f.Get("{}_stat".format(histnames[1]));
data = plot.Add(0,gr,**dataTypePlotParams[1]);
grsyst = f.Get("{}_syst".format(histnames[1]));
x,y,yerr,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
plot.AddSyst(data,syst);

grMC = f.Get("{}_MC".format(histnames[1]));
dataMC = plot.Add(0,grMC,**dataTypePlotParams[4]);
y.fill(1)
yerr.fill(0)
print(x,y,yerr)
divplot = plot.Add(0,(x,y,yerr),**dataTypePlotParams[4]);

plot.Ratio(data, divplot);
plot.Ratio(dataMC,divplot,color='b',alpha=0.5);
#numpy array scale tgrapherrors 



f.Close();


plot.GetPlot().text(0.28,0.82,toptitle,fontsize=13);
plot.GetPlot().text(0.20,0.15,dataDetail[0],fontsize=11);
#plot.GetPlot().text(0.55,0.16,"$|\\Delta\\eta|<$1.3",fontsize=11);

#plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5],
#	xticklabels=[ "", "", "", "" ]);
plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5],
        xticklabels=[ "$~~$0$-$0.1%  ","$~~$1$-$5%   ","$~~$5$-$20%  ","$~$20$-$60% " ]);

for tick in plot.GetAxes(0).get_xticklabels():
	tick.set_rotation(15)


#plot.GetAxes(0).xticks(rotation=45)
plot.Plot();

plot.GetAxes(0).tick_params(axis='x',which='minor',bottom=False);
plot.GetRatioAxes(0).tick_params(axis='x',which='minor',bottom=False);


plot.Save("figures/FIG3_Plot_v2Mult.pdf");
plot.Save("figures/FIG3_Plot_v2Mult.png");
plot.Show();

