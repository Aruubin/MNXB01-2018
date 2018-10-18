#include "TH1.h"
#include "TF1.h"
#include <TStyle.h>

void hist_gen_mod(Int_t num, Double_t sigm)
{
  TH1D* hist = new TH1D("hist", "Histogram", 40, -3, 3);
  
  TF1* fGaus = new TF1("fGaus", "gaus", -3, 3);
  fGaus->SetParameters(1, 0, sigm); // amplitude, mean, sigma

  for(Int_t i = 0; i < num; i++) {

    hist->Fill(fGaus->GetRandom());
  }
  hist->Sumw2();
  
  gStyle->SetOptFit();

  hist->Draw();
}
