{
 TFile* fin = new TFile("fout_vn_28jun2023.root","read");

 TH1D* hv2pp_stat = (TH1D*)fin->Get("v2_pt_stat");
 TH1D* hv2pp_syst = (TH1D*)fin->Get("v2_pt_syst");

 TH1D* hv3pp_stat = (TH1D*)fin->Get("v3_pt_stat");
 TH1D* hv3pp_syst = (TH1D*)fin->Get("v3_pt_syst");


 TH1D* hv2pPb_stat = (TH1D*)fin->Get("v2_v0a_stat_pt");
 TH1D* hv2pPb_syst = (TH1D*)fin->Get("v2_v0a_syst_pt");

 TH1D* hv3pPb_stat = (TH1D*)fin->Get("v3_v0a_stat_pt");
 TH1D* hv3pPb_syst = (TH1D*)fin->Get("v3_v0a_syst_pt");


 ofstream file("data4.yaml");
 
 file << "independent_variables:" << endl;
 file << "- header: {name: '$p_\\mathrm{T,trig}$', units: GeV/c}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hv2pp_stat->GetNbinsX();i++){
 file << Form("  - {low: %f, high: %f}",hv2pp_stat->GetBinCenter(i+1) - hv2pp_stat->GetBinWidth(i+1)/2., hv2pp_stat->GetBinCenter(i+1) + hv2pp_stat->GetBinWidth(i+1)/2.) << endl;
 }

 file << "dependent_variables:" << endl;

 file << "- header: {name: '$v_{2}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: reaction, value: P P}" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 0-0.1 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl; 
 for(int i=0;i<hv2pp_stat->GetNbinsX();i++){
 file <<"  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hv2pp_stat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hv2pp_syst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hv2pp_stat->GetBinContent(i+1)) << endl;
 }

 file << "- header: {name: '$v_{3}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: reaction, value: P P}" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 0-0.1 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hv2pp_stat->GetNbinsX();i++){
 file <<"  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hv3pp_stat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hv3pp_syst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hv3pp_stat->GetBinContent(i+1)) << endl;
 }


 file << "- header: {name: '$v_{2}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: reaction, value: P PB}" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 0-20 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hv2pp_stat->GetNbinsX();i++){
 file <<"  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hv2pPb_stat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hv2pPb_syst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hv2pPb_stat->GetBinContent(i+1)) << endl;
 }


 file << "- header: {name: '$v_{3}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: reaction, value: P PB}" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 0-20 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hv2pp_stat->GetNbinsX();i++){
 file <<"  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hv3pPb_stat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hv3pPb_syst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hv3pPb_stat->GetBinContent(i+1)) << endl;
 }


/*
 file << "- header: {name: '$Y_\\mathrm{frag}^\\mathrm{away}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl; 
 for(int i=0;i<hAyStat->GetNbinsX();i++){
 file << "  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hAyStat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hAySyst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hAyStat->GetBinContent(i+1)) << endl;
 }


 file << "- header: {name: '$Y_\\mathrm{frag}^\\mathrm{away}$/$Y_\\mathrm{frag}^\\mathrm{near}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hRStat->GetNbinsX();i++){
 file << "  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hRStat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hRSyst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hRStat->GetBinContent(i+1)) << endl;
 }


*/
}
