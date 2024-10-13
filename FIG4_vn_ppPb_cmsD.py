
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");
#https://github.com/jaelpark/JPyPlotRatio


import JPyPlotRatio


f = ROOT.TFile("data/fout_vn_28jun2023.root","read");
fpPb = ROOT.TFile("data/fout_vn_28jun2023.root","read");
fCMSD = ROOT.TFile("CMSDmesons/CMS_Dmesons_pppPb_HEPData-ins1817310-v1-root.root","read");
fCMSDpPb = ROOT.TFile("CMSDmesons/CMS_D0_pPb816_HEPData-ins1670168-v1-root.root","read");
# table 1(prompt D) and 8(nonPrompt D) in the paper
gr_promptD_CMS = fCMSD.Get("Table 1/Hist1D_y1"); # pp 13
gr_nonPromptD_CMS = fCMSD.Get("Table 8/Hist1D_y1"); # pPb 8.16
gr_promptD_pPbCMS2 = fCMSDpPb.Get("Table 5/Graph"); # pPb 8.16
gr_k0_pPbCMS2 = fCMSDpPb.Get("Table 1/Graph"); # pPb 8.16
dataTypePlotParams = [
	    {'plotType':'data','color':'#0051a2','fmt':'d','fillstyle':'none','markersize':6.0},
        {'plotType':'data','color':'blue','fmt':'D','fillstyle':'none','markersize':5.5},
        {'plotType':'data','color':'#660080','fmt':'*','fillstyle':'none','markersize':6.0},
        {'plotType':'data','color':'#9955ff','fmt':'d','markersize':6.0},
        {'plotType':'data','color':'m','fmt':'X','fillstyle':'none','markersize':5.5},
        {'plotType':'data','color':'seagreen','fmt':'h','markersize':5.5},
        {'plotType':'data','color':'red','fmt':'H','fillstyle':'none','markersize':5.5}
];

#adding pPb?
addpPb = True;
# define panel/xaxis limits/titles
nrow = 1;
ncol = 1;
xlimits = [(-0.1,8.1),(0.8,3.8)];
ylimits = [(-0.09,0.35)];
rlimits = [(0.3,1.9),(0.,4.5)];


# add here the histogram names for each pad
histnames =      ["v2_pt_stat","v3_pt_stat"]; #LP,jet  # check it with ROOT file Title
histnamesSyst =  ["v2_pt_syst","v3_pt_syst"]; #LP,jet  # check it with ROOT file Title	
histnamesModels = [ "v2_EPOS","v3_EPOS" ];	

histatlas_stat = ["v2_atlas_stat","v3_atlas_stat"];
histatlas_syst = ["v2_atlas_syst","v3_atlas_syst"];

histpPb_stat = ["v2_v0a_stat_pt","v3_v0a_stat_pt"];
histpPb_syst = ["v2_v0a_syst_pt","v3_v0a_syst_pt"];
# add labels for each pad
#plables = [ "Leading Particle $|\\eta|<0.9$","Jet, anti-$k_\mathrm{T}$ $R=0.4$ $|\\eta|<0.4$" ];
plables = [ "$n = 2$", "$n = 3$" ];
# model names : for histonames in ROOT file
modelStr = ["EPOS LHC"]; # "PYTHIA8 Monash2013"];#for legend
#modelStr = ["PYTHIA8 String Shoving $g$ = 3","EPOS LHC"];
#xtitle = ["$p^{\\mathrm{LP}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$","$p^{\\mathrm{Jet}}_\\mathrm{T,min}\\,(\\mathrm{GeV}/c)$"];
#xtitle = ["$p_\\mathrm{T,trig(assoc)}\\,(\\mathrm{GeV}/c)$","$p_\\mathrm{T,trig(assoc)}\\,(\\mathrm{GeV}/c)$"];
xtitle = ["$p_\\mathrm{T}\\,(\\mathrm{GeV}/c)$","$p_\\mathrm{T,trig}\\,(\\mathrm{GeV}/c)$"];
ytitle = ["$v_{2}$"];

# Following two must be added
toptitle = "pp $\\sqrt{s}$ = 13 TeV \n $0--0.1\%$"; # need to add on the top
dataDetail = ["$1.6<|\\Delta\\eta|<1.8$ \n 1 $ < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c $"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(8,6),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	#panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
#	ratioSystPlot=True,
	systPatchWidth = 0.015,
	disableRatio=[0],
	panelLabelLoc=(0.71,0.81),panelLabelSize=13,panelLabelAlign="left",
	axisLabelSize=13,tickLabelSize=13,
	legendPanel={0:0,1:0,2:0},
	legendLoc={0:(0.25,0.78),1:(0.75,0.74),2:(0.60,0.14)},
	legendSize=12,xlabel={0:xtitle[0],1:xtitle[1]},ylabel=ytitle[0]);

