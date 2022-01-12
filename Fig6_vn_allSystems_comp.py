
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
	#"vn_pp":ROOT.TFile("data/Final_Items.root","read"), # pp 1<pT<2 GeV
	"vn_pp_14":ROOT.TFile("data/Final_Items.root","read"), # pp 1<pT<4 GeV
#	"vn_pPb_zna":ROOT.TFile("data/Final_Items.root","read"),
#	"vn_pPb_v0a":ROOT.TFile("data/Final_Items.root","read"),
#	"vn_pPb_v0a":ROOT.TFile("data/fout_v2_pPb_v1.root","read"),  # pPb 1<pT<2 GeV
	"vn_pPb_v0a_14":ROOT.TFile("data/fout_v2_pPb_v1.root","read"),  # pPb 1<pT<4 GeV
	#"vn_hydro_pPb":ROOT.TFile("data/results_dual_MAP_502_pPb.root","read")
#	"vn_pp_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_pp.root","read"),
#	"vn_pPb_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_pPb.root","read"),
	#"vn_PbPb_pub":ROOT.TFile("../flow_in_small_and_large_systems/Data/output_vn_PbPb.root","read"),
    #"vn_pp_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read"), # ATLAS pp 1<pT<5 GeV
	#"vn_pPb_atl":ROOT.TFile("ATLAS-figs/output-figure18a.root","read") # ATLAS pPb 1<pT<5 GeV
}

plotParams = {
	#"vn_pp":{"color":"k","fmt":"o","markersize":5.0,"label":"pp 13 TeV, $1 < p_\\mathrm{T} < 2.0 \\,\\mathrm{GeV}/c$","labelLegendId":0},
	"vn_pp_14":{"color":"r","fmt":"o","mfc":"none","markersize":5.0,"label":"pp 13 TeV","labelLegendId":0},
#	"vn_pPb_zna":{"color":"b","fmt":"s","mfc":"none","markersize":5.0,"label":"2PC: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, ZNA","labelLegendId":0},
#	"vn_pPb_v0a":{"color":"b","fmt":"s","mfc":"none","markersize":5.0,"label":"2PC: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV, V0A","labelLegendId":0},
#	"vn_pPb_v0a":{"color":"k","fmt":"*","markersize":5.0,"label":"p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV ","labelLegendId":0},
	"vn_pPb_v0a_14":{"color":"b","fmt":"D","mfc":"none","markersize":5.0,"label":"p$-$Pb 5.02 TeV","labelLegendId":0},
	#"vn_hydro_pPb":{"color":"g","plotType":"theory"},
#	"vn_pPb_pub":{"color":"orange","fmt":"p","mfc":"none","markersize":5.0,"label":"$V_{2}\\{2,|\Delta\eta|<1.4\\}$: pPb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":1},
	#"vn_PbPb_pub":{"color":"brown","fmt":"D","mfc":"none","markersize":5.0,"label":"$V_{2}\\{2\\}$: Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":1},
	#"vn_pp_atl":{"color":"green","fmt":"o","markersize":5.0,"label":"ATLAS: pp $\\sqrt{s}$ = 13 TeV","labelLegendId":2},
	#"vn_pPb_atl":{"color":"purple","fmt":"s","mfc":"none","markersize":5.0,"label":"ATLAS: p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","labelLegendId":2},
	"vn_pp_pseudo":{"color":"pink","fmt":"o","mfc":"none","markersize":5.0,"label":"pp 1-4 GeV ","labelLegendId":0},
#	"vn_pPb_v0a_pseudo":{"color":"blue","fmt":"*","mfc":"none","markersize":5.0,"label":"p$-$Pb 1-4 GeV","labelLegendId":0},
	"ptBin1":{"color":"black",}


}	
#Histogran names corresponding to system and experiment
#histNames = ["pp","pPb_v2_zna","pPb_v2_v0a"];
#histNames = ["pp","pp_14","pPb_14"];
histNames = ["pp_14","pPb_14"];
#histNamesPub = ["ppHM","pPb","PbPb"];
histNamesAtlas = ["pp13","pPb"];
NremoveAtlas =[3,5]

# define panel/xaxis limits/titles
nrow = 1;
ncol = 2;
xlimits = [(0,65),(0,65)];
ylimits = [(-0.005,0.175)];
rlimits = [(0.5,1.6),(0.,4.5)];

