{
 TFile* fin = new TFile("dphi_extract.root","read");

 TH1D* hSig = (TH1D*)fin->Get("signal");
 TH1D* hLM = (TH1D*)fin->Get("fit");

 ofstream file("data2.yaml");
 

 file << "dependent_variables:" << endl;
 file << "- header: {name: '1/$N_{\\rm{trig}} \\mathrm{d}N^{\\mathrm{pair}}/\\mathrm{d}\\Delta\\varphi$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 0-0.1 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  values:" << endl; 
 for(int i=0;i<hSig->GetNbinsX();i++){
 file << "  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hSig->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hSig->GetBinContent(i+1)) << endl;
 }


 file << "- header: {name: '$F/N_{\\rm{trig}} \\mathrm{d}N^{\\mathrm{pair}}/\\mathrm{d}\\Delta\\varphi + G$'}" << endl;
 file << "  qualifiers:" << endl;
 file << "  - {name: FORWARD MULTIPLICITY CLASS, units: PCT, value: 60-100 }" << endl;
 file << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hSig->GetNbinsX();i++){
 file << "  - errors:" << endl;
 file << Form("    - {label: stat, symerror: %f}",hLM->GetBinError(i+1)) << endl;
 file << Form("    value: %f",hLM->GetBinContent(i+1)) << endl;
 }


 file << "independent_variables:" << endl;
 file << "- header: {name: '$\\Delta\\varphi$'}" << endl;
 file << "  values:" << endl;
 for(int i=0;i<hSig->GetNbinsX();i++){
 file << Form("  - {low: %f, high: %f}",hLM->GetBinCenter(i+1) - hLM->GetBinWidth(i+1)/2., hLM->GetBinCenter(i+1) + hLM->GetBinWidth(i+1)/2.) << endl;
 }
}
