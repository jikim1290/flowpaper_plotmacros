{
 TFile* fin = new TFile("Final_Items.root","read");

 TH1D* hNyStat = (TH1D*)fin->Get("NearJet_stat");
 TH1D* hAyStat = (TH1D*)fin->Get("AwayJet_stat");
 TH1D* hRStat = (TH1D*)fin->Get("Acceptance_stat");

 TH1D* hNySyst = (TH1D*)fin->Get("NearJet_syst");
 TH1D* hAySyst = (TH1D*)fin->Get("AwayJet_syst");
 TH1D* hRSyst = (TH1D*)fin->Get("Acceptance_syst");

 ofstream file("data3.yaml");
 
 file << "independent_variables:" << endl;
 file << "- header: {name: 'Multiplicity percentile'}" << endl;
 file << "  values:" << endl;
 file << "  - {low: 0, high: 1}" << endl;
 file << "  - {low: 1, high: 2}" << endl;
 file << "  - {low: 2, high: 3}" << endl;
 file << "  - {low: 3, high: 4}" << endl;

// file << "  - {low: \"0-0.1%\", high: \"0-0.1%\", text: \"0.5\"}" << endl;
// file << "  - {low: \"1-5%\", high: \"1-5%\", text: \"1.5\"}" << endl;
// file << "  - {low: \"5-20%\", high: \"5-20%\", text: \"2.5\"}" << endl;
// file << "  - {low: \"20-60%\", high: \"20-60%\", text: \"3.5\"}" << endl;


 file << "dependent_variables:" << endl;
 file << "- header: {name: '$Y_\\mathrm{frag}^\\mathrm{near}$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file << "  values:" << endl; 
 for(int i=0;i<hNyStat->GetNbinsX();i++){
 file << "  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hNyStat->GetBinError(i+1)) << endl;
 file << Form("    - {label: sys, symerror: %f}",hNySyst->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hNyStat->GetBinContent(i+1)) << endl;
 }


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



}
