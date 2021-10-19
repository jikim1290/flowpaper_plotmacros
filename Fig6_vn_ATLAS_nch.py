import numpy as np
import ROOT

import scipy
from scipy import interpolate

import sys
sys.path.append("JPyPlotRatio");


import JPyPlotRatio



data = {
	"vn_pp":ROOT.TFile("data/Final_Items.root","read"),
	"vn_pPb":ROOT.TFile("data/Final_Items.root","read"),
    	"vn_pp_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read"),
	"vn_pPb_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read")
}

plotParams = {
	"vn_pp":{"color":"k","fmt":"o","markersize":5.0,"label":"2PC: pp $\\sqrt{s}$ = 13 TeV","labelLegendId":0},
	"vn_pPb":{"color":"b","fmt":"s","mfc":"none","markersize":5.0,"label":"2PC: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":0},
	"vn_pp_atl":{"color":"green","fmt":"o","markersize":5.0,"label":"ATLAS: pp $\\sqrt{s}$ = 13 TeV","labelLegendId":2},
	"vn_pPb_atl":{"color":"purple","fmt":"s","mfc":"none","markersize":5.0,"label":"ATLAS: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":2}
}	



histNames = ["pp","pPb"];
histNamesAtlas = ["pp13","pPb"];
NremoveAtlas =[2,4]

# define panel/xaxis limits/titles
nrow = 1;
ncol = 1;
xlimits = [(0,100),(0,100)];
ylimits = [(-0.005,0.13)];
rlimits = [(0.,4.5),(0.,4.5)];

#Alice to atlas conversion on multiplicity = N_{ch}
NchAtlaspp_pythiaOnly = [80.33, 48.83, 29.15, 14.12];
NchAtlaspp_data =  [84.07, 50.10, 33.70, 16.11]; #From Beomkyu
NchAtlaspPb_data = [85.35, 83.27, 67.26, 49.93, 33.54]; #From Beomkyu



# add labels for each pad
plables = [ "", ""
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];

xtitle = ["$N_\\mathrm{ch}^{ ATLAS def.} |\eta|<2.5, p_\\mathrm{T}>0.4$",""];
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

for i,s in enumerate(data):
	print(s)
	if i<2:
            gr = data[s].Get("{}_stat".format(histNames[i]));
            grsyst = data[s].Get("{}_syst".format(histNames[i]));
            x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr);
            if i==0:
                x = np.array(NchAtlaspp_data);
                print(x);
            if i==1:
                print(x);
                #x = np.array(NchAtlaspPb_data);
                print(x);
        
	if i >= 2:
	    gr = data[s].Get("grAtlas_{}_stat".format(histNamesAtlas[i-4]));
	    grsyst = data[s].Get("grAtlas_{}_syst".format(histNamesAtlas[i-4]));
	    x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr);
	
	plots[s] = plot.Add(0,(x,y,yerr),**plotParams[s]);
	plot.AddSyst(plots[s],grsyst);

'''
	gr24 = data[s].Get("gv24_3subStat{}".format(histNames[i]));
	grsyst24 = data[s].Get("gv24_3subSys{}".format(histNames[i]));
	plots[s] = plot.Add(1,gr24,**plotParams[s]);
	plot.AddSyst(plots[s],grsyst24);
'''



plot.GetPlot().text(0.21,0.3,"$1 < p_\\mathrm{T} < 2.0 \\,\\mathrm{GeV}/c$",fontsize=8);
plot.GetPlot().text(0.21,0.34,"$1.6<|\Delta\eta|<1.8$",fontsize=8);
plot.GetPlot().text(0.55,0.36,"$2.0<|\Delta\eta|<5.0$",fontsize=8);
plot.GetPlot().text(0.55,0.32,"$1.0 < p_\\mathrm{T} < 5 \\,\\mathrm{GeV}/c$",fontsize=8);


plot.Plot();

plot.Save("figs/Fig6_v2Mult_allSystemsComp.pdf");
#plot.Save("figs/Fig6_v2Mult_ourresult.pdf");
plot.Save("figs/Fig6_v2Mult_allSystemsComp.png");
#plot.Save("figs/Fig6_v2Mult_ourresult.png");
plot.Show();



