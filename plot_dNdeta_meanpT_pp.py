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

toptitle = "ALICE pp $\\sqrt{s}=13\\,\\mathrm{TeV}$";
plot = JPyPlotRatio.JPyPlotRatio(panels=(1,2),
	panelsize=(3,5.2),
	#colBounds={0:(0,57.5),1:(0,57.5)},
	rowBounds={0:(-100,120)},
	legendPanel={0:0,1:0,2:1,3:1},
	legendLoc={0:(0.21,0.18),1:(0.63,0.18),2:(0.50,0.85),3:(0.2,0.12)},#,,1:(0.16,0.2)},
	ratioBounds={0:(0.80,1.1)},
	panelPrivateScale=[1],
	panelPrivateRowBounds={1:(0.0,2.0)},
	xlabel="$\\langle\\mathrm{d}N_\\mathrm{ch}/\\mathrm{d}\\eta\\rangle$",
	ylabel={0:"$\\mathrm{d}N_\\mathrm{ch}/\\mathrm{d}\\eta$",1:"$\\langle p_\\mathrm{T}\\rangle$ (GeV/$c$)"},
	ylabelRight={0:"$\\langle p_\\mathrm{T}\\rangle$ (GeV/$c$)"},
	panelLabelSize=12,
	panelLabelLoc=(0.58,0.12));

plot.EnableLatex(True);

plot.ax[0,0].set_yscale("log");
plot.GetAxes(0).set_yscale("log");
plot.GetAxes(1).yaxis.tick_right();
plot.GetRatioAxes(1).yaxis.tick_right();

#obslabels_dNdy = ["$dN/d\\eta_p$","$dN/d\\eta_\\pi$","$dN/d\\eta_K$","$dN/d\\eta_h$"];
#obslabels_pTmean = ["$\\langle p_\\mathrm{T} \\rangle_p$","$\\langle p_\\mathrm{T} \\rangle_\\pi$","$\\langle p_\\mathrm{T} \\rangle_K$"];
species = ["Proton","Pion","Kaon"];
colors = ["red","green","blue"];
labels = ["p","$\\pi$","$K$"];
ms = ["o","D","x"];

dataPlots = {}; #For plotting

fpp13 = ROOT.TFile("data/HEPData-ins1784041-v1-root.root","read");
f = ROOT.TFile("data/results_QM2018_pPb_502.root");
for si,s in enumerate(species):
	gr = fpp13.Get("Table 20/Graph1D_y{}".format([2,0,1][si]+1));
	dataPlots["13000",s,"ptmean"] = plot.Add(1,gr,fmt=ms[si],mfc="none",color=colors[si]);

#plot.GetPlot().text(0.56,0.84,"{T\\raisebox{-.5ex}{R}ENTo}+VISH(2+1)+UrQMD",color="black",fontsize=plot.legendSize);
#plot.Add(0,(np.array([0]),np.array([4000])),color="#5f8dd3",linestyle="-.",label="MAP(QM2018)",labelLegendId=2);

fpp13.Close();
f.Close();

plot.Plot();
plot.GetPlot().text(0.15,0.83,toptitle,fontsize=12);

plot.Save("figs/dndeta_meanpT_pp.pdf");
plot.Show();

