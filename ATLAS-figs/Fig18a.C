void RemovePoints(TGraphErrors, double);

void RemovePoints(TGraphErrors *ge, double nch)
{
   // Remove zero points from TGraphErrors.

   if(!ge){return;}

   Int_t nPoints = ge->GetN();
   Double_t x = 0.; 
   Double_t y = 0.; 
   int p =0; 
   while(p<nPoints) {
      ge->GetPoint(p,x,y);
      //if( x < 0.21 || x>8.  )
      if( x < nch  )
      {   
         ge->RemovePoint(p);
         //       cout<<Form(" WARNING (%s): point %d is < 1.e-10 and it was removed from the plot !!!!",ge->GetName(),p+1)<<endl;
         nPoints = ge->GetN();
      } else {
         p++;
      }   
   } // end of for(Int_t p=0;p<nPoints;p++)

   //cout<<endl;
   return;

} // end of void RemoveZeroPoints(TGraphErrors *ge)

void Fig18a()
{
//=========Macro generated from canvas: Fig18a/Fig18a
//=========  (Tue Jun 30 01:37:35 2020) by ROOT version 6.14/04

   // adding output file to read in python plotting macro
   TFile *output = new TFile("output-figure18a.root","recreate");
   output->cd();

   TCanvas *Fig18a = new TCanvas("Fig18a", "Fig18a",960,52,600,450);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
	 gStyle->SetErrorX(0.0001);
   Fig18a->Range(-43.37349,-0.02897468,318.0723,0.1583671);
   Fig18a->SetFillColor(0);
   Fig18a->SetBorderMode(0);
   Fig18a->SetBorderSize(2);
   Fig18a->SetTickx(1);
   Fig18a->SetTicky(1);
   Fig18a->SetLeftMargin(0.12);
   Fig18a->SetRightMargin(0.05);
   Fig18a->SetTopMargin(0.05);
   Fig18a->SetBottomMargin(0.16);
   Fig18a->SetFrameBorderMode(0);
   Fig18a->SetFrameBorderMode(0);

   Double_t xAxis9[18] = {0, 10, 20, 30, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
   
   TH1D *hist_pPb_systErrs = new TH1D("hist_pPb_systErrs","",17, xAxis9);
   hist_pPb_systErrs->SetBinContent(3,0.08703759);
   hist_pPb_systErrs->SetBinContent(4,0.08868399);
   hist_pPb_systErrs->SetBinContent(5,0.09313858);
   hist_pPb_systErrs->SetBinContent(6,0.09834794);
   hist_pPb_systErrs->SetBinContent(7,0.1012088);
   hist_pPb_systErrs->SetBinContent(8,0.1037441);
   hist_pPb_systErrs->SetBinContent(9,0.1063114);
   hist_pPb_systErrs->SetBinContent(10,0.1075335);
   hist_pPb_systErrs->SetBinContent(11,0.1085632);
   hist_pPb_systErrs->SetBinContent(12,0.1084577);
   hist_pPb_systErrs->SetBinContent(13,0.1089404);
   hist_pPb_systErrs->SetBinContent(14,0.1089031);
   hist_pPb_systErrs->SetBinContent(15,0.1074288);
   hist_pPb_systErrs->SetBinContent(16,0.1071738);
   hist_pPb_systErrs->SetBinContent(17,0.1080675);
   hist_pPb_systErrs->SetBinError(3,0.005319134);
   hist_pPb_systErrs->SetBinError(4,0.004767006);
   hist_pPb_systErrs->SetBinError(5,0.00299517);
   hist_pPb_systErrs->SetBinError(6,0.003049343);
   hist_pPb_systErrs->SetBinError(7,0.003033458);
   hist_pPb_systErrs->SetBinError(8,0.003015711);
   hist_pPb_systErrs->SetBinError(9,0.003009377);
   hist_pPb_systErrs->SetBinError(10,0.002978668);
   hist_pPb_systErrs->SetBinError(11,0.002959057);
   hist_pPb_systErrs->SetBinError(12,0.002926792);
   hist_pPb_systErrs->SetBinError(13,0.002929554);
   hist_pPb_systErrs->SetBinError(14,0.002937803);
   hist_pPb_systErrs->SetBinError(15,0.002926271);
   hist_pPb_systErrs->SetBinError(16,0.00266201);
   hist_pPb_systErrs->SetBinError(17,0.002684153);
   hist_pPb_systErrs->SetMinimum(0.001);
   hist_pPb_systErrs->SetMaximum(0.149);
   hist_pPb_systErrs->SetEntries(15);
   hist_pPb_systErrs->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#9999ff");
   hist_pPb_systErrs->SetLineColor(ci);
   hist_pPb_systErrs->SetLineWidth(11);
   hist_pPb_systErrs->SetMarkerColor(4);
   hist_pPb_systErrs->SetMarkerStyle(25);
   hist_pPb_systErrs->SetMarkerSize(1.2);
   hist_pPb_systErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pPb_systErrs->GetXaxis()->SetLabelFont(42);
   hist_pPb_systErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pPb_systErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pPb_systErrs->GetXaxis()->SetTitleFont(42);
   hist_pPb_systErrs->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   hist_pPb_systErrs->GetYaxis()->SetNdivisions(505);
   hist_pPb_systErrs->GetYaxis()->SetLabelFont(42);
   hist_pPb_systErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pPb_systErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pPb_systErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pPb_systErrs->GetYaxis()->SetTitleFont(42);
   hist_pPb_systErrs->GetZaxis()->SetLabelFont(42);
   hist_pPb_systErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pPb_systErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pPb_systErrs->GetZaxis()->SetTitleFont(42);
   hist_pPb_systErrs->Draw();
   Double_t xAxis10[18] = {0, 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}; 

   
   TH1D *hist_pp13_systErrs = new TH1D("hist_pp13_systErrs","",17, xAxis10);
   hist_pp13_systErrs->SetBinContent(5,0.06778575);
   hist_pp13_systErrs->SetBinContent(6,0.07247118);
   hist_pp13_systErrs->SetBinContent(7,0.07511725);
   hist_pp13_systErrs->SetBinContent(8,0.07527599);
   hist_pp13_systErrs->SetBinContent(9,0.07713918);
   hist_pp13_systErrs->SetBinContent(10,0.07839933);
   hist_pp13_systErrs->SetBinContent(11,0.07796498);
   hist_pp13_systErrs->SetBinContent(12,0.07858497);
   hist_pp13_systErrs->SetBinContent(13,0.07704914);
   hist_pp13_systErrs->SetBinContent(14,0.07640076);
   hist_pp13_systErrs->SetBinContent(15,0.07491138);
   hist_pp13_systErrs->SetBinContent(16,0.07952838);
   hist_pp13_systErrs->SetBinContent(17,0.07546426);
   hist_pp13_systErrs->SetBinError(5,0.002177373);
   hist_pp13_systErrs->SetBinError(6,0.00219705);
   hist_pp13_systErrs->SetBinError(7,0.002058736);
   hist_pp13_systErrs->SetBinError(8,0.001861487);
   hist_pp13_systErrs->SetBinError(9,0.002048036);
   hist_pp13_systErrs->SetBinError(10,0.001910903);
   hist_pp13_systErrs->SetBinError(11,0.001753426);
   hist_pp13_systErrs->SetBinError(12,0.001629777);
   hist_pp13_systErrs->SetBinError(13,0.001550755);
   hist_pp13_systErrs->SetBinError(14,0.001542513);
   hist_pp13_systErrs->SetBinError(15,0.001523999);
   hist_pp13_systErrs->SetBinError(16,0.001583215);
   hist_pp13_systErrs->SetBinError(17,0.001530801);
   hist_pp13_systErrs->SetMinimum(0.001);
   hist_pp13_systErrs->SetMaximum(0.149);
   hist_pp13_systErrs->SetEntries(13);
   hist_pp13_systErrs->SetStats(0);

   ci = TColor::GetColor("#999999");
   hist_pp13_systErrs->SetLineColor(ci);
   hist_pp13_systErrs->SetLineWidth(9);
   hist_pp13_systErrs->SetMarkerStyle(20);
   hist_pp13_systErrs->SetMarkerSize(1.2);
   hist_pp13_systErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pp13_systErrs->GetXaxis()->SetLabelFont(42);
   hist_pp13_systErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pp13_systErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pp13_systErrs->GetXaxis()->SetTitleFont(42);
   hist_pp13_systErrs->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   hist_pp13_systErrs->GetYaxis()->SetNdivisions(505);
   hist_pp13_systErrs->GetYaxis()->SetLabelFont(42);
   hist_pp13_systErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pp13_systErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pp13_systErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pp13_systErrs->GetYaxis()->SetTitleFont(42);
   hist_pp13_systErrs->GetZaxis()->SetLabelFont(42);
   hist_pp13_systErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pp13_systErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pp13_systErrs->GetZaxis()->SetTitleFont(42);
   hist_pp13_systErrs->Draw("same");
   Double_t xAxis11[15] = {0, 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120}; 
   
   TH1D *hist_pp5_systErrs = new TH1D("hist_pp5_systErrs","",14, xAxis11);
   hist_pp5_systErrs->SetBinContent(5,0.06466439);
   hist_pp5_systErrs->SetBinContent(6,0.07661603);
   hist_pp5_systErrs->SetBinContent(7,0.07653926);
   hist_pp5_systErrs->SetBinContent(8,0.0766064);
   hist_pp5_systErrs->SetBinContent(9,0.07568128);
   hist_pp5_systErrs->SetBinContent(10,0.07522215);
   hist_pp5_systErrs->SetBinContent(11,0.07647102);
   hist_pp5_systErrs->SetBinContent(12,0.07560537);
   hist_pp5_systErrs->SetBinContent(13,0.07341854);
   hist_pp5_systErrs->SetBinContent(14,0.07751568);
   hist_pp5_systErrs->SetBinError(5,0.00278699);
   hist_pp5_systErrs->SetBinError(6,0.002875119);
   hist_pp5_systErrs->SetBinError(7,0.002174868);
   hist_pp5_systErrs->SetBinError(8,0.001545115);
   hist_pp5_systErrs->SetBinError(9,0.001831549);
   hist_pp5_systErrs->SetBinError(10,0.00182347);
   hist_pp5_systErrs->SetBinError(11,0.001845561);
   hist_pp5_systErrs->SetBinError(12,0.00183021);
   hist_pp5_systErrs->SetBinError(13,0.001792244);
   hist_pp5_systErrs->SetBinError(14,0.00186431);
   hist_pp5_systErrs->SetMinimum(0.001);
   hist_pp5_systErrs->SetMaximum(0.149);
   hist_pp5_systErrs->SetEntries(10);
   hist_pp5_systErrs->SetStats(0);

   ci = TColor::GetColor("#cc6666");
   hist_pp5_systErrs->SetLineColor(ci);
   hist_pp5_systErrs->SetLineWidth(7);
   hist_pp5_systErrs->SetMarkerColor(2);
   hist_pp5_systErrs->SetMarkerStyle(24);
   hist_pp5_systErrs->SetMarkerSize(1.2);
   hist_pp5_systErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pp5_systErrs->GetXaxis()->SetLabelFont(42);
   hist_pp5_systErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pp5_systErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pp5_systErrs->GetXaxis()->SetTitleFont(42);
   hist_pp5_systErrs->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   hist_pp5_systErrs->GetYaxis()->SetNdivisions(505);
   hist_pp5_systErrs->GetYaxis()->SetLabelFont(42);
   hist_pp5_systErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pp5_systErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pp5_systErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pp5_systErrs->GetYaxis()->SetTitleFont(42);
   hist_pp5_systErrs->GetZaxis()->SetLabelFont(42);
   hist_pp5_systErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pp5_systErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pp5_systErrs->GetZaxis()->SetTitleFont(42);
   hist_pp5_systErrs->Draw("same");
   Double_t xAxis12[18] = {0, 10, 20, 30, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
   
   TH1D *UniqueName6__12 = new TH1D("UniqueName6__12","",17, xAxis12);
   UniqueName6__12->SetBinContent(3,0.08703759);
   UniqueName6__12->SetBinContent(4,0.08868399);
   UniqueName6__12->SetBinContent(5,0.09313858);
   UniqueName6__12->SetBinContent(6,0.09834794);
   UniqueName6__12->SetBinContent(7,0.1012088);
   UniqueName6__12->SetBinContent(8,0.1037441);
   UniqueName6__12->SetBinContent(9,0.1063114);
   UniqueName6__12->SetBinContent(10,0.1075335);
   UniqueName6__12->SetBinContent(11,0.1085632);
   UniqueName6__12->SetBinContent(12,0.1084577);
   UniqueName6__12->SetBinContent(13,0.1089404);
   UniqueName6__12->SetBinContent(14,0.1089031);
   UniqueName6__12->SetBinContent(15,0.1074288);
   UniqueName6__12->SetBinContent(16,0.1071738);
   UniqueName6__12->SetBinContent(17,0.1080675);
   UniqueName6__12->SetBinError(3,0.001630642);
   UniqueName6__12->SetBinError(4,0.0007994473);
   UniqueName6__12->SetBinError(5,0.0003936738);
   UniqueName6__12->SetBinError(6,0.000257954);
   UniqueName6__12->SetBinError(7,0.0002104193);
   UniqueName6__12->SetBinError(8,0.0001740828);
   UniqueName6__12->SetBinError(9,0.000163734);
   UniqueName6__12->SetBinError(10,0.0001238883);
   UniqueName6__12->SetBinError(11,0.0001231283);
   UniqueName6__12->SetBinError(12,0.000136666);
   UniqueName6__12->SetBinError(13,0.0001233295);
   UniqueName6__12->SetBinError(14,0.0001051128);
   UniqueName6__12->SetBinError(15,0.0001538768);
   UniqueName6__12->SetBinError(16,0.0002979711);
   UniqueName6__12->SetBinError(17,0.0006225556);
   UniqueName6__12->SetMinimum(0.001);
   UniqueName6__12->SetMaximum(0.149);
   UniqueName6__12->SetEntries(15);
   UniqueName6__12->SetStats(0);
   UniqueName6__12->SetLineColor(4);
   UniqueName6__12->SetLineWidth(2);
   UniqueName6__12->SetMarkerColor(4);
   UniqueName6__12->SetMarkerStyle(25);
   UniqueName6__12->SetMarkerSize(1.2);
   UniqueName6__12->GetXaxis()->SetTitle("N_{ch}^{rec}");
   UniqueName6__12->GetXaxis()->SetLabelFont(42);
   UniqueName6__12->GetXaxis()->SetLabelSize(0.05);
   UniqueName6__12->GetXaxis()->SetTitleSize(0.06);
   UniqueName6__12->GetXaxis()->SetTitleFont(42);
   UniqueName6__12->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName6__12->GetYaxis()->SetNdivisions(505);
   UniqueName6__12->GetYaxis()->SetLabelFont(42);
   UniqueName6__12->GetYaxis()->SetLabelSize(0.05);
   UniqueName6__12->GetYaxis()->SetTitleSize(0.06);
   UniqueName6__12->GetYaxis()->SetTitleOffset(0.97);
   UniqueName6__12->GetYaxis()->SetTitleFont(42);
   UniqueName6__12->GetZaxis()->SetLabelFont(42);
   UniqueName6__12->GetZaxis()->SetLabelSize(0.05);
   UniqueName6__12->GetZaxis()->SetTitleSize(0.05);
   UniqueName6__12->GetZaxis()->SetTitleFont(42);
   UniqueName6__12->Draw("same");
   Double_t xAxis13[18] = {0, 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120, 130, 140, 150}; 
   
   TH1D *UniqueName7__13 = new TH1D("UniqueName7__13","",17, xAxis13);
   UniqueName7__13->SetBinContent(5,0.06778575);
   UniqueName7__13->SetBinContent(6,0.07247118);
   UniqueName7__13->SetBinContent(7,0.07511725);
   UniqueName7__13->SetBinContent(8,0.07527599);
   UniqueName7__13->SetBinContent(9,0.07713918);
   UniqueName7__13->SetBinContent(10,0.07839933);
   UniqueName7__13->SetBinContent(11,0.07796498);
   UniqueName7__13->SetBinContent(12,0.07858497);
   UniqueName7__13->SetBinContent(13,0.07704914);
   UniqueName7__13->SetBinContent(14,0.07640076);
   UniqueName7__13->SetBinContent(15,0.07491138);
   UniqueName7__13->SetBinContent(16,0.07952838);
   UniqueName7__13->SetBinContent(17,0.07546426);
   UniqueName7__13->SetBinError(5,0.001247466);
   UniqueName7__13->SetBinError(6,0.0006838962);
   UniqueName7__13->SetBinError(7,0.0005143136);
   UniqueName7__13->SetBinError(8,0.0005024001);
   UniqueName7__13->SetBinError(9,0.0002800077);
   UniqueName7__13->SetBinError(10,0.0003110915);
   UniqueName7__13->SetBinError(11,0.0003797039);
   UniqueName7__13->SetBinError(12,0.0002471209);
   UniqueName7__13->SetBinError(13,0.0003082976);
   UniqueName7__13->SetBinError(14,0.0004148111);
   UniqueName7__13->SetBinError(15,0.0006028563);
   UniqueName7__13->SetBinError(16,0.0008374751);
   UniqueName7__13->SetBinError(17,0.001365468);
   UniqueName7__13->SetMinimum(0.001);
   UniqueName7__13->SetMaximum(0.149);
   UniqueName7__13->SetEntries(13);
   UniqueName7__13->SetStats(0);
   UniqueName7__13->SetLineWidth(2);
   UniqueName7__13->SetMarkerStyle(20);
   UniqueName7__13->SetMarkerSize(1.2);
   UniqueName7__13->GetXaxis()->SetTitle("N_{ch}^{rec}");
   UniqueName7__13->GetXaxis()->SetLabelFont(42);
   UniqueName7__13->GetXaxis()->SetLabelSize(0.05);
   UniqueName7__13->GetXaxis()->SetTitleSize(0.06);
   UniqueName7__13->GetXaxis()->SetTitleFont(42);
   UniqueName7__13->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName7__13->GetYaxis()->SetNdivisions(505);
   UniqueName7__13->GetYaxis()->SetLabelFont(42);
   UniqueName7__13->GetYaxis()->SetLabelSize(0.05);
   UniqueName7__13->GetYaxis()->SetTitleSize(0.06);
   UniqueName7__13->GetYaxis()->SetTitleOffset(0.97);
   UniqueName7__13->GetYaxis()->SetTitleFont(42);
   UniqueName7__13->GetZaxis()->SetLabelFont(42);
   UniqueName7__13->GetZaxis()->SetLabelSize(0.05);
   UniqueName7__13->GetZaxis()->SetTitleSize(0.05);
   UniqueName7__13->GetZaxis()->SetTitleFont(42);
   UniqueName7__13->Draw("same");
   Double_t xAxis14[15] = {0, 5, 10, 15, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120}; 
   
   TH1D *UniqueName8__14 = new TH1D("UniqueName8__14","",14, xAxis14);
   UniqueName8__14->SetBinContent(5,0.06466439);
   UniqueName8__14->SetBinContent(6,0.07661603);
   UniqueName8__14->SetBinContent(7,0.07653926);
   UniqueName8__14->SetBinContent(8,0.0766064);
   UniqueName8__14->SetBinContent(9,0.07568128);
   UniqueName8__14->SetBinContent(10,0.07522215);
   UniqueName8__14->SetBinContent(11,0.07647102);
   UniqueName8__14->SetBinContent(12,0.07560537);
   UniqueName8__14->SetBinContent(13,0.07341854);
   UniqueName8__14->SetBinContent(14,0.07751568);
   UniqueName8__14->SetBinError(5,0.003924467);
   UniqueName8__14->SetBinError(6,0.002177656);
   UniqueName8__14->SetBinError(7,0.002113126);
   UniqueName8__14->SetBinError(8,0.002518095);
   UniqueName8__14->SetBinError(9,0.0005686581);
   UniqueName8__14->SetBinError(10,0.0005884767);
   UniqueName8__14->SetBinError(11,0.0007322505);
   UniqueName8__14->SetBinError(12,0.0006264001);
   UniqueName8__14->SetBinError(13,0.000983797);
   UniqueName8__14->SetBinError(14,0.001626045);
   UniqueName8__14->SetMinimum(0.001);
   UniqueName8__14->SetMaximum(0.149);
   UniqueName8__14->SetEntries(10);
   UniqueName8__14->SetStats(0);
   UniqueName8__14->SetLineColor(2);
   UniqueName8__14->SetLineWidth(2);
   UniqueName8__14->SetMarkerColor(2);
   UniqueName8__14->SetMarkerStyle(24);
   UniqueName8__14->SetMarkerSize(1.2);
   UniqueName8__14->GetXaxis()->SetTitle("N_{ch}^{rec}");
   UniqueName8__14->GetXaxis()->SetLabelFont(42);
   UniqueName8__14->GetXaxis()->SetLabelSize(0.05);
   UniqueName8__14->GetXaxis()->SetTitleSize(0.06);
   UniqueName8__14->GetXaxis()->SetTitleFont(42);
   UniqueName8__14->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName8__14->GetYaxis()->SetNdivisions(505);
   UniqueName8__14->GetYaxis()->SetLabelFont(42);
   UniqueName8__14->GetYaxis()->SetLabelSize(0.05);
   UniqueName8__14->GetYaxis()->SetTitleSize(0.06);
   UniqueName8__14->GetYaxis()->SetTitleOffset(0.97);
   UniqueName8__14->GetYaxis()->SetTitleFont(42);
   UniqueName8__14->GetZaxis()->SetLabelFont(42);
   UniqueName8__14->GetZaxis()->SetLabelSize(0.05);
   UniqueName8__14->GetZaxis()->SetTitleSize(0.05);
   UniqueName8__14->GetZaxis()->SetTitleFont(42);
   UniqueName8__14->Draw("same");
   

   int NremoveAtlas[] = {2,4};
   TGraphErrors *grAtlas_pPb_syst =  new TGraphErrors(hist_pPb_systErrs);
   TGraphErrors *grAtlas_pp13_syst =  new TGraphErrors(hist_pp13_systErrs);
   TGraphErrors *grAtlas_pp5_syst =  new TGraphErrors(hist_pp5_systErrs);
   TGraphErrors *grAtlas_pPb_stat =  new TGraphErrors(UniqueName6__12);
   TGraphErrors *grAtlas_pp13_stat =  new TGraphErrors(UniqueName7__13);
   TGraphErrors *grAtlas_pp5_stat =  new TGraphErrors(UniqueName8__14);

   RemovePoints(grAtlas_pPb_syst,20);
   RemovePoints(grAtlas_pPb_stat,20);
   
   RemovePoints(grAtlas_pp13_syst,20);
   RemovePoints(grAtlas_pp13_stat,20);
   RemovePoints(grAtlas_pp5_syst,20);
   RemovePoints(grAtlas_pp5_stat,20);
      
   // Writing histograms to file
   grAtlas_pPb_syst->Write("grAtlas_pPb_syst");
   grAtlas_pp13_syst->Write("grAtlas_pp13_syst");
   grAtlas_pp5_syst->Write("grAtlas_pp5_syst");
   grAtlas_pPb_stat->Write("grAtlas_pPb_stat");
   grAtlas_pp13_stat->Write("grAtlas_pp13_stat");
   grAtlas_pp5_stat->Write("grAtlas_pp5_stat");

   hist_pPb_systErrs->Write("hAtlas_pPb_syst");
   hist_pp13_systErrs->Write("hAtlas_pp13_syst");
   hist_pp5_systErrs->Write("hAtlas_pp5_syst");
   UniqueName6__12->Write("hAtlas_pPb_stat");
   UniqueName7__13->Write("hAtlas_pp13_stat");
   UniqueName8__14->Write("hAtlas_pp5_stat");




   TLegend *leg = new TLegend(0.44,0.18,0.77,0.42,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("UniqueName9","#it{p}+Pb #sqrt{s_{NN}}=5.02 TeV, 28 nb^{-1}_{ }","EP");

   ci = TColor::GetColor("#9999ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(11);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(25);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("UniqueName10","#it{pp} #sqrt{s}=13 TeV, 64 nb^{-1}_{ }","EP");

   ci = TColor::GetColor("#999999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(9);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("UniqueName11","#it{pp} #sqrt{s}=5.02 TeV, 170 nb^{-1}_{ }","EP");

   ci = TColor::GetColor("#cc6666");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(7);
   entry->SetMarkerColor(2);
   entry->SetMarkerStyle(24);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   leg->Draw();
   TLatex *   tex = new TLatex(0.5,0.88,"ATLAS");
tex->SetNDC();
   tex->SetTextFont(73);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.64,0.88,"");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.5,0.83,"Template Fits");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19,0.88,"1<p_{T}^{a,b}<5 GeV");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
      tex = new TLatex(0.19,0.82,"2<|#Delta#eta|<5");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
   Fig18a->Modified();
   Fig18a->cd();
   Fig18a->SetSelected(Fig18a);


}


