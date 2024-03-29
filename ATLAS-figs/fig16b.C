void fig16b()
{
   TCanvas *can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1 = new TCanvas("can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1", "can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1",0,0,600,450);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->Range(-1.156627,-0.02310126,8.481928,0.1275316);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFillColor(0);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBorderMode(0);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBorderSize(2);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTickx(1);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTicky(1);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetLeftMargin(0.12);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetRightMargin(0.05);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTopMargin(0.05);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBottomMargin(0.16);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFrameBorderMode(0);
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFrameBorderMode(0);
   
   TH1D *UniqueName1410 = new TH1D("UniqueName1410","",100,0,8);
   UniqueName1410->SetMinimum(0.001);
   UniqueName1410->SetMaximum(0.12);
   UniqueName1410->SetStats(0);
   UniqueName1410->SetLineColor(0);
   UniqueName1410->SetLineWidth(2);
   UniqueName1410->SetMarkerStyle(20);
   UniqueName1410->SetMarkerSize(1.2);
   UniqueName1410->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName1410->GetXaxis()->SetNdivisions(505);
   UniqueName1410->GetXaxis()->SetLabelFont(42);
   UniqueName1410->GetXaxis()->SetLabelSize(0.05);
   UniqueName1410->GetXaxis()->SetTitleSize(0.06);
   UniqueName1410->GetXaxis()->SetTitleFont(42);
   UniqueName1410->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   UniqueName1410->GetYaxis()->SetNdivisions(505);
   UniqueName1410->GetYaxis()->SetLabelFont(42);
   UniqueName1410->GetYaxis()->SetLabelSize(0.05);
   UniqueName1410->GetYaxis()->SetTitleSize(0.06);
   UniqueName1410->GetYaxis()->SetTitleOffset(0.97);
   UniqueName1410->GetYaxis()->SetTitleFont(42);
   UniqueName1410->GetZaxis()->SetLabelFont(42);
   UniqueName1410->GetZaxis()->SetLabelSize(0.05);
   UniqueName1410->GetZaxis()->SetTitleSize(0.05);
   UniqueName1410->GetZaxis()->SetTitleFont(42);
   UniqueName1410->Draw("");
   Double_t xAxis9[9] = {0.5, 1, 1.5, 2, 3, 4, 6, 8, 10}; 
   
   TH1D *UniqueName1511 = new TH1D("UniqueName1511","",8, xAxis9);
   UniqueName1511->SetBinContent(1,0.00983317);
   UniqueName1511->SetBinContent(2,0.02224674);
   UniqueName1511->SetBinContent(3,0.03207747);
   UniqueName1511->SetBinContent(4,0.04328478);
   UniqueName1511->SetBinContent(5,0.06092275);
   UniqueName1511->SetBinContent(6,0.07580533);
   UniqueName1511->SetBinContent(7,0.09662314);
   UniqueName1511->SetBinContent(8,0.2291813);
   UniqueName1511->SetBinError(1,0.002448585);
   UniqueName1511->SetBinError(2,0.004515495);
   UniqueName1511->SetBinError(3,0.006461061);
   UniqueName1511->SetBinError(4,0.008704257);
   UniqueName1511->SetBinError(5,0.01224469);
   UniqueName1511->SetBinError(6,0.0152343);
   UniqueName1511->SetBinError(7,0.01941707);
   UniqueName1511->SetBinError(8,0.04605426);
   UniqueName1511->SetMinimum(0);
   UniqueName1511->SetMaximum(1.503599);
   UniqueName1511->SetEntries(8);
   UniqueName1511->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#999999");
   UniqueName1511->SetLineColor(ci);
   UniqueName1511->SetLineWidth(9);
   UniqueName1511->SetMarkerStyle(20);
   UniqueName1511->SetMarkerSize(1.2);
   UniqueName1511->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName1511->GetXaxis()->SetNdivisions(505);
   UniqueName1511->GetXaxis()->SetLabelFont(42);
   UniqueName1511->GetXaxis()->SetLabelSize(0.05);
   UniqueName1511->GetXaxis()->SetTitleSize(0.06);
   UniqueName1511->GetXaxis()->SetTitleFont(42);
   UniqueName1511->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   UniqueName1511->GetYaxis()->SetNdivisions(505);
   UniqueName1511->GetYaxis()->SetLabelFont(42);
   UniqueName1511->GetYaxis()->SetLabelSize(0.05);
   UniqueName1511->GetYaxis()->SetTitleSize(0.06);
   UniqueName1511->GetYaxis()->SetTitleOffset(0.97);
   UniqueName1511->GetYaxis()->SetTitleFont(42);
   UniqueName1511->GetZaxis()->SetLabelFont(42);
   UniqueName1511->GetZaxis()->SetLabelSize(0.05);
   UniqueName1511->GetZaxis()->SetTitleSize(0.05);
   UniqueName1511->GetZaxis()->SetTitleFont(42);
   UniqueName1511->Draw("same");
   Double_t xAxis10[9] = {0.5, 1, 1.5, 2, 3, 4, 6, 8, 10}; 
   
   TH1D *UniqueName1812 = new TH1D("UniqueName1812","",8, xAxis10);
   UniqueName1812->SetBinContent(1,0.01823055);
   UniqueName1812->SetBinContent(2,0.03468592);
   UniqueName1812->SetBinContent(3,0.04932354);
   UniqueName1812->SetBinContent(4,0.06073529);
   UniqueName1812->SetBinContent(5,0.06297491);
   UniqueName1812->SetBinContent(6,0.07528334);
   UniqueName1812->SetBinContent(7,0.05893384);
   UniqueName1812->SetBinContent(8,0.07875739);
   UniqueName1812->SetBinError(1,0.0009420914);
   UniqueName1812->SetBinError(2,0.001485195);
   UniqueName1812->SetBinError(3,0.002081676);
   UniqueName1812->SetBinError(4,0.002556425);
   UniqueName1812->SetBinError(5,0.005369763);
   UniqueName1812->SetBinError(6,0.006417849);
   UniqueName1812->SetBinError(7,0.006145139);
   UniqueName1812->SetBinError(8,0.01592125);
   UniqueName1812->SetMinimum(0);
   UniqueName1812->SetMaximum(1.503599);
   UniqueName1812->SetEntries(8);
   UniqueName1812->SetStats(0);

   ci = TColor::GetColor("#9999ff");
   UniqueName1812->SetLineColor(ci);
   UniqueName1812->SetLineWidth(11);
   UniqueName1812->SetMarkerColor(4);
   UniqueName1812->SetMarkerStyle(25);
   UniqueName1812->SetMarkerSize(1.2);
   UniqueName1812->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName1812->GetXaxis()->SetNdivisions(505);
   UniqueName1812->GetXaxis()->SetLabelFont(42);
   UniqueName1812->GetXaxis()->SetLabelSize(0.05);
   UniqueName1812->GetXaxis()->SetTitleSize(0.06);
   UniqueName1812->GetXaxis()->SetTitleFont(42);
   UniqueName1812->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   UniqueName1812->GetYaxis()->SetNdivisions(505);
   UniqueName1812->GetYaxis()->SetLabelFont(42);
   UniqueName1812->GetYaxis()->SetLabelSize(0.05);
   UniqueName1812->GetYaxis()->SetTitleSize(0.06);
   UniqueName1812->GetYaxis()->SetTitleOffset(0.97);
   UniqueName1812->GetYaxis()->SetTitleFont(42);
   UniqueName1812->GetZaxis()->SetLabelFont(42);
   UniqueName1812->GetZaxis()->SetLabelSize(0.05);
   UniqueName1812->GetZaxis()->SetTitleSize(0.05);
   UniqueName1812->GetZaxis()->SetTitleFont(42);
   UniqueName1812->Draw("same");
   Double_t xAxis11[9] = {0.5, 1, 1.5, 2, 3, 4, 6, 8, 10}; 
   
   TH1D *UniqueName1013 = new TH1D("UniqueName1013","",8, xAxis11);
   UniqueName1013->SetBinContent(1,0.00983317);
   UniqueName1013->SetBinContent(2,0.02224674);
   UniqueName1013->SetBinContent(3,0.03207747);
   UniqueName1013->SetBinContent(4,0.04328478);
   UniqueName1013->SetBinContent(5,0.06092275);
   UniqueName1013->SetBinContent(6,0.07580533);
   UniqueName1013->SetBinContent(7,0.09662314);
   UniqueName1013->SetBinContent(8,0.2291813);
   UniqueName1013->SetBinError(1,0.001086097);
   UniqueName1013->SetBinError(2,0.001799823);
   UniqueName1013->SetBinError(3,0.00280322);
   UniqueName1013->SetBinError(4,0.003621267);
   UniqueName1013->SetBinError(5,0.007346507);
   UniqueName1013->SetBinError(6,0.01179498);
   UniqueName1013->SetBinError(7,0.03089768);
   UniqueName1013->SetBinError(8,0.06775768);
   UniqueName1013->SetMinimum(0);
   UniqueName1013->SetMaximum(1.503599);
   UniqueName1013->SetEntries(8);
   UniqueName1013->SetStats(0);
   UniqueName1013->SetLineWidth(2);
   UniqueName1013->SetMarkerStyle(20);
   UniqueName1013->SetMarkerSize(1.2);
   UniqueName1013->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName1013->GetXaxis()->SetNdivisions(505);
   UniqueName1013->GetXaxis()->SetLabelFont(42);
   UniqueName1013->GetXaxis()->SetLabelSize(0.05);
   UniqueName1013->GetXaxis()->SetTitleSize(0.06);
   UniqueName1013->GetXaxis()->SetTitleFont(42);
   UniqueName1013->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   UniqueName1013->GetYaxis()->SetNdivisions(505);
   UniqueName1013->GetYaxis()->SetLabelFont(42);
   UniqueName1013->GetYaxis()->SetLabelSize(0.05);
   UniqueName1013->GetYaxis()->SetTitleSize(0.06);
   UniqueName1013->GetYaxis()->SetTitleOffset(0.97);
   UniqueName1013->GetYaxis()->SetTitleFont(42);
   UniqueName1013->GetZaxis()->SetLabelFont(42);
   UniqueName1013->GetZaxis()->SetLabelSize(0.05);
   UniqueName1013->GetZaxis()->SetTitleSize(0.05);
   UniqueName1013->GetZaxis()->SetTitleFont(42);
   UniqueName1013->Draw("same");
   Double_t xAxis12[9] = {0.5, 1, 1.5, 2, 3, 4, 6, 8, 10}; 
   
   TH1D *UniqueName1214 = new TH1D("UniqueName1214","",8, xAxis12);
   UniqueName1214->SetBinContent(1,0.01823055);
   UniqueName1214->SetBinContent(2,0.03468592);
   UniqueName1214->SetBinContent(3,0.04932354);
   UniqueName1214->SetBinContent(4,0.06073529);
   UniqueName1214->SetBinContent(5,0.06297491);
   UniqueName1214->SetBinContent(6,0.07528334);
   UniqueName1214->SetBinContent(7,0.05893384);
   UniqueName1214->SetBinContent(8,0.07875739);
   UniqueName1214->SetBinError(1,0.0003884615);
   UniqueName1214->SetBinError(2,0.0006649134);
   UniqueName1214->SetBinError(3,0.001099219);
   UniqueName1214->SetBinError(4,0.001478977);
   UniqueName1214->SetBinError(5,0.003257336);
   UniqueName1214->SetBinError(6,0.005587062);
   UniqueName1214->SetBinError(7,0.0150612);
   UniqueName1214->SetBinError(8,0.03453292);
   UniqueName1214->SetMinimum(0);
   UniqueName1214->SetMaximum(1.503599);
   UniqueName1214->SetEntries(8);
   UniqueName1214->SetStats(0);
   UniqueName1214->SetLineColor(4);
   UniqueName1214->SetLineWidth(2);
   UniqueName1214->SetMarkerColor(4);
   UniqueName1214->SetMarkerStyle(25);
   UniqueName1214->SetMarkerSize(1.2);
   UniqueName1214->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName1214->GetXaxis()->SetNdivisions(505);
   UniqueName1214->GetXaxis()->SetLabelFont(42);
   UniqueName1214->GetXaxis()->SetLabelSize(0.05);
   UniqueName1214->GetXaxis()->SetTitleSize(0.06);
   UniqueName1214->GetXaxis()->SetTitleFont(42);
   UniqueName1214->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   UniqueName1214->GetYaxis()->SetNdivisions(505);
   UniqueName1214->GetYaxis()->SetLabelFont(42);
   UniqueName1214->GetYaxis()->SetLabelSize(0.05);
   UniqueName1214->GetYaxis()->SetTitleSize(0.06);
   UniqueName1214->GetYaxis()->SetTitleOffset(0.97);
   UniqueName1214->GetYaxis()->SetTitleFont(42);
   UniqueName1214->GetZaxis()->SetLabelFont(42);
   UniqueName1214->GetZaxis()->SetLabelSize(0.05);
   UniqueName1214->GetZaxis()->SetTitleSize(0.05);
   UniqueName1214->GetZaxis()->SetTitleFont(42);
   UniqueName1214->Draw("same");
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
      tex = new TLatex(0.19,0.88,"0.5<p_{T}^{b}<5 GeV");
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
      tex = new TLatex(0.19,0.76,"N_{ ch}^{ rec}#geq60");
tex->SetNDC();
   tex->SetTextFont(43);
   tex->SetTextSize(20);
   tex->SetLineWidth(2);
   tex->Draw();
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->Modified();
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->cd();
   can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetSelected(can_v3_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1);
}
