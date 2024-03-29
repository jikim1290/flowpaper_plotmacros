void Fig18b()
{
//=========Macro generated from canvas: Fig18b/Fig18b
//=========  (Tue Jun 30 01:37:38 2020) by ROOT version 6.14/04
   TCanvas *Fig18b = new TCanvas("Fig18b", "Fig18b",960,530,600,450);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
	 gStyle->SetErrorX(0.0001);
   Fig18b->Range(-43.37349,-0.01074683,318.0723,0.06267089);
   Fig18b->SetFillColor(0);
   Fig18b->SetBorderMode(0);
   Fig18b->SetBorderSize(2);
   Fig18b->SetTickx(1);
   Fig18b->SetTicky(1);
   Fig18b->SetLeftMargin(0.12);
   Fig18b->SetRightMargin(0.05);
   Fig18b->SetTopMargin(0.05);
   Fig18b->SetBottomMargin(0.16);
   Fig18b->SetFrameBorderMode(0);
   Fig18b->SetFrameBorderMode(0);
   
   Double_t xAxis21[17] = {0, 10, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
   TH1D *hist_pPb_systErrs = new TH1D("hist_pPb_systErrs","",16, xAxis21);
   hist_pPb_systErrs->SetBinContent(3,0.02261987);
   hist_pPb_systErrs->SetBinContent(4,0.03141965);
   hist_pPb_systErrs->SetBinContent(5,0.03492036);
   hist_pPb_systErrs->SetBinContent(6,0.03598424);
   hist_pPb_systErrs->SetBinContent(7,0.03773548);
   hist_pPb_systErrs->SetBinContent(8,0.03937805);
   hist_pPb_systErrs->SetBinContent(9,0.04232896);
   hist_pPb_systErrs->SetBinContent(10,0.04456139);
   hist_pPb_systErrs->SetBinContent(11,0.04475294);
   hist_pPb_systErrs->SetBinContent(12,0.04610954);
   hist_pPb_systErrs->SetBinContent(13,0.04752708);
   hist_pPb_systErrs->SetBinContent(14,0.04798247);
   hist_pPb_systErrs->SetBinContent(15,0.04865798);
   hist_pPb_systErrs->SetBinContent(16,0.04860191);
   hist_pPb_systErrs->SetBinError(3,0.005891567);
   hist_pPb_systErrs->SetBinError(4,0.001746285);
   hist_pPb_systErrs->SetBinError(5,0.001855761);
   hist_pPb_systErrs->SetBinError(6,0.001836526);
   hist_pPb_systErrs->SetBinError(7,0.001848828);
   hist_pPb_systErrs->SetBinError(8,0.001853906);
   hist_pPb_systErrs->SetBinError(9,0.001915388);
   hist_pPb_systErrs->SetBinError(10,0.001942909);
   hist_pPb_systErrs->SetBinError(11,0.001886832);
   hist_pPb_systErrs->SetBinError(12,0.001883968);
   hist_pPb_systErrs->SetBinError(13,0.001888722);
   hist_pPb_systErrs->SetBinError(14,0.001863661);
   hist_pPb_systErrs->SetBinError(15,0.001889255);
   hist_pPb_systErrs->SetBinError(16,0.00188713);
   hist_pPb_systErrs->SetMinimum(0.001);
   hist_pPb_systErrs->SetMaximum(0.059);
   hist_pPb_systErrs->SetEntries(14);
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
   hist_pPb_systErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
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
   Double_t xAxis22[7] = {20, 40, 60, 80, 100, 120, 140}; 
   
   TH1D *hist_pp13_systErrs = new TH1D("hist_pp13_systErrs","",6, xAxis22);
   hist_pp13_systErrs->SetBinContent(1,0.01934423);
   hist_pp13_systErrs->SetBinContent(2,0.02317042);
   hist_pp13_systErrs->SetBinContent(3,0.02517097);
   hist_pp13_systErrs->SetBinContent(4,0.02346417);
   hist_pp13_systErrs->SetBinContent(5,0.02483431);
   hist_pp13_systErrs->SetBinContent(6,0.02465277);
   hist_pp13_systErrs->SetBinError(1,0.003525341);
   hist_pp13_systErrs->SetBinError(2,0.002996882);
   hist_pp13_systErrs->SetBinError(3,0.002333644);
   hist_pp13_systErrs->SetBinError(4,0.001653011);
   hist_pp13_systErrs->SetBinError(5,0.001450958);
   hist_pp13_systErrs->SetBinError(6,0.001443654);
   hist_pp13_systErrs->SetMinimum(0.001);
   hist_pp13_systErrs->SetMaximum(0.059);
   hist_pp13_systErrs->SetEntries(6);
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
   hist_pp13_systErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
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
   Double_t xAxis23[6] = {20, 40, 60, 80, 100, 120}; 
   
   TH1D *hist_pp5_systErrs = new TH1D("hist_pp5_systErrs","",5, xAxis23);
   hist_pp5_systErrs->SetBinContent(1,0.01856369);
   hist_pp5_systErrs->SetBinContent(2,0.02507858);
   hist_pp5_systErrs->SetBinContent(3,0.02207691);
   hist_pp5_systErrs->SetBinContent(4,0.02453423);
   hist_pp5_systErrs->SetBinContent(5,0.0189351);
   hist_pp5_systErrs->SetBinError(1,0.00539177);
   hist_pp5_systErrs->SetBinError(2,0.001658807);
   hist_pp5_systErrs->SetBinError(3,0.00156291);
   hist_pp5_systErrs->SetBinError(4,0.00168585);
   hist_pp5_systErrs->SetBinError(5,0.001432891);
   hist_pp5_systErrs->SetMinimum(0.001);
   hist_pp5_systErrs->SetMaximum(0.059);
   hist_pp5_systErrs->SetEntries(5);
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
   hist_pp5_systErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
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
   Double_t xAxis24[17] = {0, 10, 20, 40, 60, 80, 100, 120, 140, 160, 180, 200, 220, 240, 260, 280, 300}; 
   
   TH1D *hist_pPb_statErrs = new TH1D("hist_pPb_statErrs","",16, xAxis24);
   hist_pPb_statErrs->SetBinContent(3,0.02261987);
   hist_pPb_statErrs->SetBinContent(4,0.03141965);
   hist_pPb_statErrs->SetBinContent(5,0.03492036);
   hist_pPb_statErrs->SetBinContent(6,0.03598424);
   hist_pPb_statErrs->SetBinContent(7,0.03773548);
   hist_pPb_statErrs->SetBinContent(8,0.03937805);
   hist_pPb_statErrs->SetBinContent(9,0.04232896);
   hist_pPb_statErrs->SetBinContent(10,0.04456139);
   hist_pPb_statErrs->SetBinContent(11,0.04475294);
   hist_pPb_statErrs->SetBinContent(12,0.04610954);
   hist_pPb_statErrs->SetBinContent(13,0.04752708);
   hist_pPb_statErrs->SetBinContent(14,0.04798247);
   hist_pPb_statErrs->SetBinContent(15,0.04865798);
   hist_pPb_statErrs->SetBinContent(16,0.04860191);
   hist_pPb_statErrs->SetBinError(3,0.003773505);
   hist_pPb_statErrs->SetBinError(4,0.001187328);
   hist_pPb_statErrs->SetBinError(5,0.0007338189);
   hist_pPb_statErrs->SetBinError(6,0.0005964749);
   hist_pPb_statErrs->SetBinError(7,0.0004805773);
   hist_pPb_statErrs->SetBinError(8,0.000444565);
   hist_pPb_statErrs->SetBinError(9,0.0003159977);
   hist_pPb_statErrs->SetBinError(10,0.0003010146);
   hist_pPb_statErrs->SetBinError(11,0.0003348179);
   hist_pPb_statErrs->SetBinError(12,0.000292372);
   hist_pPb_statErrs->SetBinError(13,0.0002415888);
   hist_pPb_statErrs->SetBinError(14,0.0003456622);
   hist_pPb_statErrs->SetBinError(15,0.0006597526);
   hist_pPb_statErrs->SetBinError(16,0.001400229);
   hist_pPb_statErrs->SetMinimum(0.001);
   hist_pPb_statErrs->SetMaximum(0.059);
   hist_pPb_statErrs->SetEntries(14);
   hist_pPb_statErrs->SetStats(0);
   hist_pPb_statErrs->SetLineColor(4);
   hist_pPb_statErrs->SetLineWidth(2);
   hist_pPb_statErrs->SetMarkerColor(4);
   hist_pPb_statErrs->SetMarkerStyle(25);
   hist_pPb_statErrs->SetMarkerSize(1.2);
   hist_pPb_statErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pPb_statErrs->GetXaxis()->SetLabelFont(42);
   hist_pPb_statErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pPb_statErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pPb_statErrs->GetXaxis()->SetTitleFont(42);
   hist_pPb_statErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   hist_pPb_statErrs->GetYaxis()->SetNdivisions(505);
   hist_pPb_statErrs->GetYaxis()->SetLabelFont(42);
   hist_pPb_statErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pPb_statErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pPb_statErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pPb_statErrs->GetYaxis()->SetTitleFont(42);
   hist_pPb_statErrs->GetZaxis()->SetLabelFont(42);
   hist_pPb_statErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pPb_statErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pPb_statErrs->GetZaxis()->SetTitleFont(42);
   hist_pPb_statErrs->Draw("same");
   Double_t xAxis25[7] = {20, 40, 60, 80, 100, 120, 140}; 
   
   TH1D *hist_pp13_statErrs = new TH1D("hist_pp13_statErrs","",6, xAxis25);
   hist_pp13_statErrs->SetBinContent(1,0.01934423);
   hist_pp13_statErrs->SetBinContent(2,0.02317042);
   hist_pp13_statErrs->SetBinContent(3,0.02517097);
   hist_pp13_statErrs->SetBinContent(4,0.02346417);
   hist_pp13_statErrs->SetBinContent(5,0.02483431);
   hist_pp13_statErrs->SetBinContent(6,0.02465277);
   hist_pp13_statErrs->SetBinError(1,0.002841054);
   hist_pp13_statErrs->SetBinError(2,0.001333881);
   hist_pp13_statErrs->SetBinError(3,0.0007430259);
   hist_pp13_statErrs->SetBinError(4,0.0007459689);
   hist_pp13_statErrs->SetBinError(5,0.0008004792);
   hist_pp13_statErrs->SetBinError(6,0.00155423);
   hist_pp13_statErrs->SetMinimum(0.001);
   hist_pp13_statErrs->SetMaximum(0.059);
   hist_pp13_statErrs->SetEntries(6);
   hist_pp13_statErrs->SetStats(0);
   hist_pp13_statErrs->SetLineWidth(2);
   hist_pp13_statErrs->SetMarkerStyle(20);
   hist_pp13_statErrs->SetMarkerSize(1.2);
   hist_pp13_statErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pp13_statErrs->GetXaxis()->SetLabelFont(42);
   hist_pp13_statErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pp13_statErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pp13_statErrs->GetXaxis()->SetTitleFont(42);
   hist_pp13_statErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   hist_pp13_statErrs->GetYaxis()->SetNdivisions(505);
   hist_pp13_statErrs->GetYaxis()->SetLabelFont(42);
   hist_pp13_statErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pp13_statErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pp13_statErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pp13_statErrs->GetYaxis()->SetTitleFont(42);
   hist_pp13_statErrs->GetZaxis()->SetLabelFont(42);
   hist_pp13_statErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pp13_statErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pp13_statErrs->GetZaxis()->SetTitleFont(42);
   hist_pp13_statErrs->Draw("same");
   Double_t xAxis26[6] = {20, 40, 60, 80, 100, 120}; 
   
   TH1D *hist_pp5_statErrs = new TH1D("hist_pp5_statErrs","",5, xAxis26);
   hist_pp5_statErrs->SetBinContent(1,0.01856369);
   hist_pp5_statErrs->SetBinContent(2,0.02507858);
   hist_pp5_statErrs->SetBinContent(3,0.02207691);
   hist_pp5_statErrs->SetBinContent(4,0.02453423);
   hist_pp5_statErrs->SetBinContent(5,0.0189351);
   hist_pp5_statErrs->SetBinError(1,0.01352972);
   hist_pp5_statErrs->SetBinError(2,0.005685134);
   hist_pp5_statErrs->SetBinError(3,0.001883328);
   hist_pp5_statErrs->SetBinError(4,0.001714014);
   hist_pp5_statErrs->SetBinError(5,0.003696581);
   hist_pp5_statErrs->SetMinimum(0.001);
   hist_pp5_statErrs->SetMaximum(0.059);
   hist_pp5_statErrs->SetEntries(5);
   hist_pp5_statErrs->SetStats(0);
   hist_pp5_statErrs->SetLineColor(2);
   hist_pp5_statErrs->SetLineWidth(2);
   hist_pp5_statErrs->SetMarkerColor(2);
   hist_pp5_statErrs->SetMarkerStyle(24);
   hist_pp5_statErrs->SetMarkerSize(1.2);
   hist_pp5_statErrs->GetXaxis()->SetTitle("N_{ch}^{rec}");
   hist_pp5_statErrs->GetXaxis()->SetLabelFont(42);
   hist_pp5_statErrs->GetXaxis()->SetLabelSize(0.05);
   hist_pp5_statErrs->GetXaxis()->SetTitleSize(0.06);
   hist_pp5_statErrs->GetXaxis()->SetTitleFont(42);
   hist_pp5_statErrs->GetYaxis()->SetTitle("v_{3}(p_{T}^{a})");
   hist_pp5_statErrs->GetYaxis()->SetNdivisions(505);
   hist_pp5_statErrs->GetYaxis()->SetLabelFont(42);
   hist_pp5_statErrs->GetYaxis()->SetLabelSize(0.05);
   hist_pp5_statErrs->GetYaxis()->SetTitleSize(0.06);
   hist_pp5_statErrs->GetYaxis()->SetTitleOffset(0.97);
   hist_pp5_statErrs->GetYaxis()->SetTitleFont(42);
   hist_pp5_statErrs->GetZaxis()->SetLabelFont(42);
   hist_pp5_statErrs->GetZaxis()->SetLabelSize(0.05);
   hist_pp5_statErrs->GetZaxis()->SetTitleSize(0.05);
   hist_pp5_statErrs->GetZaxis()->SetTitleFont(42);
   hist_pp5_statErrs->Draw("same");
   
   TLegend *leg = new TLegend(0.44,0.18,0.77,0.42,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextSize(0.045);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(0);
   TLegendEntry *entry=leg->AddEntry("UniqueName20","#it{p}+Pb #sqrt{s_{NN}}=5.02 TeV, 28 nb^{-1}_{ }","EP");

   ci = TColor::GetColor("#9999ff");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(11);
   entry->SetMarkerColor(4);
   entry->SetMarkerStyle(25);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("UniqueName21","#it{pp} #sqrt{s}=13 TeV, 64 nb^{-1}_{ }","EP");

   ci = TColor::GetColor("#999999");
   entry->SetLineColor(ci);
   entry->SetLineStyle(1);
   entry->SetLineWidth(9);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(20);
   entry->SetMarkerSize(1.2);
   entry->SetTextFont(42);
   entry=leg->AddEntry("UniqueName22","#it{pp} #sqrt{s}=5.02 TeV, 170 nb^{-1}_{ }","EP");

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
   Fig18b->Modified();
   Fig18b->cd();
   Fig18b->SetSelected(Fig18b);
}
