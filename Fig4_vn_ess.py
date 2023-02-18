
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");
#https://github.com/jaelpark/JPyPlotRatio


import JPyPlotRatio


f = ROOT.TFile("data/Final_Items.root","read"); #root file for 1-4 GeV/c pt
dataTypePlotParams = [
	{'plotType':'data','color':'k','fmt':'o','markersize':5.0},
	{'plotType':'data','color':'r','fmt':'s','fillstyle':'none','markersize':5.0},
	{'plotType':'theory','facecolor':'C0','edgecolor':'C0','alpha':0.5,'linestyle':'solid','linecolor':'C0'},
	{'plotType':'theory','facecolor':'C1','edgecolor':'C1','alpha':0.5,'linestyle':'dotted','linecolor':'C1'},
	{'plotType':'theory','facecolor':'C2','edgecolor':'C2','alpha':0.5,'linestyle':'dashed','linecolor':'C2'},
	{'plotType':'theory','facecolor':'C3','edgecolor':'C3','alpha':0.5,'linestyle':'dashdot','linecolor':'C3'},
];


# define panel/xaxis limits/titles
nrow = 2;
ncol = 2;
xlimits = [
	[(-0.1,7.1),(-0.1,5.1)],
	[(-0.1,4.1),(-0.1,5.1)] ];
ylimits = [(0.04,0.15),(0.0,0.12)];
rlimits = [(0.,4.5),(0.,4.5)];

# add here the histogram names for each pad
histnames = [ # 1-4 GeV hist
	["v2_LP",	"v2_jet"],
	["v3_LP",  "v3_jet"], ];

histnames12 = [ #1-2 GeV 
	["v2_lp",	"v2_jet"],
	["v3_lp",  "v3_jet"], ];
histnamesSyst = [
	["v2_0_ALICE_syst",  "v2_1_ALICE_syst"],
	["v3_0_ALICE_syst",  "v3_1_ALICE_syst"], ];
histnamesModels = [
	["v2_0_EPOS",  "v2_1_EPOS"],
	["v3_0_EPOS",  "v3_1_EPOS"], ];

# add labels for each pad
plables = [ "Leading Particle $|\\eta|<0.9$","Jet, anti-$k_\\mathrm{T}$ $R=0.4$ $|\\eta|<0.4$" ,"",""];
# model names : for histonames in ROOT file
modelStr = ["EPOS LHC"]; # "PYTHIA8 Monash2013"];#for legend
#modelStr = ["PYTHIA8 String Shoving $g$ = 3","EPOS LHC"];
xtitle = ["$p^{\\mathrm{LP}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$","$p^{\\mathrm{Jet}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$"];
ytitle = ["$V_{2}$", "$V_{3}$"];

# Following two must be added
toptitle = ["pp $\\sqrt{s}$ = 13 TeV","0--0.1$\%$"]; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T} < 4\\,\\mathrm{GeV}/c$","$1.6 < |\\Delta\\eta| < 1.8$"];
dataDetail12 = ["$1 < p_\\mathrm{T} < 2\\,\\mathrm{GeV}/c$"];
PanelName = ["LP", "Jet"];

plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits[0],  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0,1],
	panelLabelLoc=(0.07,0.14),panelLabelSize=9,panelLabelAlign="left",
	legendPanel=2,
	legendLoc=(0.40,0.6),legendSize=9,xlabel={0:xtitle[0],1:xtitle[1]},
	ylabel={0:ytitle[0],1:ytitle[1]});
plot.EnableLatex(True); # for publication need fonts via texlive

