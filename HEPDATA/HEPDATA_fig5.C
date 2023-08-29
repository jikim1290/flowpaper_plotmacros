{
 TFile* fin = new TFile("fout_vn_28jun2023.root","read");

 TGraphErrors* gv2pp_stat = (TGraphErrors*)fin->Get("pp_stat");
 TGraphErrors* gv2pp_syst = (TGraphErrors*)fin->Get("pp_syst");

 TGraphErrors* gv2pp14_stat = (TGraphErrors*)fin->Get("pp_14_stat");
 TGraphErrors* gv2pp14_syst = (TGraphErrors*)fin->Get("pp_14_syst");

 ofstream file1("data5_1.yaml");
 
 file1 << "independent_variables:" << endl;
 file1 << "- header: {name: '$N_\\mathrm{ch}(|\\eta|)<$ 0.5'}" << endl;
 file1 << "  values:" << endl;
 for(int i=0;i<gv2pp_stat->GetN();i++){
 file1 << Form("  - {value: %f}",gv2pp_syst->GetX()[i] ) << endl; 
 }

 file1 << "dependent_variables:" << endl;

 file1 << "- header: {name: '$v_{2}$'}" << endl;
 file1 << "  qualifiers:" << endl;
 file1 << "  - {name: reaction, value: P P}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file1 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file1 << "  values:" << endl; 
 for(int i=0;i<gv2pp_stat->GetN();i++){
 file1 <<"  - errors:" << endl;
 file1 << Form("    - {label: stat, symerror: %f}",gv2pp_stat->GetErrorY(i)) << endl;
 file1 << Form("    - {label: sys, symerror: %f}",gv2pp_syst->GetErrorY(i)) << endl;
 file1 << Form("    value: %f",gv2pp_stat->GetY()[i]) << endl;
 }

 file1 << "- header: {name: '$v_{2}$'}" << endl;
 file1 << "  qualifiers:" << endl;
 file1 << "  - {name: reaction, value: P P}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file1 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file1 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file1 << "  values:" << endl;
 for(int i=0;i<gv2pp_stat->GetN();i++){
 file1 <<"  - errors:" << endl;
 file1 << Form("    - {label: stat, symerror: %f}",gv2pp14_stat->GetErrorY(i)) << endl;
 file1 << Form("    - {label: sys, symerror: %f}",gv2pp14_syst->GetErrorY(i)) << endl;
 file1 << Form("    value: %f",gv2pp14_stat->GetY()[i]) << endl;
 }


 TGraphErrors* gv3pp_stat = (TGraphErrors*)fin->Get("pp_v3_stat");
 TGraphErrors* gv3pp_syst = (TGraphErrors*)fin->Get("pp_v3_syst");

 TGraphErrors* gv3pp14_stat = (TGraphErrors*)fin->Get("pp_14_v3_stat");
 TGraphErrors* gv3pp14_syst = (TGraphErrors*)fin->Get("pp_14_v3_syst");

 ofstream file2("data5_2.yaml");

 file2 << "independent_variables:" << endl;
 file2 << "- header: {name: '$N_\\mathrm{ch}(|\\eta|)<$ 0.5'}" << endl;
 file2 << "  values:" << endl;
 for(int i=0;i<gv3pp_stat->GetN();i++){
 file2 << Form("  - {value: %f}",gv3pp_syst->GetX()[i] ) << endl;
 }

 file2 << "dependent_variables:" << endl;

 file2 << "- header: {name: '$v_{3}$'}" << endl;
 file2 << "  qualifiers:" << endl;
 file2 << "  - {name: reaction, value: P P}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-2}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file2 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file2 << "  values:" << endl;
 for(int i=0;i<gv3pp_stat->GetN();i++){
 file2 <<"  - errors:" << endl;
 file2 << Form("    - {label: stat, symerror: %f}",gv3pp_stat->GetErrorY(i)) << endl;
 file2 << Form("    - {label: sys, symerror: %f}",gv3pp_syst->GetErrorY(i)) << endl;
 file2 << Form("    value: %f",gv3pp_stat->GetY()[i]) << endl;
 }

 file2 << "- header: {name: '$v_{3}$'}" << endl;
 file2 << "  qualifiers:" << endl;
 file2 << "  - {name: reaction, value: P P}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file2 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file2 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file2 << "  values:" << endl;
 for(int i=0;i<gv3pp_stat->GetN();i++){
 file2 <<"  - errors:" << endl;
 file2 << Form("    - {label: stat, symerror: %f}",gv3pp14_stat->GetErrorY(i)) << endl;
 file2 << Form("    - {label: sys, symerror: %f}",gv3pp14_syst->GetErrorY(i)) << endl;
 file2 << Form("    value: %f",gv3pp14_stat->GetY()[i]) << endl;
 }

 TGraphErrors* gv2pPb_stat = (TGraphErrors*)fin->Get("pPb_14_v2_stat");
 TGraphErrors* gv2pPb_syst = (TGraphErrors*)fin->Get("pPb_14_v2_syst");

 TGraphErrors* gv3pPb_stat = (TGraphErrors*)fin->Get("pPb_14_v3_stat");
 TGraphErrors* gv3pPb_syst = (TGraphErrors*)fin->Get("pPb_14_v3_syst");


 ofstream file3("data5_3.yaml");

 file3 << "independent_variables:" << endl;
 file3 << "- header: {name: '$N_\\mathrm{ch}(|\\eta|)<$ 0.5'}" << endl;
 file3 << "  values:" << endl;
 for(int i=0;i<gv2pPb_stat->GetN();i++){
 file3 << Form("  - {value: %f}",gv2pPb_syst->GetX()[i] ) << endl;
 }

 file3 << "dependent_variables:" << endl;

 file3 << "- header: {name: '$v_{2}$'}" << endl;
 file3 << "  qualifiers:" << endl;
 file3 << "  - {name: reaction, value: P PB}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file3 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file3 << "  values:" << endl;
 for(int i=0;i<gv2pPb_stat->GetN();i++){
 file3 <<"  - errors:" << endl;
 file3 << Form("    - {label: stat, symerror: %f}",gv2pPb_stat->GetErrorY(i)) << endl;
 file3 << Form("    - {label: sys, symerror: %f}",gv2pPb_syst->GetErrorY(i)) << endl;
 file3 << Form("    value: %f",gv2pPb_stat->GetY()[i]) << endl;
 }

 file3 << "- header: {name: '$v_{3}$'}" << endl;
 file3 << "  qualifiers:" << endl;
 file3 << "  - {name: reaction, value: P PB}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,trig}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: '$p_\\mathrm{T,assoc}$', units: GeV/c,  value: 1-4}" << endl;
 file3 << "  - {name: stat, value: Statistical Uncertainty}" << endl;
 file3 << "  - {name: sys, value: Systematic Uncertainty}" << endl;
 file3 << "  values:" << endl;
 for(int i=0;i<gv2pPb_stat->GetN();i++){
 file3 <<"  - errors:" << endl;
 file3 << Form("    - {label: stat, symerror: %f}",gv3pPb_stat->GetErrorY(i)) << endl;
 file3 << Form("    - {label: sys, symerror: %f}",gv3pPb_syst->GetErrorY(i)) << endl;
 file3 << Form("    value: %f",gv3pPb_stat->GetY()[i]) << endl;
 }



}
