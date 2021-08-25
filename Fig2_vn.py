
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");
#https://github.com/jaelpark/JPyPlotRatio


import JPyPlotRatio


f = ROOT.TFile("data/Final_Items.root","read");
dataTypePlotParams = [
	{'plotType':'data','color':'k','fmt':'o','markersize':5.0},
	{'plotType':'data','color':'b','fmt':'d','markersize':5.0},
	{'plotType':'theory','facecolor':'C0','edgecolor':'C0','alpha':0.5,'linestyle':'solid','linecolor':'C0'},
	{'plotType':'theory','facecolor':'C1','edgecolor':'C1','alpha':0.5,'linestyle':'dotted','linecolor':'C1'},
	{'plotType':'theory','facecolor':'C2','edgecolor':'C2','alpha':0.5,'linestyle':'dashed','linecolor':'C2'},
	{'plotType':'theory','facecolor':'C3','edgecolor':'C3','alpha':0.5,'linestyle':'dashdot','linecolor':'C3'},
];


# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(1.0,4.5),(1.0,4.5)];
ylimits = [(-0.03,0.145)];
rlimits = [(0.,4.5),(0.,4.5)];


# add here the histogram names for each pad
histnames =      ["v2_pt_stat","v3_pt_stat"]; #LP,jet  # check it with ROOT file Title
histnamesSyst =  ["v2_pt_syst","v3_pt_syst"]; #LP,jet  # check it with ROOT file Title	
histnamesModels = [ "v2_EPOS","v3_EPOS" ];	

histatlas =	 ["v2_ATLAS_pp"];
histatlas_v3_stat =      ["v3_altas_stat"];
histatlas_v3_syst =      ["v3_altas_syst"];


# add labels for each pad
#plables = [ "Leading Particle $|\\eta|<0.9$","Jet, anti-$k_\mathrm{T}$ $R=0.4$ $|\\eta|<0.4$" ];
plables = [ "$V_{2}$", "$V_{3}$" ];
# model names : for histonames in ROOT file
modelStr = ["EPOS LHC"]; # "PYTHIA8 Monash2013"];#for legend
#modelStr = ["PYTHIA8 String Shoving $g$ = 3","EPOS LHC"];
#xtitle = ["$p^{\\mathrm{LP}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$","$p^{\\mathrm{Jet}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$"];
#xtitle = ["$p_\\mathrm{T,trig(assoc)}\\,(\\mathrm{GeV}/c)$","$p_\\mathrm{T,trig(assoc)}\\,(\\mathrm{GeV}/c)$"];
xtitle = ["$p_\\mathrm{T,trig}\\,(\\mathrm{GeV}/c)$","$p_\\mathrm{T,trig}\\,(\\mathrm{GeV}/c)$"];
ytitle = ["$V_{n}$"];

# Following two must be added
toptitle = "pp $\\sqrt{s}$ = 13 TeV \n 0--0.1\%"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig(assoc)} < 2\\,\\mathrm{GeV}/c$","$1.6 < |\\Delta\\eta| < 1.8$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
#	ratioSystPlot=True,
	disableRatio=[0],
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel=0,
	legendLoc=(0.46,0.27),legendSize=11,xlabel={0:xtitle[0],1:xtitle[1]},ylabel=ytitle[0]);


plot.EnableLatex(True); # for publication need fonts via texlive

plotMatrix = np.empty((nrow,ncol),dtype=int);

#plot.GetAxes(0).set_xticks([1.5,2.5,3.5]);


for i in range(0,nrow):
	for j in range(0,ncol):
		index = i*ncol+j; # for each panel 
		plot.GetAxes(index).set_xticks([1.5,2.5,3.5]);
		plot.GetAxes(index).xaxis.set_ticks_position('both');
		plot.GetAxes(index).yaxis.set_ticks_position('both');
		gr = f.Get("{}".format(histnames[j]));
		gr.Print();
		data = plot.Add(index,gr,**dataTypePlotParams[0],label="ALICE, $1.6<|\\Delta\\eta|<1.8$ \n 1 $ < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c $");
		grsyst = f.Get("{}".format(histnamesSyst[j]));
		_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
		plot.AddSyst(data,syst);
		if(j==0):
#			grModel = f.Get("{}".format(histnamesModels[j]));
#			model = plot.Add(index,grModel,**dataTypePlotParams[4],label=modelStr[0]);
			grATLAS = f.Get("{}".format(histatlas[j]));
			grATLAS.Print();
			data = plot.Add(index,grATLAS,**dataTypePlotParams[1],label="ATLAS, $2.0<|\\Delta\\eta|<5.0$ \n 0.5 $ < p_\\mathrm{T,assoc} < 5 \\,\\mathrm{GeV}/c $");
		if(j==1):
			grATLAS = f.Get("{}".format(histatlas_v3_stat[0]));
			data = plot.Add(index,grATLAS,**dataTypePlotParams[1],label="ATLAS, $2.0<|\\Delta\\eta|<5.0$ \n 0.5 $ < p_\\mathrm{T,assoc} < 5 \\,\\mathrm{GeV}/c $");
			grsystATLAS = f.Get("{}".format(histatlas_v3_syst[0]));
			_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsystATLAS));
			plot.AddSyst(data,syst);
#		for k in range(0,len(modelStr)):
#			grModel = f.Get("{}".format(histnamesModels[k][j]));
#			model = plot.Add(index,grModel,**dataTypePlotParams[1+k],label=modelStr[k]);
#			if(k>0):
#				plot.Ratio(model,data,dataTypePlotParams[k+1]);
#				plot.Ratio(model,data,style="errorbar"); #Calculate and plot ratio between data and theory
#				plot.Ratio(model,data );

f.Close();

plot.GetPlot().text(0.15,0.77,"ALICE Work in progress",fontsize=12);
plot.GetPlot().text(0.54,0.62,toptitle,fontsize=11);
#plot.GetPlot().text(0.16,0.27,dataDetail[0],fontsize=10);
#plot.GetPlot().text(0.16,0.17,dataDetail[1],fontsize=10);

# this is need because of the input histo label setting..
#plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5,6.5], xticklabels=["0","3","5","7","9","13","20"]);
#plot.GetAxes(1).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5], xticklabels=["0","10","20","30","40","50"]);
plot.Plot();

plot.Save("figs/Fig2_vn.pdf");
plot.Save("figs/Fig2_vn.png");
plot.Show();
