TGraphErrors* AddSystG( TGraphErrors* g, double value){
 TGraphErrors* gupdated = new TGraphErrors();

 for(int i=0;i<g->GetN();i++){
	gupdated->SetPointError( i, g->GetX()[i],
		sqrt( pow( g->GetErrorY(i),2 ) +
			pow( g->GetY()[i]*value,2 ) ) );
 }
 gupdated->SetName( g->GetName() );

 return gupdated;
}

TH1D* AddSystH( TH1D* h, double value){
 TH1D* hupdated = (TH1D*)h->Clone( h->GetName() );
 hupdated->Reset();
 for(int i=0;i<hupdated->GetNbinsX();i++){
	hupdated->SetBinError( i+1,
		sqrt( pow( h->GetBinError(i+1),2 ) + pow( h->GetBinContent(i+1) *value,2 ) ) );
 }
 return hupdated;
}


void AddSyst(){
 TFile* finpp = new TFile("data/Final_Items_git.root","update");

 const int nhist = 10;
 const char hname[nhist][100] = {
	"v2_pt_syst",
	"v3_pt_syst",

	"hv2_LP_1_4_syst",
	"hv2_jet_1_4_syst",
	"hv3_LP_1_4_syst",
	"hv3_jet_1_4_syst",

	"v2_lp_syst",
	"v3_lp_syst",
	"v2_jet_syst",
	"v3_jet_syst" };

 TH1D* hAddresspp[nhist];
 TH1D* hAddressppOLD[nhist];

 double val[2] = {
	0.01, 0.03
 };

 for(int i=0;i<nhist;i++){
	hAddressppOLD[i] = (TH1D*)finpp->Get( hname[i] );
	hAddresspp[i] = (TH1D*)AddSystH( hAddressppOLD[i], val[i%2] );
	hAddressppOLD[i]->SetName(Form("%s_OLD",hAddressppOLD[i]->GetName() ));
 }

 const int ng_pp = 4;
 const char gname_pp[ng_pp][100] = {
	"pp_syst",
	"pp_14_syst",
	"pp_v3_syst",
	"pp_14_v3_syst" };

 TGraphErrors* gAddresspp[ng_pp];
 TGraphErrors* gAddressppOLD[ng_pp];

 for(int i=0;i<ng_pp;i++){
	gAddressppOLD[i] = (TGraphErrors*)finpp->Get( gname_pp[i] );
	gAddresspp[i] = (TGraphErrors*)AddSystG( gAddressppOLD[i], val[i%2]  );
	gAddressppOLD[i]->SetName(Form("%s_OLD",gAddressppOLD[i]->GetName() ));	
 }


 finpp->cd();
 for(int i=0;i<nhist;i++){
	hAddressppOLD[i]->Write();
	hAddresspp[i]->Write();
 }
 for(int i=0;i<ng_pp;i++){
	gAddressppOLD[i]->Write();
	gAddresspp[i]->Write();
 } 


 TFile* finpPb = new TFile("data/fout_v2_pPb_v2_git.root","update");

 const int nhist_pPb = 2;
 const char hname_pPb[nhist_pPb][100] = {
    "v2_v0a_syst_pt",
    "v3_v0a_syst_pt" };

 double valpPb[2] = {
    0.01, 0.08
 };

 TH1D* hAddresspPb[nhist];
 TH1D* hAddresspPbOLD[nhist];

 for(int i=0;i<nhist_pPb;i++){
    hAddresspPbOLD[i] = (TH1D*)finpPb->Get( hname_pPb[i] );
    hAddresspPb[i] = (TH1D*)AddSystH( hAddresspPbOLD[i], valpPb[i%2] );
    hAddresspPbOLD[i]->SetName(Form("%s_OLD",hAddresspPbOLD[i]->GetName() ));
 }


 const int ng_pPb = 2;
 const char gname_pPb[ng_pPb][100] = {
    "pPb_14_v2_syst",
    "pPb_14_v3_syst" };

 TGraphErrors* gAddresspPb[ng_pp];
 TGraphErrors* gAddresspPbOLD[ng_pp];

 for(int i=0;i<ng_pPb;i++){
    gAddresspPbOLD[i] = (TGraphErrors*)finpPb->Get( gname_pPb[i] );
    gAddresspPb[i] = (TGraphErrors*)AddSystG( gAddresspPbOLD[i], valpPb[i%2] );
    gAddresspPbOLD[i]->SetName(Form("%s_OLD",gAddresspPbOLD[i]->GetName() ));
 }

 finpPb->cd();
 for(int i=0;i<nhist_pPb;i++){
	hAddresspPbOLD[i]->Write();
	hAddresspPb[i]->Write();
 }
 for(int i=0;i<ng_pPb;i++){
	gAddresspPbOLD[i]->Write();
	gAddresspPb[i]->Write();
 }

}






