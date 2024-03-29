void fig16a()
{
   TCanvas *can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1 = new TCanvas("can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1", "can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1",0,0,600,450);
   gStyle->SetOptStat(0);
   gStyle->SetOptTitle(0);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->Range(-1.445783,-0.04132911,10.60241,0.2232278);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFillColor(0);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBorderMode(0);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBorderSize(2);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTickx(1);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTicky(1);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetLeftMargin(0.12);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetRightMargin(0.05);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetTopMargin(0.05);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetBottomMargin(0.16);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFrameBorderMode(0);
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetFrameBorderMode(0);
   
   TH1D *UniqueName41 = new TH1D("UniqueName41","",100,0,10);
   UniqueName41->SetMinimum(0.001);
   UniqueName41->SetMaximum(0.21);
   UniqueName41->SetStats(0);
   UniqueName41->SetLineColor(0);
   UniqueName41->SetLineWidth(2);
   UniqueName41->SetMarkerStyle(20);
   UniqueName41->SetMarkerSize(1.2);
   UniqueName41->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName41->GetXaxis()->SetNdivisions(505);
   UniqueName41->GetXaxis()->SetLabelFont(42);
   UniqueName41->GetXaxis()->SetLabelSize(0.05);
   UniqueName41->GetXaxis()->SetTitleSize(0.06);
   UniqueName41->GetXaxis()->SetTitleFont(42);
   UniqueName41->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName41->GetYaxis()->SetNdivisions(505);
   UniqueName41->GetYaxis()->SetLabelFont(42);
   UniqueName41->GetYaxis()->SetLabelSize(0.05);
   UniqueName41->GetYaxis()->SetTitleSize(0.06);
   UniqueName41->GetYaxis()->SetTitleOffset(0.97);
   UniqueName41->GetYaxis()->SetTitleFont(42);
   UniqueName41->GetZaxis()->SetLabelFont(42);
   UniqueName41->GetZaxis()->SetLabelSize(0.05);
   UniqueName41->GetZaxis()->SetTitleSize(0.05);
   UniqueName41->GetZaxis()->SetTitleFont(42);
   UniqueName41->Draw("");
   Double_t xAxis1[23] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 4.5, 5, 5.5, 6, 8, 10}; 
   
   TH1D *UniqueName52 = new TH1D("UniqueName52","",22, xAxis1);
   UniqueName52->SetBinContent(1,0.03548429);
   UniqueName52->SetBinContent(2,0.03872465);
   UniqueName52->SetBinContent(3,0.04556626);
   UniqueName52->SetBinContent(4,0.05362166);
   UniqueName52->SetBinContent(5,0.06135918);
   UniqueName52->SetBinContent(6,0.06675533);
   UniqueName52->SetBinContent(7,0.07395943);
   UniqueName52->SetBinContent(8,0.07758265);
   UniqueName52->SetBinContent(9,0.08093514);
   UniqueName52->SetBinContent(10,0.08888899);
   UniqueName52->SetBinContent(11,0.08725879);
   UniqueName52->SetBinContent(12,0.09070411);
   UniqueName52->SetBinContent(13,0.09122941);
   UniqueName52->SetBinContent(14,0.09063897);
   UniqueName52->SetBinContent(15,0.08915764);
   UniqueName52->SetBinContent(16,0.08508763);
   UniqueName52->SetBinContent(17,0.08129061);
   UniqueName52->SetBinContent(18,0.07360504);
   UniqueName52->SetBinContent(19,0.05122279);
   UniqueName52->SetBinContent(20,0.0379115);
   UniqueName52->SetBinContent(21,0.01828774);
   UniqueName52->SetBinContent(22,-0.04786495);
   UniqueName52->SetBinError(1,0.001700713);
   UniqueName52->SetBinError(2,0.001670529);
   UniqueName52->SetBinError(3,0.001695895);
   UniqueName52->SetBinError(4,0.001865186);
   UniqueName52->SetBinError(5,0.002128261);
   UniqueName52->SetBinError(6,0.002393408);
   UniqueName52->SetBinError(7,0.002754421);
   UniqueName52->SetBinError(8,0.003032748);
   UniqueName52->SetBinError(9,0.003321065);
   UniqueName52->SetBinError(10,0.003815324);
   UniqueName52->SetBinError(11,0.003935066);
   UniqueName52->SetBinError(12,0.004279537);
   UniqueName52->SetBinError(13,0.004501471);
   UniqueName52->SetBinError(14,0.004671005);
   UniqueName52->SetBinError(15,0.009036403);
   UniqueName52->SetBinError(16,0.008627443);
   UniqueName52->SetBinError(17,0.008246428);
   UniqueName52->SetBinError(18,0.007477304);
   UniqueName52->SetBinError(19,0.005275974);
   UniqueName52->SetBinError(20,0.004064031);
   UniqueName52->SetBinError(21,0.007844578);
   UniqueName52->SetBinError(22,0.04788234);
   UniqueName52->SetMinimum(0);
   UniqueName52->SetMaximum(0.1740981);
   UniqueName52->SetEntries(22);
   UniqueName52->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#999999");
   UniqueName52->SetLineColor(ci);
   UniqueName52->SetLineWidth(9);
   UniqueName52->SetMarkerStyle(20);
   UniqueName52->SetMarkerSize(1.2);
   UniqueName52->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName52->GetXaxis()->SetNdivisions(505);
   UniqueName52->GetXaxis()->SetLabelFont(42);
   UniqueName52->GetXaxis()->SetLabelSize(0.05);
   UniqueName52->GetXaxis()->SetTitleSize(0.06);
   UniqueName52->GetXaxis()->SetTitleFont(42);
   UniqueName52->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName52->GetYaxis()->SetNdivisions(505);
   UniqueName52->GetYaxis()->SetLabelFont(42);
   UniqueName52->GetYaxis()->SetLabelSize(0.05);
   UniqueName52->GetYaxis()->SetTitleSize(0.06);
   UniqueName52->GetYaxis()->SetTitleOffset(0.97);
   UniqueName52->GetYaxis()->SetTitleFont(42);
   UniqueName52->GetZaxis()->SetLabelFont(42);
   UniqueName52->GetZaxis()->SetLabelSize(0.05);
   UniqueName52->GetZaxis()->SetTitleSize(0.05);
   UniqueName52->GetZaxis()->SetTitleFont(42);
   UniqueName52->Draw("same"); // pp 13 TeV
   Double_t xAxis2[20] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 6, 8, 10}; 
   
   TH1D *UniqueName73 = new TH1D("UniqueName73","",19, xAxis2);
   UniqueName73->SetBinContent(1,0.035112);
   UniqueName73->SetBinContent(2,0.03877817);
   UniqueName73->SetBinContent(3,0.04491069);
   UniqueName73->SetBinContent(4,0.05374743);
   UniqueName73->SetBinContent(5,0.06181347);
   UniqueName73->SetBinContent(6,0.06485594);
   UniqueName73->SetBinContent(7,0.07139113);
   UniqueName73->SetBinContent(8,0.07711334);
   UniqueName73->SetBinContent(9,0.07760299);
   UniqueName73->SetBinContent(10,0.07973239);
   UniqueName73->SetBinContent(11,0.08440386);
   UniqueName73->SetBinContent(12,0.09069191);
   UniqueName73->SetBinContent(13,0.08176174);
   UniqueName73->SetBinContent(14,0.0813585);
   UniqueName73->SetBinContent(15,0.07468065);
   UniqueName73->SetBinContent(16,0.08888725);
   UniqueName73->SetBinContent(17,0.05255584);
   UniqueName73->SetBinContent(18,-0.01745607);
   UniqueName73->SetBinContent(19,-0.1089296);
   UniqueName73->SetBinError(1,0.002307686);
   UniqueName73->SetBinError(2,0.002376976);
   UniqueName73->SetBinError(3,0.002558627);
   UniqueName73->SetBinError(4,0.002903312);
   UniqueName73->SetBinError(5,0.003261725);
   UniqueName73->SetBinError(6,0.003403072);
   UniqueName73->SetBinError(7,0.003713959);
   UniqueName73->SetBinError(8,0.003991905);
   UniqueName73->SetBinError(9,0.004015874);
   UniqueName73->SetBinError(10,0.004120396);
   UniqueName73->SetBinError(11,0.004351093);
   UniqueName73->SetBinError(12,0.004663975);
   UniqueName73->SetBinError(13,0.004220397);
   UniqueName73->SetBinError(14,0.004200499);
   UniqueName73->SetBinError(15,0.006799571);
   UniqueName73->SetBinError(16,0.008072564);
   UniqueName73->SetBinError(17,0.02630141);
   UniqueName73->SetBinError(18,0.009218327);
   UniqueName73->SetBinError(19,0.05447841);
   UniqueName73->SetMinimum(0);
   UniqueName73->SetMaximum(0.1740981);
   UniqueName73->SetEntries(19);
   UniqueName73->SetStats(0);

   ci = TColor::GetColor("#cc6666");
   UniqueName73->SetLineColor(ci);
   UniqueName73->SetLineWidth(7);
   UniqueName73->SetMarkerColor(2);
   UniqueName73->SetMarkerStyle(24);
   UniqueName73->SetMarkerSize(1.2);
   UniqueName73->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName73->GetXaxis()->SetNdivisions(505);
   UniqueName73->GetXaxis()->SetLabelFont(42);
   UniqueName73->GetXaxis()->SetLabelSize(0.05);
   UniqueName73->GetXaxis()->SetTitleSize(0.06);
   UniqueName73->GetXaxis()->SetTitleFont(42);
   UniqueName73->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName73->GetYaxis()->SetNdivisions(505);
   UniqueName73->GetYaxis()->SetLabelFont(42);
   UniqueName73->GetYaxis()->SetLabelSize(0.05);
   UniqueName73->GetYaxis()->SetTitleSize(0.06);
   UniqueName73->GetYaxis()->SetTitleOffset(0.97);
   UniqueName73->GetYaxis()->SetTitleFont(42);
   UniqueName73->GetZaxis()->SetLabelFont(42);
   UniqueName73->GetZaxis()->SetLabelSize(0.05);
   UniqueName73->GetZaxis()->SetTitleSize(0.05);
   UniqueName73->GetZaxis()->SetTitleFont(42);
   // UniqueName73->Draw("same"); // pp 5TeV
   Double_t xAxis3[23] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 4.5, 5, 5.5, 6, 8, 10}; 
   
   TH1D *UniqueName94 = new TH1D("UniqueName94","",22, xAxis3);
   UniqueName94->SetBinContent(1,0.04098818);
   UniqueName94->SetBinContent(2,0.04844597);
   UniqueName94->SetBinContent(3,0.05959152);
   UniqueName94->SetBinContent(4,0.07323024);
   UniqueName94->SetBinContent(5,0.08555458);
   UniqueName94->SetBinContent(6,0.0959482);
   UniqueName94->SetBinContent(7,0.1054505);
   UniqueName94->SetBinContent(8,0.1141026);
   UniqueName94->SetBinContent(9,0.1207105);
   UniqueName94->SetBinContent(10,0.126894);
   UniqueName94->SetBinContent(11,0.1290834);
   UniqueName94->SetBinContent(12,0.1363112);
   UniqueName94->SetBinContent(13,0.1392784);
   UniqueName94->SetBinContent(14,0.133885);
   UniqueName94->SetBinContent(15,0.1360228);
   UniqueName94->SetBinContent(16,0.1338799);
   UniqueName94->SetBinContent(17,0.1186786);
   UniqueName94->SetBinContent(18,0.1059697);
   UniqueName94->SetBinContent(19,0.1026556);
   UniqueName94->SetBinContent(20,0.08641908);
   UniqueName94->SetBinContent(21,0.05885198);
   UniqueName94->SetBinContent(22,0.01467718);
   UniqueName94->SetBinError(1,0.001264405);
   UniqueName94->SetBinError(2,0.001480835);
   UniqueName94->SetBinError(3,0.001811524);
   UniqueName94->SetBinError(4,0.002220758);
   UniqueName94->SetBinError(5,0.002592229);
   UniqueName94->SetBinError(6,0.002906059);
   UniqueName94->SetBinError(7,0.003193218);
   UniqueName94->SetBinError(8,0.003454805);
   UniqueName94->SetBinError(9,0.003654641);
   UniqueName94->SetBinError(10,0.003841676);
   UniqueName94->SetBinError(11,0.003907905);
   UniqueName94->SetBinError(12,0.004126561);
   UniqueName94->SetBinError(13,0.004216334);
   UniqueName94->SetBinError(14,0.004053159);
   UniqueName94->SetBinError(15,0.005119342);
   UniqueName94->SetBinError(16,0.005038726);
   UniqueName94->SetBinError(17,0.008734518);
   UniqueName94->SetBinError(18,0.007799371);
   UniqueName94->SetBinError(19,0.007555532);
   UniqueName94->SetBinError(20,0.006361034);
   UniqueName94->SetBinError(21,0.01184732);
   UniqueName94->SetBinError(22,0.0146968);
   UniqueName94->SetMinimum(0);
   UniqueName94->SetMaximum(0.1740981);
   UniqueName94->SetEntries(22);
   UniqueName94->SetStats(0);

   ci = TColor::GetColor("#9999ff");
   UniqueName94->SetLineColor(ci);
   UniqueName94->SetLineWidth(11);
   UniqueName94->SetMarkerColor(4);
   UniqueName94->SetMarkerStyle(25);
   UniqueName94->SetMarkerSize(1.2);
   UniqueName94->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName94->GetXaxis()->SetNdivisions(505);
   UniqueName94->GetXaxis()->SetLabelFont(42);
   UniqueName94->GetXaxis()->SetLabelSize(0.05);
   UniqueName94->GetXaxis()->SetTitleSize(0.06);
   UniqueName94->GetXaxis()->SetTitleFont(42);
   UniqueName94->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName94->GetYaxis()->SetNdivisions(505);
   UniqueName94->GetYaxis()->SetLabelFont(42);
   UniqueName94->GetYaxis()->SetLabelSize(0.05);
   UniqueName94->GetYaxis()->SetTitleSize(0.06);
   UniqueName94->GetYaxis()->SetTitleOffset(0.97);
   UniqueName94->GetYaxis()->SetTitleFont(42);
   UniqueName94->GetZaxis()->SetLabelFont(42);
   UniqueName94->GetZaxis()->SetLabelSize(0.05);
   UniqueName94->GetZaxis()->SetTitleSize(0.05);
   UniqueName94->GetZaxis()->SetTitleFont(42);
   UniqueName94->Draw("same");
   Double_t xAxis4[23] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 4.5, 5, 5.5, 6, 8, 10}; 
   
   TH1D *UniqueName05 = new TH1D("UniqueName05","",22, xAxis4);
   UniqueName05->SetBinContent(1,0.03548429);
   UniqueName05->SetBinContent(2,0.03872465);
   UniqueName05->SetBinContent(3,0.04556626);
   UniqueName05->SetBinContent(4,0.05362166);
   UniqueName05->SetBinContent(5,0.06135918);
   UniqueName05->SetBinContent(6,0.06675533);
   UniqueName05->SetBinContent(7,0.07395943);
   UniqueName05->SetBinContent(8,0.07758265);
   UniqueName05->SetBinContent(9,0.08093514);
   UniqueName05->SetBinContent(10,0.08888899);
   UniqueName05->SetBinContent(11,0.08725879);
   UniqueName05->SetBinContent(12,0.09070411);
   UniqueName05->SetBinContent(13,0.09122941);
   UniqueName05->SetBinContent(14,0.09063897);
   UniqueName05->SetBinContent(15,0.08915764);
   UniqueName05->SetBinContent(16,0.08508763);
   UniqueName05->SetBinContent(17,0.08129061);
   UniqueName05->SetBinContent(18,0.07360504);
   UniqueName05->SetBinContent(19,0.05122279);
   UniqueName05->SetBinContent(20,0.0379115);
   UniqueName05->SetBinContent(21,0.01828774);
   UniqueName05->SetBinContent(22,-0.04786495);
   UniqueName05->SetBinError(1,0.0003739776);
   UniqueName05->SetBinError(2,0.0004001137);
   UniqueName05->SetBinError(3,0.0003222784);
   UniqueName05->SetBinError(4,0.0003856531);
   UniqueName05->SetBinError(5,0.0004658943);
   UniqueName05->SetBinError(6,0.0005605777);
   UniqueName05->SetBinError(7,0.0006748861);
   UniqueName05->SetBinError(8,0.0008091929);
   UniqueName05->SetBinError(9,0.0009576837);
   UniqueName05->SetBinError(10,0.001136451);
   UniqueName05->SetBinError(11,0.001341205);
   UniqueName05->SetBinError(12,0.001576206);
   UniqueName05->SetBinError(13,0.001858737);
   UniqueName05->SetBinError(14,0.00213344);
   UniqueName05->SetBinError(15,0.001754749);
   UniqueName05->SetBinError(16,0.002452961);
   UniqueName05->SetBinError(17,0.003312394);
   UniqueName05->SetBinError(18,0.004447826);
   UniqueName05->SetBinError(19,0.005942248);
   UniqueName05->SetBinError(20,0.007566357);
   UniqueName05->SetBinError(21,0.006252355);
   UniqueName05->SetBinError(22,0.01373747);
   UniqueName05->SetMinimum(0);
   UniqueName05->SetMaximum(0.1740981);
   UniqueName05->SetEntries(22);
   UniqueName05->SetStats(0);
   UniqueName05->SetLineWidth(2);
   UniqueName05->SetMarkerStyle(20);
   UniqueName05->SetMarkerSize(1.2);
   UniqueName05->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName05->GetXaxis()->SetNdivisions(505);
   UniqueName05->GetXaxis()->SetLabelFont(42);
   UniqueName05->GetXaxis()->SetLabelSize(0.05);
   UniqueName05->GetXaxis()->SetTitleSize(0.06);
   UniqueName05->GetXaxis()->SetTitleFont(42);
   UniqueName05->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName05->GetYaxis()->SetNdivisions(505);
   UniqueName05->GetYaxis()->SetLabelFont(42);
   UniqueName05->GetYaxis()->SetLabelSize(0.05);
   UniqueName05->GetYaxis()->SetTitleSize(0.06);
   UniqueName05->GetYaxis()->SetTitleOffset(0.97);
   UniqueName05->GetYaxis()->SetTitleFont(42);
   UniqueName05->GetZaxis()->SetLabelFont(42);
   UniqueName05->GetZaxis()->SetLabelSize(0.05);
   UniqueName05->GetZaxis()->SetTitleSize(0.05);
   UniqueName05->GetZaxis()->SetTitleFont(42);
   //UniqueName05->Draw("same");
   Double_t xAxis5[20] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 6, 8, 10}; 
   
   TH1D *UniqueName16 = new TH1D("UniqueName16","",19, xAxis5);
   UniqueName16->SetBinContent(1,0.035112);
   UniqueName16->SetBinContent(2,0.03877817);
   UniqueName16->SetBinContent(3,0.04491069);
   UniqueName16->SetBinContent(4,0.05374743);
   UniqueName16->SetBinContent(5,0.06181347);
   UniqueName16->SetBinContent(6,0.06485594);
   UniqueName16->SetBinContent(7,0.07139113);
   UniqueName16->SetBinContent(8,0.07711334);
   UniqueName16->SetBinContent(9,0.07760299);
   UniqueName16->SetBinContent(10,0.07973239);
   UniqueName16->SetBinContent(11,0.08440386);
   UniqueName16->SetBinContent(12,0.09069191);
   UniqueName16->SetBinContent(13,0.08176174);
   UniqueName16->SetBinContent(14,0.0813585);
   UniqueName16->SetBinContent(15,0.07468065);
   UniqueName16->SetBinContent(16,0.08888725);
   UniqueName16->SetBinContent(17,0.05255584);
   UniqueName16->SetBinContent(18,-0.01745607);
   UniqueName16->SetBinContent(19,-0.1089296);
   UniqueName16->SetBinError(1,0.0008600678);
   UniqueName16->SetBinError(2,0.0009091502);
   UniqueName16->SetBinError(3,0.0007402156);
   UniqueName16->SetBinError(4,0.0009113217);
   UniqueName16->SetBinError(5,0.001127068);
   UniqueName16->SetBinError(6,0.001410726);
   UniqueName16->SetBinError(7,0.001742419);
   UniqueName16->SetBinError(8,0.00211105);
   UniqueName16->SetBinError(9,0.002617068);
   UniqueName16->SetBinError(10,0.003142268);
   UniqueName16->SetBinError(11,0.003759232);
   UniqueName16->SetBinError(12,0.004445781);
   UniqueName16->SetBinError(13,0.005292685);
   UniqueName16->SetBinError(14,0.006259009);
   UniqueName16->SetBinError(15,0.005376693);
   UniqueName16->SetBinError(16,0.007843223);
   UniqueName16->SetBinError(17,0.00760729);
   UniqueName16->SetBinError(18,0.02313698);
   UniqueName16->SetBinError(19,0.05290858);
   UniqueName16->SetMinimum(0);
   UniqueName16->SetMaximum(0.1740981);
   UniqueName16->SetEntries(19);
   UniqueName16->SetStats(0);
   UniqueName16->SetLineColor(2);
   UniqueName16->SetLineWidth(2);
   UniqueName16->SetMarkerColor(2);
   UniqueName16->SetMarkerStyle(24);
   UniqueName16->SetMarkerSize(1.2);
   UniqueName16->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName16->GetXaxis()->SetNdivisions(505);
   UniqueName16->GetXaxis()->SetLabelFont(42);
   UniqueName16->GetXaxis()->SetLabelSize(0.05);
   UniqueName16->GetXaxis()->SetTitleSize(0.06);
   UniqueName16->GetXaxis()->SetTitleFont(42);
   UniqueName16->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName16->GetYaxis()->SetNdivisions(505);
   UniqueName16->GetYaxis()->SetLabelFont(42);
   UniqueName16->GetYaxis()->SetLabelSize(0.05);
   UniqueName16->GetYaxis()->SetTitleSize(0.06);
   UniqueName16->GetYaxis()->SetTitleOffset(0.97);
   UniqueName16->GetYaxis()->SetTitleFont(42);
   UniqueName16->GetZaxis()->SetLabelFont(42);
   UniqueName16->GetZaxis()->SetLabelSize(0.05);
   UniqueName16->GetZaxis()->SetTitleSize(0.05);
   UniqueName16->GetZaxis()->SetTitleFont(42);
   //UniqueName16->Draw("same");
   Double_t xAxis6[23] = {0.4, 0.5, 0.6, 0.8, 1, 1.2, 1.4, 1.6, 1.8, 2, 2.2, 2.4, 2.6, 2.8, 3, 3.5, 4, 4.5, 5, 5.5, 6, 8, 10}; 
   
   TH1D *UniqueName27 = new TH1D("UniqueName27","",22, xAxis6);
   UniqueName27->SetBinContent(1,0.04098818);
   UniqueName27->SetBinContent(2,0.04844597);
   UniqueName27->SetBinContent(3,0.05959152);
   UniqueName27->SetBinContent(4,0.07323024);
   UniqueName27->SetBinContent(5,0.08555458);
   UniqueName27->SetBinContent(6,0.0959482);
   UniqueName27->SetBinContent(7,0.1054505);
   UniqueName27->SetBinContent(8,0.1141026);
   UniqueName27->SetBinContent(9,0.1207105);
   UniqueName27->SetBinContent(10,0.126894);
   UniqueName27->SetBinContent(11,0.1290834);
   UniqueName27->SetBinContent(12,0.1363112);
   UniqueName27->SetBinContent(13,0.1392784);
   UniqueName27->SetBinContent(14,0.133885);
   UniqueName27->SetBinContent(15,0.1360228);
   UniqueName27->SetBinContent(16,0.1338799);
   UniqueName27->SetBinContent(17,0.1186786);
   UniqueName27->SetBinContent(18,0.1059697);
   UniqueName27->SetBinContent(19,0.1026556);
   UniqueName27->SetBinContent(20,0.08641908);
   UniqueName27->SetBinContent(21,0.05885198);
   UniqueName27->SetBinContent(22,0.01467718);
   UniqueName27->SetBinError(1,0.0002283691);
   UniqueName27->SetBinError(2,0.0002460164);
   UniqueName27->SetBinError(3,0.0002029221);
   UniqueName27->SetBinError(4,0.0002504778);
   UniqueName27->SetBinError(5,0.0003096817);
   UniqueName27->SetBinError(6,0.0003836337);
   UniqueName27->SetBinError(7,0.000470383);
   UniqueName27->SetBinError(8,0.000576937);
   UniqueName27->SetBinError(9,0.0006928725);
   UniqueName27->SetBinError(10,0.0008358918);
   UniqueName27->SetBinError(11,0.001001154);
   UniqueName27->SetBinError(12,0.001204803);
   UniqueName27->SetBinError(13,0.001385958);
   UniqueName27->SetBinError(14,0.001696613);
   UniqueName27->SetBinError(15,0.001386863);
   UniqueName27->SetBinError(16,0.001960388);
   UniqueName27->SetBinError(17,0.002809126);
   UniqueName27->SetBinError(18,0.003768877);
   UniqueName27->SetBinError(19,0.004862221);
   UniqueName27->SetBinError(20,0.006417584);
   UniqueName27->SetBinError(21,0.005274594);
   UniqueName27->SetBinError(22,0.01215346);
   UniqueName27->SetMinimum(0);
   UniqueName27->SetMaximum(0.1740981);
   UniqueName27->SetEntries(22);
   UniqueName27->SetStats(0);
   UniqueName27->SetLineColor(4);
   UniqueName27->SetLineWidth(2);
   UniqueName27->SetMarkerColor(4);
   UniqueName27->SetMarkerStyle(25);
   UniqueName27->SetMarkerSize(1.2);
   UniqueName27->GetXaxis()->SetTitle("p_{T}^{a} [GeV]");
   UniqueName27->GetXaxis()->SetNdivisions(505);
   UniqueName27->GetXaxis()->SetLabelFont(42);
   UniqueName27->GetXaxis()->SetLabelSize(0.05);
   UniqueName27->GetXaxis()->SetTitleSize(0.06);
   UniqueName27->GetXaxis()->SetTitleFont(42);
   UniqueName27->GetYaxis()->SetTitle("v_{2}(p_{T}^{a})");
   UniqueName27->GetYaxis()->SetNdivisions(505);
   UniqueName27->GetYaxis()->SetLabelFont(42);
   UniqueName27->GetYaxis()->SetLabelSize(0.05);
   UniqueName27->GetYaxis()->SetTitleSize(0.06);
   UniqueName27->GetYaxis()->SetTitleOffset(0.97);
   UniqueName27->GetYaxis()->SetTitleFont(42);
   UniqueName27->GetZaxis()->SetLabelFont(42);
   UniqueName27->GetZaxis()->SetLabelSize(0.05);
   UniqueName27->GetZaxis()->SetTitleSize(0.05);
   UniqueName27->GetZaxis()->SetTitleFont(42);
   //UniqueName27->Draw("same");
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
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->Modified();
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->cd();
   can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1->SetSelected(can_v2_SystemCompare_ptadep_cent26_pericent31_ptb6_ch2_eta1_type1);

   // Write the results to ROOT file
   TFile *fout = new TFile("ATLAS-figure16a_v2ptdep_N60.root","recreate");
   fout->cd();
   TGraphAsymmErrors *grAtlas_pp13tev_ptdep_N60 =  new   TGraphAsymmErrors(UniqueName52);
   TGraphAsymmErrors *grAtlas_pPb5tev_ptdep_N60 =  new   TGraphAsymmErrors(UniqueName94);
   grAtlas_pp13tev_ptdep_N60->Write("grAtlas_pp13tev_ptdep_N60");
   grAtlas_pPb5tev_ptdep_N60->Write("grAtlas_pPb5tev_ptdep_N60");
   
   fout->Write();
   fout->Close();
}
