
import numpy as np
import pickle

files = [
	"pp13TeV_ch_v2{2}_pT0.2.dat",
	"pp13TeV_ch_v2{2}_pT1_4.dat",
	"pp13TeV_ch_v3{2}_pT0.2.dat",
	"pp13TeV_ch_v3{2}_pT1_4.dat",
	"pPb5020_ch_v2{2}_pT0.2.dat",
	"pPb5020_ch_v2{2}_pT1_4.dat",
	"pPb5020_ch_v3{2}_pT0.2.dat",
	"pPb5020_ch_v3{2}_pT1_4.dat",
];

data = {};

for f in files:
	name = f.split('_');
	pt = f.split('pT')[1].replace('.','_');

	a = np.loadtxt(f);
	data[(name[0],name[2][:-3],pt[:-4])] = {"cent":a[:,0],"mult":a[:,1],"y":a[:,2],"yerr":a[:,3]};
	print((name[0],name[2][:-3],pt[:-4]));

with open("schenke_smallSystem.pkl","wb") as f:
	pickle.dump(data,f);

