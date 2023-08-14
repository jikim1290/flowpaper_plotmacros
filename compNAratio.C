{
	const int Nfiles = 3;
	TString filenames[Nfiles] = {"data/JYR_monash.root","data/Final_Items.root","data/Final_Items.root"};
	TString hnames[Nfiles] = {"hRatio","Acceptance_MC","Acceptance_d_stat"};
	TString labels[Nfiles] = {"PYTHIA Monash","PYTHIA 4C","ALICE data"};
	TH1D *hist[Nfiles];
	TFile *fin[Nfiles];
	for(int i=0;i<Nfiles;i++){
		fin[i] = TFile::Open(filenames[i]);
		hist[i] = (TH1D*)fin[i]->Get(hnames[i]);
	}
	TCanvas *c1 = new TCanvas("c1","c1",800,600);
	TLegend *leg = new TLegend(0.6,0.2,0.9,0.4);
	hist[0]->GetYaxis()->SetRangeUser(0.12,0.59);
	hist[0]->SetLineColor(1);
	hist[0]->GetYaxis()->SetTitle("Near/Away Ratio");
	hist[0]->GetXaxis()->SetTitle("Multiplicity bins");
	leg->AddEntry(hist[0],labels[0],"l");
	hist[0]->Draw();
	for(int i=1;i<Nfiles-1;i++){
		hist[1]->SetLineColor(i+1);
		hist[1]->Draw("same");
		leg->AddEntry(hist[i],labels[i],"l");
	}
	TH1D *Acceptance_syst__1 = new TH1D("Acceptance_syst__1","",4,0,4);
    Acceptance_syst__1->SetBinContent(1,0.3943683);
    Acceptance_syst__1->SetBinContent(2,0.4211666);
    Acceptance_syst__1->SetBinContent(3,0.4420916);
    Acceptance_syst__1->SetBinContent(4,0.4547497);
    Acceptance_syst__1->SetBinError(1,0.02842352);
    Acceptance_syst__1->SetBinError(2,0.03408905);
    Acceptance_syst__1->SetBinError(3,0.0389503);
    Acceptance_syst__1->SetBinError(4,0.03733935);
    Acceptance_syst__1->SetEntries(600.7057);
    Acceptance_syst__1->SetLineWidth(3);
    Acceptance_syst__1->SetMarkerColor(5);
    Acceptance_syst__1->Draw("same");
	leg->AddEntry(Acceptance_syst__1,labels[2],"l");
	leg->Draw();
	
	gPad->GetCanvas()->SaveAs("compNAratio.pdf");
}
