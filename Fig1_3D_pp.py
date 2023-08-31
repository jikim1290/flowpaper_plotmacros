from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np
import sys
from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.ticker as ticker
from fractions import Fraction
sys.path.append("JPyPlotRatio");
import JPyPlotRatio
import ROOT

# define panel/xaxis limits/titles

xtitle = "$\\Delta\\eta$"
ytitle = "$\\Delta\\phi$"
ztitle = ""

modelTypePlotParams = [
    {'color':'#0051a2','alpha':0.5,'linestyle':'solid'}
];

filenames = ["data/Corr2d_figures_pp.root"
             ]

centBin = ["hC_5_0_0_2_11", "hC_0_0_0_3_11", "hC_0_0_0_4_11"]

zxydata = {}

zlimmax = [1.3,2,0.15]
zlimmin = [1.15,0,0.06]

f = ROOT.TFile(filenames[0],"read");
f.Print()
for ic in range(0,len(centBin)):
    histnames = ["{:s}".format(centBin[ic])
    ]; # 
    h2D = f.Get("{}".format(histnames[0]));
    #h2D.RebinX(4)
    #h2D.Scale(1./4)
    #h2D.Print()

    z,x,y = JPyPlotRatio.TH2ToNumpy(h2D);
    x,y = np.meshgrid(x,y)
    zxydata[filenames[0],"z",ic] = z
    zxydata[filenames[0],"x",ic] = x
    #zxydata[filenames[0],"y",ic] = np.absolute(y)
    zxydata[filenames[0],"y",ic] = y

# set up a figure twice as wide as it is tall
fig = plt.figure(figsize=plt.figaspect(0.8))
# set up the axes for the first plot
#print(paramsinfo)
zmax = 0.

for ic in range(0,len(centBin)):
    ax = fig.add_subplot(2, 2, ic+1, projection='3d')
    #print(zxydata.get((filenames[i],"z"),-999))
    surf = ax.plot_surface(
     zxydata.get((filenames[0],"x",ic),-999), 
     zxydata.get((filenames[0],"y",ic),-999), 
     zxydata.get((filenames[0],"z",ic),-999), 
        rstride=1, cstride=1, cmap=cm.rainbow, alpha=0.5, edgecolors="black",
                   linewidth=0, antialiased=False)
    #ax.set_zlim(-1.01, 1.01)
    #fig.colorbar(surf, shrink=0.5, aspect=10)
    
    
    
    ax.set_xlabel(xtitle, fontsize=6, labelpad=-5)
    ax.set_ylabel(ytitle, fontsize=6, labelpad=-5)
    ax.tick_params(axis='y', which='major', pad=-1.5, labelsize=6)
    ax.tick_params(axis='x', which='major', pad=-3.0, labelsize=6)
    ax.tick_params(axis='z', which='major', pad=-3.0, labelsize=6)
    ax.yaxis.set_major_locator(ticker.MultipleLocator(1.))
    ax.xaxis.set_major_locator(ticker.MultipleLocator(0.4))

    #create_pi_labels(-0.25, 1.25, 1, ax, 'x')
    #if(i==0):
    # ax.set_zlabel(ztitle)
    #if(i==0):
    #    fig.colorbar(surf, shrink=0.6, aspect=4,location='left')
    #ax.title.set_text(centBin[ic])
    #ax.title.set_size(8)
    ax.view_init(45, 45)
    plt.title(centBin[ic], loc='left', fontsize=7)
    plt.xlim(-1.6, 1.6)
    #ax.set_zlim(zlimmin[ic],zlimmin[ic])
    plt.subplots_adjust(
    #                left=0.1,
    #                bottom=0.1,
    #                right=0.9,
    #                top=0.9,
                wspace=0.15,
                hspace=0.6)
    linex = np.array([0.0,-0.8])
    liney = np.array([-8.0,6.0])
    linez = np.array([0.0,0.0])
    #ax.plot(linex, liney, linez, label="cut-off", color="red") #**modelTypePlotParams[ig],
    
fig.savefig("figs/Fig1_3D_pp.pdf")
