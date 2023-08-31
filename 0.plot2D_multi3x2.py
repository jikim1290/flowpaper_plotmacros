from matplotlib import cm
import matplotlib.pyplot as plt
import numpy as np
import sys
#from matplotlib.backends.backend_pdf import PdfPages
import matplotlib.ticker as ticker
from fractions import Fraction
sys.path.append("JPyPlotRatio");
import JPyPlotRatio
import ROOT

def create_pi_labels(a=0, b=2, step=0.5, ax=None, direction='x'):
	"""
	A function that gives back ticks an labels in radians
	Keyword arguments:
	a -- lower limit is a*pi (default 0.0)
	b -- upper limit is b*pi (default 2.0)
	step -- step is step*pi  (default 0.5)
	ax -- if ax is not None then ticks and labels are set for this axes (default None)
	direction -- 'x' or 'y' or 'z' (default 'x') which axis you want to label
	return value is ticks, labels
	"""

	max_denominator = int(1/step)
	values = np.arange(a, b+0.1*step, step)
	fracs = [Fraction(x).limit_denominator(max_denominator) for x in values]
	ticks = values*np.pi

	if plt.rcParams["text.usetex"] is True:
		vspace = r"\vphantom{\frac{1}{2}}"
	else:
		vspace = ""

	labels = []

	for frac in fracs:
		if frac.numerator==0:
			labels.append(r"$0" + vspace + "$")
		elif frac.numerator<0:
			if frac.denominator==1 and abs(frac.numerator)==1:
				labels.append(r"$-\pi" + vspace + "$")
			elif frac.denominator==1:
				labels.append(r"$-{}\pi".format(abs(frac.numerator)) +vspace + "$")
			else:
				labels.append(r"$-\frac{{{}}}{{{}}} \pi$".format(abs(frac.numerator), frac.denominator))
		else:
			if frac.denominator==1 and frac.numerator==1:
				labels.append(r"$\pi" + vspace + "$")
			elif frac.denominator==1:
				labels.append(r"${}\pi".format(frac.numerator) + vspace + "$")
			else:
				labels.append(r"$\frac{{{}}}{{{}}} \pi$".format(frac.numerator, frac.denominator))

	if ax is not None:
		if direction == 'x':
			ax.set_xticks(ticks)
			ax.set_xticklabels(labels)
		elif direction == 'y':
			ax.set_yticks(ticks)
			ax.set_yticklabels(labels)
		elif direction == 'z':
			ax.set_zticks(ticks)
			ax.set_zticklabels(labels)
		else:
			print("direction ", direction, "is not a proper argument")

	return ticks, labels



# define panel/xaxis limits/titles
ChopNearSidePeak = False;
toptitle = "ALICE pp $\\sqrt{s}$ = 13 TeV"; # need to add on the top
xtitle = "$\\Delta\\varphi (\\mathrm{rad})$"
ytitle = "$\\Delta\\eta$"
ztitle = "$(1/N_\mathrm{trig})\mathrm{d}^2 N^\mathrm{pair}/\mathrm{d}\Delta\eta\mathrm{d}\Delta\varphi$"

#	for (int ic = 0; ic < nbins_mult; ic++) {
#		for (int iptt = 0; iptt < Nptt; iptt++) {
#			TString hname = Form("dphi_%d_0_%d",iptt,ic);
#			h2D[ic][iptt] = (TH2D*) fIn->Get(hname);
datatitle = "pp $\\sqrt{s}$ = 13TeV"; 
paramsinfo = {}; 


modelTypePlotParams = [
	{'color':'#0051a2','alpha':1.0,'linestyle':'solid'},
	{'color':'#e580ff','alpha':1.0,'linestyle':'solid'},
	{'color':'red','alpha':1.0,'linestyle':'solid'}
];

# arg int
SelDraw = [1, 4, 6, 8, 10, 11, 12,14]
ipt = 0
zmin = [0.002, 0.015, 0.04, 0.05]
zmax = [0.002, 0.02, 0.03, 0.09]
ar_zmin = np.array(zmin)
ar_zmax = np.array(zmax)

files = ["data/Corr2d_figures_pp.root"]

histnames = ["hC_5_0_0_2_11", "hC_0_0_0_3_11", "hC_0_0_0_4_11"]
dataTypeStr = ["0-0.1%", "20-60%", "60-100%"]
# set up a figure twice as wide as it is tall
fig = plt.figure(figsize=plt.figaspect(0.5))

# set up the axes for the first plot
#print(paramsinfo)
zmax = 0.
for i in range(0,len(files)):
	fig.clear();

	f1 = ROOT.TFile(files[i]);

	for ic in range(0,len(histnames)):
		f = ROOT.TFile(files[i],"read");
		f.Print()
		h2D = f.Get("{}".format(histnames[ic]));
		#h2D.RebinX(2)
		#h2D.Scale(1./2)
		h2D.Print()
		if(i==0):
			datatitle = h2D.GetTitle()
			paramsinfo[SelDraw[ic]] = datatitle.split(",")

		z,y,x = JPyPlotRatio.TH2ToNumpy(h2D);
		y,x = np.meshgrid(y,x)
		if(ChopNearSidePeak):
			awaySideMax = z[x > 0.95*np.pi].max();
			z[z > awaySideMax] = awaySideMax;
		z[z <= 1e-6] = np.nan;
		f.Close();

		#----
		ax = fig.add_subplot(1, 3, ic+1, projection='3d')
		
		surf = ax.plot_surface(x,y,z,rstride=1, cstride=1, cmap=cm.jet,edgecolors="black",linewidth=0, antialiased=False, alpha=1.0)
		#ax.set_axisbelow(True);
		#print(ar_zmin[ic],ar_zmax[ic])
		#ax.set_zlim(0.05,0.07)
		#ax.set_ylim(-1.5,1.5)
		#fig.colorbar(surf, shrink=0.5, aspect=10)

		ax.set_xlabel(xtitle)
		ax.set_ylabel(ytitle)

		ax.yaxis.set_major_locator(ticker.MultipleLocator(1.))
		ax.xaxis.set_major_locator(ticker.MultipleLocator(2.0))
		create_pi_labels(-0.25, 1.25, 1, ax, 'x')
		if(ic==0):
		 ax.set_zlabel(ztitle)
		#if(i==0):
		#    fig.colorbar(surf, shrink=0.6, aspect=4,location='left')
		ax.title.set_text("{}".format(dataTypeStr[ic]))
		ax.view_init(45, 45)
		plt.subplots_adjust(
		#                left=0.1,
		#                bottom=0.1,
		#                right=0.9,
		#                top=0.9,
					wspace=0.15,
					hspace=0.6);

	ax.legend(loc = 'upper right', prop={'size': 6},bbox_to_anchor=(1.1, 1))    
	fig.text(0.4, 0.8, toptitle, fontsize=12, color="black")
	if(ChopNearSidePeak):
		fig.savefig("figures/Fig_2DCorrelations_ChopNearSidePeak.pdf")
	else:
		fig.savefig("figures/Fig_2DCorrelations.pdf")
	#fig.show()

