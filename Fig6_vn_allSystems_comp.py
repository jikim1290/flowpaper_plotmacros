
import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");


import JPyPlotRatio

data = {
	"vn_pp":ROOT.TFile("data/Final_Items.root","read"),
#	"vn_pPb_zna":ROOT.TFile("data/Final_Items.root","read"),
	"vn_pPb_v0a":ROOT.TFile("data/Final_Items.root","read"),
#	"vn_pp_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_pp.root","read"),
#	"vn_pPb_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_pPb.root","read"),
	#"vn_PbPb_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_PbPb.root","read"),
    	"vn_pp_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read"),
	"vn_pPb_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read")
}

plotParams = {
	"vn_pp":{"color":"k","fmt":"o","markersize":5.0,"label":"2PC: pp $\\sqrt{s}$ = 13 TeV","labelLegendId":0},
#	"vn_pPb_zna":{"color":"b","fmt":"s","mfc":"none","markersize":5.0,"label":"2PC: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, ZNA","labelLegendId":0},
#	"vn_pPb_v0a":{"color":"b","fmt":"s","mfc":"none","markersize":5.0,"label":"2PC: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, V0A","labelLegendId":0},
	"vn_pPb_v0a":{"color":"r","fmt":"*","mfc":"none","markersize":5.0,"label":"2PC: p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, V0A","labelLegendId":0},
#	"vn_pPb_pub":{"color":"orange","fmt":"p","mfc":"none","markersize":5.0,"label":"$V_{2}\\{2,|\Delta\eta|<1.4\\}$: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":1},
	#"vn_PbPb_pub":{"color":"brown","fmt":"D","mfc":"none","markersize":5.0,"label":"$V_{2}\\{2\\}$: Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":1},
	"vn_pp_atl":{"color":"green","fmt":"o","markersize":5.0,"label":"ATLAS: pp $\\sqrt{s}$ = 13 TeV","labelLegendId":2},
	"vn_pPb_atl":{"color":"purple","fmt":"s","mfc":"none","markersize":5.0,"label":"ATLAS: p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":2}
}	

#histNames = ["pp","pPb_v2_zna","pPb_v2_v0a"];
histNames = ["pp","pPb_v2_v0a"];
#histNamesPub = ["ppHM","pPb","PbPb"];
histNamesAtlas = ["pp13","pPb"];
NremoveAtlas =[3,5]

# define panel/xaxis limits/titles
nrow = 1;
ncol = 1;
xlimits = [(0,100),(0,100)];
ylimits = [(-0.005,0.13)];
rlimits = [(0.,4.5),(0.,4.5)];




# add labels for each pad
plables = [ "", ""
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];

xtitle = ["$N_\\mathrm{ch} (|\eta|<0.5)$",""];
ytitle = ["$V_{2}$","$V_{2}\\{4\\}$"];
#labelList = ["pp $\\sqrt{s}$ = 13 TeV our","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV our","pp $\\sqrt{s}$ = 13 TeV","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV"]


# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds=ylimits,  # for nrow
	#colBounds=xlimits,  # for ncol
	panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	legendPanel={0:0,1:0,2:0},
	#legendPanel={0:0},
	legendLoc={0:(0.30,0.15),1:(0.72,0.45),2:(0.75,0.12)},
	#legendLoc={0:(0.60,0.15)},
	legendSize=7,xlabel=xtitle[0],ylabel=ytitle[0]);

#plot.EnableLatex(True);

plotMatrix = np.empty((nrow,ncol),dtype=int);

#plot.GetAxes(0).set_xticks([0,15, 30, 45,60]);
#plot.GetAxes(1).set_xticks([0,15, 30, 45,60]);
plot.GetAxes(0).xaxis.set_ticks_position('both');
plot.GetAxes(0).yaxis.set_ticks_position('both');

plots = {};

nmeas=2;
for i,s in enumerate(data):
	print(s)

	if i<nmeas:
		gr = data[s].Get("{}_stat".format(histNames[i]));
		grsyst = data[s].Get("{}_syst".format(histNames[i]));
		#plots[s] = plot.Add(0,gr,**plotParams[s],label=labelList[i]);
		#plot.AddSyst(plots[s],grsyst);

#	if i >=2 and i < 4:
#		gr = data[s].Get("gv22Gap14Stat{}".format(histNamesPub[i-2]));
#		grsyst = data[s].Get("gv22Gap14Sys{}".format(histNamesPub[i-2]));

	if i >= nmeas:
		gr = data[s].Get("grAtlas_{}_stat".format(histNamesAtlas[i-nmeas]));
		grsyst = data[s].Get("grAtlas_{}_syst".format(histNamesAtlas[i-nmeas]));
	
	
	plots[s] = plot.Add(0,gr,**plotParams[s]);
	plot.AddSyst(plots[s],grsyst);

'''
	gr24 = data[s].Get("gv24_3subStat{}".format(histNames[i]));
	grsyst24 = data[s].Get("gv24_3subSys{}".format(histNames[i]));
	plots[s] = plot.Add(1,gr24,**plotParams[s]);
	plot.AddSyst(plots[s],grsyst24);
'''



plot.GetPlot().text(0.21,0.34,"$1 < p_\\mathrm{T} < 2 \\,\\mathrm{GeV}/c$",fontsize=8);
plot.GetPlot().text(0.21,0.38,"$1.6<|\Delta\eta|<1.8$",fontsize=8);
#plot.GetPlot().text(0.55,0.53,"$0.2 < p_\\mathrm{T} < 3.0 \\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.55,0.65,"$|\Delta\eta|<1.4$",fontsize=8);
plot.GetPlot().text(0.5,0.36,"$2.0<|\Delta\eta|<5.0$",fontsize=8);
plot.GetPlot().text(0.5,0.32,"$1.0 < p_\\mathrm{T} < 5 \\,\\mathrm{GeV}/c$",fontsize=8);
plot.GetPlot().text(0.5,0.28,"$N_{ch}^* = |\eta|<2.5$ and $p_\\mathrm{T}>0.4\\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.19,0.14,dataDetail[0],fontsize=11);


plot.Plot();

plot.Save("figs/Fig6_v2Mult_allSystemsComp.pdf");
#plot.Save("figs/Fig6_v2Mult_ourresult.pdf");
plot.Save("figs/Fig6_v2Mult_allSystemsComp.png");
#plot.Save("figs/Fig6_v2Mult_ourresult.png");
plot.Show();