#Alice to atlas conversion on multiplicity = N_{ch}
NchAtlaspp_pythiaOnly = [80.33, 48.83, 29.15, 14.12];
NchAtlaspp_data =  [84.07, 50.10, 33.70, 16.11]; #From Beomkyu
NchAtlaspPb_data = [85.35, 83.27, 67.26, 49.93, 33.54]; #From Beomkyu



# add labels for each pad
plables = [ "", ""
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$",
	#		"$1.0 < p_\\mathrm{T,trigg(assoc)} < 2.0$","$2.0 < p_\\mathrm{T,trigg(assoc)} < 3.0$","$3.0 < p_\\mathrm{T,trigg(assoc)} < 4.0$"
		 ];

xtitle = ["$N_\\mathrm{ch}(|\eta|<0.5)$",""];
#ytitle = ["$V_{2}$","$V_{2}\\{4\\}$"];
ytitle = ["$v_{2}$","$v_{3}$"];
#labelList = ["pp $\\sqrt{s}$ = 13 TeV our","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV our","pp $\\sqrt{s}$ = 13 TeV","p$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV","Pb$-$Pb $\\sqrt{s_\\mathrm{NN}}$ = 5.02 TeV"]


# Following two must be added
toptitle = "$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$"; # need to add on the top
dataDetail = ["$1 < p_\\mathrm{T,trig} < 2 \\,\\mathrm{GeV}/c$ \n $1 < p_\\mathrm{T,assoc} < 4 \\,\\mathrm{GeV}/c$"];


plot = JPyPlotRatio.JPyPlotRatio(panels=(nrow,ncol),
	panelsize=(5,5),
	rowBounds=ylimits,  # for nrow
	colBounds=xlimits,  # for ncol
	#panelLabel=plables,  # nrowxncol
	ratioBounds=rlimits,# for nrow
	disableRatio=[0],
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(0.01,0.10)},
	majorTickMultiple=10,
	systPatchWidth=0.02,
	panelLabelLoc=(0.85,0.85),panelLabelSize=16,panelLabelAlign="left",
	#legendPanel={0:0,1:0,2:0},
	legendPanel={0:0,1:1,2:1},
	legendLoc={0:(0.63,0.16),1:(0.49,0.5),2:(0.43,0.1)},
	legendSize=9,xlabel=xtitle[0],ylabel=ytitle,ylabelRight=ytitle[1]);

plot.EnableLatex(True);

#--- hydro calculation -------------------------------------
#pPb_hydro_mult = np.array([171.9,74.0,65.9,54.1,44.1,32.8,25.4,19.6,14.7,10.6]); #fine bins
for si,(s,color) in enumerate([
	("pT14","blue"),
	("pT14_m3","slateblue")]):#,
	fh = ROOT.TFile("data/results_dual_MAP_502_pPb_{}.root".format(s),"read")
	pPb_hydro_mult = np.array([171.9,54.1,44.1,32.8,25.4,19.6,14.7,10.6]);
	pPb_hydro_mult_avg = 0.5*(pPb_hydro_mult[:-1]+pPb_hydro_mult[1:])
	for i,n in enumerate(range(2,4)):
		gr = fh.Get("gr_v{}_QC".format(n));
		_,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr);
		plot.Add(i,(pPb_hydro_mult_avg[1:],y[1:],yerr[1:]),linecolor=color,linestyle="--",color=color,plotType="theory",alpha=0.4,label="{T\\raisebox{-.5ex}{R}ENTo}, MAP(2021)"+", m={}, p--Pb 5.02 TeV".format([6,3][si]),labelOrder=1,labelLegendId=1);
	fh.Close();

with open("data/hydroschenke/schenke_SmallSystem.pkl","rb") as f:
	schenkeDict = pickle.load(f);
for i,n in enumerate(range(2,4)):
	for s,label,color in [
		(('pPb5020','v{}'.format(n),'1_4'),"IP-Glasma $\\eta/s=0.12$, $\\zeta/s(T)$, p--Pb 5.02 TeV","royalblue"),
		(('pp13TeV','v{}'.format(n),'1_4'),"IP-Glasma $\\eta/s=0.12$, $\\zeta/s(T)$, pp 13 TeV","darkorange")]:
		d = schenkeDict[s];
		plot.Add(i,(d["mult"],d["y"],d["yerr"]),plotType="theory",linecolor=color,color=color,alpha=0.4,label=label,labelOrder=2,labelLegendId=1);
