import numpy as np
import matplotlib
import matplotlib.pyplot as plt
import matplotlib.patches as patches
import matplotlib.ticker as plticker
import ROOT
import h5py
from scipy import interpolate
import pickle
import sys
sys.path.append("JPyPlotRatio");

import JPyPlotRatio

toptitle = "ALICE pPb";
plot = JPyPlotRatio.JPyPlotRatio(panels=(1,2),
	panelsize=(3,5.2),
	colBounds={0:(0,57.5),1:(0,57.5)},
	rowBounds={0:(-100,120)},
	legendPanel={0:0,1:0,2:1,3:1},
	legendLoc={0:(0.21,0.18),1:(0.63,0.18),2:(0.50,0.85),3:(0.2,0.12)},#,,1:(0.16,0.2)},
	ratioBounds={0:(0.80,1.1)},
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(0.0,2.0)},
	xlabel="Centrality (%)",
	ylabel={0:"$\\mathrm{d}N_\\mathrm{ch}/\\mathrm{d}\\eta$",1:"$\\langle p_\\mathrm{T}\\rangle$ (GeV/$c$)"},
	ylabelRight={0:"$\\langle p_\\mathrm{T}\\rangle$ (GeV/$c$)"},
	panelLabelSize=12,
	panelLabelLoc=(0.58,0.12));

plot.EnableLatex(True);

plot.ax[0,0].set_yscale("log");
plot.GetAxes(0).set_yscale("log");
plot.GetAxes(1).yaxis.tick_right();
plot.GetRatioAxes(1).yaxis.tick_right();

data = {
	"Charged":{
		"x":np.array([2.5,7.5,15,30,50]),
		"dNdy":np.array([44.96,36.05,30.33,23.12,15.89]),
		"dNdy_err":np.array([0.99,0.8,0.67,0.52,0.35])#,0.21,0.09])
	}
}

#obslabels_dNdy = ["$dN/d\\eta_p$","$dN/d\\eta_\\pi$","$dN/d\\eta_K$","$dN/d\\eta_h$"];
#obslabels_pTmean = ["$\\langle p_\\mathrm{T} \\rangle_p$","$\\langle p_\\mathrm{T} \\rangle_\\pi$","$\\langle p_\\mathrm{T} \\rangle_K$"];
species = ["Proton","Pion","Kaon"];
colors = ["red","green","blue"];
labels = ["p","$\\pi$","$K$"];
ms = ["o","D","x"];

dataPlots = {}; #For plotting
#------
dataPlots["502","charged","eta"] = plot.Add(0,(data["Charged"]["x"],data["Charged"]["dNdy"],data["Charged"]["dNdy_err"]),color="black",fmt="s",mfc="none",labelLegendId=0,label="Charged");
#------

chiDict_dNdy = {};
chiDict_pTmean = {};
f = ROOT.TFile("data/results_QM2018_pPb_502.root");
for si,s in enumerate(species):
	gr = f.Get("gr_mult_{}".format(s));
	p = plot.Add(0,gr,alpha=1,linestyle="-.",color="#5f8dd3",scale=0.5 if si == 1 else 1.0);

	dat = np.loadtxt("data/HEPData-ins1244523-v2-Table_{}.csv".format([18,21,20][si]),skiprows=13,delimiter=',');
	dataPlots["502",s,"ptmean"] = plot.Add(1,(dat[:,3],dat[:,6]),fmt="s",mfc="none",color=colors[si],label=labels[si]);

	gr = f.Get("gr_pTmean_{}".format(s));
	p = plot.Add(1,gr,alpha=1,linestyle="-.",color="#5f8dd3");
	plot.Ratio(p,dataPlots["502",s,"ptmean"],color=colors[si]);

#Only charged particle multiplicity available
gr = f.Get("gr_mult_Charged".format(s));
p = plot.Add(0,gr,alpha=1,linestyle="-.",color="#5f8dd3");
plot.Ratio(p,dataPlots["502","charged","eta"],marker="s",mfc="none");

plot.GetPlot().text(0.56,0.84,"{T\\raisebox{-.5ex}{R}ENTo}+VISH(2+1)+UrQMD",color="black",fontsize=plot.legendSize);
plot.Add(0,(np.array([0]),np.array([4000])),color="#5f8dd3",linestyle="-.",label="MAP(QM2018)",labelLegendId=2);

f.Close();

plot.Plot();
plot.GetPlot().text(0.30,0.83,toptitle,fontsize=12);

plot.Save("/tmp/dndeta_meanpT_pPb.pdf");
plot.Show();

