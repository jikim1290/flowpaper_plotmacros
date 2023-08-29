{
 TFile* fin = new TFile("fout_vn_28jun2023.root","read");

 TH1D* hv2lp_stat = (TH1D*)fin->Get("v2_lp_stat");
 TH1D* hv2lp_syst = (TH1D*)fin->Get("v2_lp_syst");

 TH1D* hv2lp14_stat = (TH1D*)fin->Get("hv2_LP_1_4_stat");
 TH1D* hv2lp14_syst = (TH1D*)fin->Get("hv2_LP_1_4_syst");


 TH1D* hv3lp_stat = (TH1D*)fin->Get("v3_lp_stat");
 TH1D* hv3lp_syst = (TH1D*)fin->Get("v3_lp_syst");

 TH1D* hv3lp14_stat = (TH1D*)fin->Get("hv3_LP_1_4_stat");
 TH1D* hv3lp14_syst = (TH1D*)fin->Get("hv3_LP_1_4_syst");


 TH1D* hv2jet_stat = (TH1D*)fin->Get("v2_jet_stat");
 TH1D* hv2jet_syst = (TH1D*)fin->Get("v2_jet_syst");

 TH1D* hv2jet14_stat = (TH1D*)fin->Get("hv2_jet_1_4_stat");
 TH1D* hv2jet14_syst = (TH1D*)fin->Get("hv2_jet_1_4_syst"); 


 TH1D* hv3jet_stat = (TH1D*)fin->Get("v3_jet_stat");
 TH1D* hv3jet_syst = (TH1D*)fin->Get("v3_jet_syst");

 TH1D* hv3jet14_stat = (TH1D*)fin->Get("hv3_jet_1_4_stat");
 TH1D* hv3jet14_syst = (TH1D*)fin->Get("hv3_jet_1_4_syst");


 ofstream file1("data6_1.yaml");
 
 file1 << "independent_variables:" << endl;
 file1 << "- header: {name: '$p_\\mathrm{T,min}^\\mathrm{LP}$', units: GeV/c}" << endl;
 file1 << "  values:" << endl;
 file1 << Form("  - {value: %f}",0. ) << endl; 
 file1 << Form("  - {value: %f}",3. ) << endl;                   
 file1 << Form("  - {value: %f}",5. ) << endl;                   
 file1 << Form("  - {value: %f}",7. ) << endl;                   
 file1 << Form("  - {value: %f}",9. ) << endl;                   
 file1 << Form("  - {value: %f}",13. ) << endl;                   
 file1 << Form("  - {value: %f}",20. ) << endl;                   

 file1 << "dependent_variables:" << endl;

 file1 << "- header: {name: '$v_{2}$'}" << endl;
 file1 << "  qualifiers:" << endl;
 file1 << "  - {name: reaction, value: P P}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file1 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file1 << "  values:" << endl; 
 for(int i=0;i<7;i++){
 file1 << "  - errors:" << endl;
 file1 << Form("    - {label: stat, symerror: %f}",hv2lp_stat->GetBinError(i+1)) << endl;
 file1 << Form("    - {label: sys, symerror: %f}",hv2lp_syst->GetBinError(i+1)) << endl;
 file1 << Form("    value: %f",hv2lp_stat->GetBinContent(i+1)) << endl;
 }

 file1 << "- header: {name: '$v_{2}$'}" << endl;
 file1 << "  qualifiers:" << endl;
 file1 << "  - {name: reaction, value: P P}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file1 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file1 << "  values:" << endl;
 for(int i=0;i<7;i++){
 file1 << "  - errors:" << endl;
 file1 << Form("    - {label: stat, symerror: %f}",hv2lp14_stat->GetBinError(i+1)) << endl;
 file1 << Form("    - {label: sys, symerror: %f}",hv2lp14_syst->GetBinError(i+1)) << endl;
 file1 << Form("    value: %f",hv2lp14_stat->GetBinContent(i+1)) << endl;
 }


 ofstream file2("data6_2.yaml");

 file2 << "independent_variables:" << endl;
 file2 << "- header: {name: '$p_\\mathrm{T,min}^\\mathrm{LP}$', units: GeV/c}" << endl;
 file2 << "  values:" << endl;
 file2 << Form("  - {value: %f}",0. ) << endl;
 file2 << Form("  - {value: %f}",3. ) << endl;
 file2 << Form("  - {value: %f}",5. ) << endl;
 file2 << Form("  - {value: %f}",7. ) << endl;

 file2 << "dependent_variables:" << endl;

 file2 << "- header: {name: '$v_{3}$'}" << endl;
 file2 << "  qualifiers:" << endl;
 file2 << "  - {name: reaction, value: P P}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file2 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file2 << "  values:" << endl;
 for(int i=0;i<4;i++){
 file2 << "  - errors:" << endl;
 file2 << Form("    - {label: stat, symerror: %f}",hv3lp_stat->GetBinError(i+1)) << endl;
 file2 << Form("    - {label: sys, symerror: %f}",hv3lp_syst->GetBinError(i+1)) << endl;
 file2 << Form("    value: %f",hv3lp_stat->GetBinContent(i+1)) << endl;
 }

 file2 << "- header: {name: '$v_{3}$'}" << endl;
 file2 << "  qualifiers:" << endl;
 file2 << "  - {name: reaction, value: P P}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file2 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file2 << "  values:" << endl;
 for(int i=0;i<4;i++){
 file2 << "  - errors:" << endl;
 file2 << Form("    - {label: stat, symerror: %f}",hv3lp14_stat->GetBinError(i+1)) << endl;
 file2 << Form("    - {label: sys, symerror: %f}",hv3lp14_syst->GetBinError(i+1)) << endl;
 file2 << Form("    value: %f",hv3lp14_stat->GetBinContent(i+1)) << endl;
 }


 ofstream file3("data6_3.yaml");

 file3 << "independent_variables:" << endl;
 file3 << "- header: {name: '$p_\\mathrm{T,min}^\\mathrm{jet}$', units: GeV/c}" << endl;
 file3 << "  values:" << endl;
 file3 << Form("  - {value: %f}",0. ) << endl;
 file3 << Form("  - {value: %f}",10. ) << endl;
 file3 << Form("  - {value: %f}",20. ) << endl;
 file3 << Form("  - {value: %f}",30. ) << endl;
 file3 << Form("  - {value: %f}",40. ) << endl;

 file3 << "dependent_variables:" << endl;

 file3 << "- header: {name: '$v_{2}$'}" << endl;
 file3 << "  qualifiers:" << endl;
 file3 << "  - {name: reaction, value: P P}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file3 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file3 << "  values:" << endl;
 for(int i=0;i<5;i++){
 file3 << "  - errors:" << endl;
 file3 << Form("    - {label: stat, symerror: %f}",hv2jet_stat->GetBinError(i+1)) << endl;
 file3 << Form("    - {label: sys, symerror: %f}",hv2jet_syst->GetBinError(i+1)) << endl;
 file3 << Form("    value: %f",hv2jet_stat->GetBinContent(i+1)) << endl;
 }

 file3 << "- header: {name: '$v_{2}$'}" << endl;
 file3 << "  qualifiers:" << endl;
 file3 << "  - {name: reaction, value: P P}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file3 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file3 << "  values:" << endl;
 for(int i=0;i<5;i++){
 file3 << "  - errors:" << endl;
 file3 << Form("    - {label: stat, symerror: %f}",hv2jet14_stat->GetBinError(i+1)) << endl;
 file3 << Form("    - {label: sys, symerror: %f}",hv2jet14_syst->GetBinError(i+1)) << endl;
 file3 << Form("    value: %f",hv2jet14_stat->GetBinContent(i+1)) << endl;
 }


 ofstream file4("data6_4.yaml");

 file4 << "independent_variables:" << endl;
 file4 << "- header: {name: '$p_\\mathrm{T,min}^\\mathrm{jet}$', units: GeV/c}" << endl;
 file4 << "  values:" << endl;
 file4 << Form("  - {value: %f}",0. ) << endl;
 file4 << Form("  - {value: %f}",10. ) << endl;
 file4 << Form("  - {value: %f}",20. ) << endl;
 file4 << Form("  - {value: %f}",30. ) << endl;
 file4 << Form("  - {value: %f}",40. ) << endl;

 file4 << "dependent_variables:" << endl;

 file4 << "- header: {name: '$v_{3}$'}" << endl;
 file4 << "  qualifiers:" << endl;
 file4 << "  - {name: reaction, value: P P}" << endl;
 file4 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file4 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file4 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file4 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file4 << "  values:" << endl;
 for(int i=0;i<5;i++){
 file4 << "  - errors:" << endl;
 file4 << Form("    - {label: stat, symerror: %f}",hv3jet_stat->GetBinError(i+1)) << endl;
 file4 << Form("    - {label: sys, symerror: %f}",hv3jet_syst->GetBinError(i+1)) << endl;
 file4 << Form("    value: %f",hv3jet_stat->GetBinContent(i+1)) << endl;
 }

 file4 << "- header: {name: '$v_{3}$'}" << endl;
 file4 << "  qualifiers:" << endl;
 file4 << "  - {name: reaction, value: P P}" << endl;
 file4 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file4 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file4 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file4 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file4 << "  values:" << endl;
 for(int i=0;i<5;i++){
 file4 << "  - errors:" << endl;
 file4 << Form("    - {label: stat, symerror: %f}",hv3jet14_stat->GetBinError(i+1)) << endl;
 file4 << Form("    - {label: sys, symerror: %f}",hv3jet14_syst->GetBinError(i+1)) << endl;
 file4 << Form("    value: %f",hv3jet14_stat->GetBinContent(i+1)) << endl;
 }


}