#GubsHyd Farid's
color = ["coral","red"]
gubparam=["$\\sigma_{r}$ = 0.40[fm]$, \\chi \\sigma_{\\epsilon}$ = 0.097",
		"$\\sigma_{r}$ = 0.62[fm]$, \\chi \\sigma_{\\epsilon}$ = 0.086"]
for i,p in enumerate([0,1]):
	d = np.loadtxt("data/GubsHyd/gubshyd_param{}.dat".format(p));
	plot.Add(0,(d[:,0],d[:,1]),linestyle=["--","-"][i],linecolor=color[i],color=color[i],plotType="theory",alpha=0.4,labelLegendId=2,label="GubsHyd, {}, pp 13 TeV".format(gubparam[p]));

plotMatrix = np.empty((nrow,ncol),dtype=int);

for i in range(0,2):
	#XXX use majorTickMultiple=10 in constructor
	#plot.GetAxes(i).set_xticks([0,10,20,30,40,50,60]);#,70,100, 120, 150, 200, 250,300]);
	#plot.GetAxes(1).set_xticks([0,15, 30, 45,60]);
	plot.GetAxes(i).xaxis.set_ticks_position('both');
	plot.GetAxes(i).yaxis.set_ticks_position('both');
	plot.GetAxes(i).yaxis.set_major_locator(plticker.MaxNLocator(7));

plots = {};

nmeas=4;
for i,s in enumerate(data):
	print(s)

	if i<nmeas:
		gr = data[s].Get("{}_stat".format(histNames[i]));
		grsyst = data[s].Get("{}_syst".format(histNames[i]));

		x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch
		'''
		if i==0:
		    x = np.array(NchAtlaspp_data);
		    print("pp ALICE",y);
		if i==1:
		    x = np.array(NchAtlaspPb_data);
		 ''' 

#	if i >=2 and i < 4:
#		gr = data[s].Get("gv22Gap14Stat{}".format(histNamesPub[i-2]));
#		grsyst = data[s].Get("gv22Gap14Sys{}".format(histNamesPub[i-2]));

	if i >= nmeas:
		gr = data[s].Get("grAtlas_{}_stat".format(histNamesAtlas[i-nmeas]));
		grsyst = data[s].Get("grAtlas_{}_syst".format(histNamesAtlas[i-nmeas]));
		x,y,_,yerr = JPyPlotRatio.TGraphErrorsToNumpy(gr); # to replace with ATLAS converted Nch

		if i==2:
			print("pp ATLAS",y);

	plots[s] = plot.Add(0,(x,y,yerr),**plotParams[s]); # to replace with ATLAS converted Nch
	plot.AddSyst(plots[s],grsyst);
#plot.Ratio(plots["vn_pp_14"], plots["vn_pp"]);
#plot.Ratio(plots["vn_pPb_v0a_14"], plots["vn_pPb_v0a"]);

plot.GetPlot().text(0.14,0.80,"ALICE",fontsize=12);
plot.GetPlot().text(0.31,0.30,"$1.6<|\Delta\eta|<1.8$\n$1.0<p_\\mathrm{T}<4.0\\,\\mathrm{GeV}$",fontsize=9);
#plot.GetPlot().text(0.35,0.3,"$1 < p_\\mathrm{T} < 2.0 \\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.65,0.3,"$1 < p_\\mathrm{T} < 4.0 \\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.55,0.53,"$0.2 < p_\\mathrm{T} < 3.0 \\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.55,0.65,"$|\Delta\eta|<1.4$",fontsize=8);
#plot.GetPlot().text(0.5,0.36,"$2.0<|\Delta\eta|<5.0$",fontsize=8);
#plot.GetPlot().text(0.5,0.32,"$1.0 < p_\\mathrm{T} < 5 \\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.5,0.28,"$N_\\mathrm{ch,ATLAS}^{rec}, |\eta|<2.5$, $p_\\mathrm{T}>0.4\\,\\mathrm{GeV}/c$",fontsize=8);
#plot.GetPlot().text(0.19,0.14,dataDetail[0],fontsize=11);
#-----------------------------------------------------------

plot.Plot();

plot.GetAxes(1).yaxis.tick_right();

#plot.Save("figs/Fig6_v2Mult_allSystemsComp2.pdf");
#plot.Save("figs/Fig6_v2Mult_allSystemsComp2.png");
plot.Save("figs/Fig6_v2Mult_allSystems_Hydro.pdf");
plot.Save("figs/Fig6_v2Mult_allSystems_Hydro.png");
plot.Show();