#plot.EnableLatex(True); # for publication need fonts via texlive

plotMatrix = np.empty((nrow,ncol),dtype=int);

#plot.GetAxes(0).set_xticks([1.5,2.5,3.5]);


for i in range(0,nrow):
	for j in range(0,ncol):
		index = i*ncol+j; # for each panel 
		#plot.GetAxes(index).set_xticks([1.5,2.5,3.5]);
		plot.GetAxes(index).xaxis.set_ticks_position('both');
		plot.GetAxes(index).yaxis.set_ticks_position('both');
		gr = f.Get("{}".format(histnames[j]));
		datapp = plot.Add(index,gr,**dataTypePlotParams[0],label="pp $\\sqrt{s} = 13$ TeV",labelLegendId=0);
		    #, $1.6<|\\Delta\\eta|<1.8$ \n 1 $ < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c $"
		grsyst = f.Get("{}".format(histnamesSyst[j]));
		_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
		plot.AddSyst(datapp,syst);
		#Loading ATLAS
		grATLAS = f.Get("{}".format(histatlas_stat[j]));
		#data = plot.Add(index,grATLAS,**dataTypePlotParams[1],label="ATLAS, $2.0<|\\Delta\\eta|<5.0$ \n 0.5 $ < p_\\mathrm{T,assoc} < 5 \\,\\mathrm{GeV}/c $");
		#grsystATLAS = f.Get("{}".format(histatlas_syst[j]));
		#_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsystATLAS));
		#plot.AddSyst(data,syst);
		#End of ATLAS
		#Loading pPb
		if(addpPb):
			grpPb = fpPb.Get("{}".format(histpPb_stat[j]));
			grpPb.Print();
			dataPb = plot.Add(index,grpPb,**dataTypePlotParams[2],label="pPb $\\sqrt{s_{\\rm NN}} = 5.02$ TeV",labelLegendId=0);
			grsystpPb = fpPb.Get("{}".format(histpPb_syst[j]));
			_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsystpPb));
			plot.AddSyst(dataPb,syst);
			plot.Ratio(dataPb,datapp);
		#End of pPb
		#gr = f.Get("{}".format(histnames[j]));
		#gr.Print();
		#data = plot.Add(index,gr,**dataTypePlotParams[0],label="ALICE, $1.6<|\\Delta\\eta|<1.8$ \n 1 $ < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c $");
		#grsyst = f.Get("{}".format(histnamesSyst[j]));
		#_,_,_,syst = JPyPlotRatio.TGraphErrorsToNumpy(ROOT.TGraphErrors(grsyst));
		#plot.AddSyst(data,syst);
# add CMS
data_promptD_CMS = plot.Add(0,gr_promptD_CMS,**dataTypePlotParams[3],label="Prompt $D^{0}$ pp $\\sqrt{s} = 13$ TeV",labelLegendId=1);
data_NonpromptD_CMS = plot.Add(0,gr_nonPromptD_CMS,**dataTypePlotParams[4],label="Non-Prompt $D^{0}$, pPb 8.16 TeV",labelLegendId=1);
data_promptD_CMS1 = plot.Add(0,gr_promptD_pPbCMS2,**dataTypePlotParams[5],label="Prompt $D^{0}$, pPb 8.16 TeV",labelLegendId=1);
data_k0_CMS1 = plot.Add(0,gr_k0_pPbCMS2,**dataTypePlotParams[6],label="$K^{0}_{Ss}$, pPb 8.16 TeV",labelLegendId=1);
f.Close();

plot.GetPlot().text(0.15,0.80,"ALICE",fontsize=13);
plot.GetPlot().text(0.53,0.81,"CMS",fontsize=13);
#plot.GetPlot().text(0.15,0.77,"ALICE",fontsize=12);
#plot.GetPlot().text(0.54,0.65,dataDetail[0],fontsize=13);
#plot.GetPlot().text(0.16,0.17,dataDetail[1],fontsize=10);

# this is need because of the input histo label setting..
#plot.GetAxes(0).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5,6.5], xticklabels=["0","3","5","7","9","13","20"]);
#plot.GetAxes(1).set(xticks=[0.5,1.5,2.5,3.5,4.5,5.5], xticklabels=["0","10","20","30","40","50"]);
plot.Plot();
if(addpPb):
	plot.Save("figures/FIG4_vn_pppPb_wDmeson.pdf");
	#plot.Save("figs/FIG4_vn_pppPb_wDmeson.png");
else:
    plot.Save("figures/FIG4_vn_wDmeson.pdf")
    #lot.Save("figures/FIG4_vn_wDmeson.png");

plot.Show();

