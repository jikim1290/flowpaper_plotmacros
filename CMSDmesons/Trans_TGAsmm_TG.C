
#include "TGraphErrors.h"
#include "TGraphAsymmErrors.h"
#include "TMath.h"
TGraphErrors *GetTGE(TGraphAsymmErrors *grData);
void Trans(TString filename);

void Trans(TString filename){
        TFile *f = new TFile( filename,"update" );
        TIter keyList(f->GetListOfKeys());
        TKey *key;

        for (auto k : *f->GetListOfKeys()){
            cout << k->GetName() << endl;
            f->cd(k->GetName());
            TGraphAsymmErrors *gras = (TGraphAsymmErrors*)gDirectory->Get("Graph1D_y1");
            if(gras == 0) continue;
            TGraphErrors *gr = GetTGE(gras);
         
            gr->Write();
        }
        // while ((key = (TKey*)keyList())) {
        //     cout << key->GetClassName() << endl;
        //     TClass *cl = gROOT->GetClass(key->GetClassName());
        //     cl->Print();
        //     if (!cl->InheritsFrom("TGraphAsymmErrors")) continue;
        //     cl->Print();
        //     TGraphAsymmErrors *gras = (TGraphAsymmErrors*)key->ReadObj();
        //     TGraphErrors *gr = GetTGE(gras);
        //     if(gr == 0) continue;
        //     //gr->Write();

        // }
        f->Close();     

}       

// error must be corrected later
TGraphErrors *GetTGE(TGraphAsymmErrors *grData){
    double x[300], y[300], exl[300], exh[300], eyl[300], eyh[300];
    
    int NC =  grData->GetN();
    TGraphErrors * gr = new TGraphErrors( NC );
    for(int ii=0;ii<NC;ii++){
        grData->GetPoint(ii,x[ii],y[ii]);
        exl[ii] = grData->GetErrorXlow(ii);
        exh[ii] = grData->GetErrorXhigh(ii);
        eyl[ii] = grData->GetErrorYlow(ii);
        eyh[ii] = grData->GetErrorYhigh(ii);
    }
    for(int ii=0;ii<NC;ii++){
        if(eyl[ii] != eyh[ii] ){
                cout << "Error is not symmetric" << endl;
                return 0;
        }
    }
    return new TGraphErrors(NC, x, y, exl, eyl);
}