for iobs in range(0,2):
	for j in range(0,ncol):
		index = iobs*ncol+j;
		plot.GetAxes(index).xaxis.set_ticks_position('both');
		plot.GetAxes(index).yaxis.set_ticks_position('both');
		gr = f.Get("h{}_1_4_stat".format(histnames[iobs][j])); # 1-4 GeV
		gr12 = f.Get("{}_stat".format(histnames12[iobs][j])); # 1-2 GeV without mom. range in the hist name
		#gr.Print();

		grsyst = f.Get("h{}_1_4_syst".format(histnames[iobs][j])); # 1-4 GeV
		_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
		print("1-4",syst);
		grsyst12 = f.Get("{}_syst".format(histnames12[iobs][j])); # 1-2 GeV without mom. range in the hist name
		print(grsyst);
		_,_,_,syst12 = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst12));
		print("1-2",syst12);
		if index == 2:
			#remove pT_LP > 7 points
			x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(gr));
			x,y,yerr = x[:4],y[:4],yerr[:4];
			syst = syst[:4];
			gr = (x,y,yerr);

			x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(gr12));
			x,y,yerr = x[:4],y[:4],yerr[:4];
			syst12 = syst12[:4];
			gr12 = (x,y,yerr);

		data = plot.Add(index,gr,**dataTypePlotParams[0],label=dataDetail[0]);
		data12 = plot.Add(index,gr12,**dataTypePlotParams[1],label=dataDetail12[0]);
		plot.AddSyst(data,syst);
		plot.AddSyst(data12,syst12);
#			if( iobs==0 ):
#				grModel = f.Get("{}".format(histnamesModels[iobs][j]));
#				data = plot.Add(index,grModel,**dataTypePlotParams[3],label=modelStr[0]);

#			for k in range(0,len(modelStr)):
#				grModel = f.Get("{}".format(histnamesModels[k][j]));
#				model = plot.Add(index,grModel,**dataTypePlotParams[1+k],label=modelStr[k]);
#				if(k>0):
#				plot.Ratio(model,data,dataTypePlotParams[k+1]);
#				plot.Ratio(model,data,style="errorbar"); #Calculate and plot ratio between data and theory
#					plot.Ratio(model,data );


#'''
plot.GetPlot().text(0.15,0.82,toptitle[0],fontsize=12);
plot.GetPlot().text(0.17,0.77,toptitle[1],fontsize=12);
#plot.GetPlot().text(0.16,0.78,dataDetail[0],fontsize=11);
plot.GetPlot().text(0.18,0.39,dataDetail[1],fontsize=11);
plot.GetPlot().text(0.44,0.80,PanelName[0],fontsize=12);
plot.GetPlot().text(0.80,0.80,PanelName[1],fontsize=12);
plot.GetPlot().text(0.44,0.40,PanelName[0],fontsize=12);
plot.GetPlot().text(0.80,0.40,PanelName[1],fontsize=12);
plot.GetPlot().text(0.18,0.43,"ALICE",fontsize=11);

# this is need because of the input histo label setting..
#if( iobs==0 ):
#	plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5,6.5], xticklabels=["Unbiased","3","5","7","9","13","20"]);
#if( iobs==1 ):
#	plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5], xticklabels=["Unbiased","3","5","7"]);
plot.GetAxes(2).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5,6.5], xticklabels=["All $p_\\mathrm{T}$","3","5","7","9","13","20"]);
#	plot.GetAxes(1).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5,6.5], xticklabels=["Unbiased","10","20","30","40","50","60"]);
plot.GetAxes(3).set(xticks=[0.5,1.5,2.5,3.5,4.5], xticklabels=["All $p_\\mathrm{T}$","10","20","30","40"]);
cntforaxis=0;
for tick in plot.GetAxes(2).get_xticklabels():
	if( cntforaxis==0 ):
		tick.set(fontsize=8);
		tick.set_rotation(-17)
		cntforaxis += 1;
cntforaxis=0;
for tick in plot.GetAxes(3).get_xticklabels():
	if( cntforaxis==0 ):
		tick.set(fontsize=8);
		tick.set_rotation(-17)
		cntforaxis += 1;
#'''

plot.Plot();
	
plot.Save("figs/Fig4_vn_LP.pdf");
plot.Save("figs/Fig4_vn_LP.png");

plot.Show();

