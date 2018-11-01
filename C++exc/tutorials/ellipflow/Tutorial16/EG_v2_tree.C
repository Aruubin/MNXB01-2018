

#include <iostream>
#include <fstream>


using namespace std;


#include <TF1.h> 
#include <TH1.h> 
#include <TStyle.h>
#include <TMath.h>  
#include <TCanvas.h>
#include <TRandom.h>
#include <TTree.h>

#include <TFile.h>
#include <TClonesArray.h>
#include <TClass.h>
#include "MyClasses.C"


void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t sigmaTracks, Double_t v2, Double_t sigmaV2); 
//NOTE!: For values of sigmaTracks larger than one, the executable is very likely to crash. 


void rootfuncgenerate(Int_t nEvents, Int_t nTracks, Double_t sigmaTracks, Double_t v2, Double_t sigmav2) 
{
  cout << "Generating " << nEvents << " events" << endl << endl;


  TH1D* hPhi = new TH1D("hPhi", "ROOT func generated v2 distribution; Phi; Counts", 
			100, 0, 2*TMath::Pi());

  Double_t phi[nTracks];
  
  ofstream file1("phi_dist.dat");
  
  TFile* file = new TFile("phi_dist.root", "RECREATE");
  TTree* tree = new TTree("tree", "Output tree");
  MyEvent* event = new MyEvent();
  tree->Branch("event", &event);
  TClonesArray* trackArray = new TClonesArray("MyTrack", 1000);
  tree->Branch("track", "TClonesArray", &trackArray);
  Int_t nT = 0;
 
 
 
 
  
  for(Int_t n = 0; n < nEvents; n++) {
	
	Int_t nTracksRand = gRandom->Gaus(nTracks, sigmaTracks);
	
	Double_t v2Rand = gRandom->Gaus(v2, sigmav2);  

	
    TF1* v2Func = new TF1("v2Func", "1+2*[3]*cos(2*x)", 0, 2*TMath::Pi());
    v2Func->SetParameter(3, v2Rand);
    
    event->nTracks = nTracksRand;
	event->fV2 = v2Rand;
   
    for (Int_t nt = 0; nt < nTracksRand; nt++) {
	phi[nt] = v2Func->GetRandom();  
	MyTrack* track = new((*trackArray)[nt]) MyTrack();
	track->fPhi = phi[nt];
	}
   
    if((n+1)%1000==0)
      cout << "event " << n+1 << endl;
    
    file1<< "Event "<<n<<endl;
    file1<< "nTracks "<<nTracksRand<<endl;
    
    
    for(Int_t i = 0; i < nTracksRand; i++){
	hPhi->Fill(phi[i]);
    file1<<i<<" : "<<phi[i]<<endl;
    }
    
    tree->Fill();
    trackArray->Clear();
  }
  file1.close();
  file->Write();
  file->Close();
  
  
  
  gStyle->SetOptStat(1111);
  gStyle->SetOptFit(1111);

  
  TCanvas* c1 = new TCanvas("c1", "v2 canvas", 900, 600);
  hPhi->SetMinimum(0);
  hPhi->Draw();
  

  TF1* fitFunc = new TF1("fitFunc", "[0]*(1+2*[1]*cos(2*x))", 0, 2*TMath::Pi());
  fitFunc->SetParameter(0, 10);
  fitFunc->SetParameter(1, v2);
  fitFunc->SetLineColor(kRed);
  hPhi->Fit(fitFunc);
  
  
  c1->SaveAs("v2_rootfunc.jpg");
}
