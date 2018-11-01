#include <iostream>
#include <fstream>

using namespace std;


#include <TF1.h>  
#include <TH1.h> 
#include <TStyle.h>
#include <TMath.h> 
#include <TCanvas.h>
#include <TTree.h>
#include <TFile.h>
#include <TClonesArray.h>
#include <TClass.h>

#include "MyClasses.C"

void analyze_v2_2particle();


void analyze_v2_2particle()
{
	
	TFile* file = TFile::Open("phi_dist.root");
	TTree* tree = (TTree*)file->Get("tree");
	MyEvent* event = 0;
	TClonesArray* trackArray = 0;
	tree->SetBranchAddress("event", &event);
	tree->SetBranchAddress("track", &trackArray);
	
	Double_t sum_cos2 = 0;
	Double_t sum_sin2 = 0;
	Double_t corrQ = 0;
	Double_t v2Avg = 0;
	
	Int_t nEvents = tree->GetEntries();
	for(Int_t n = 0; n < nEvents; n++){
		tree->GetEntry(n);
		
		const Int_t nTracks = trackArray->GetEntries();
		
		for(Int_t i=0; i<nTracks; i++){
			MyTrack* track = (MyTrack*)trackArray->At(i);
			
			sum_cos2 +=TMath::Cos(2*(track->fPhi));
			sum_sin2 +=TMath::Sin(2*(track->fPhi));
			
		}
	corrQ = (pow(sum_cos2, 2) + pow(sum_sin2, 2) - nTracks)/(nTracks*(nTracks-1));
	
	cout<<"From Q-vector method at event: "<<n<<" <2>= "<<corrQ<<endl;
	sum_cos2 = 0;
	sum_sin2 = 0;
	if(corrQ<0){
		cout<<"<2> is negative, please choose larger number of tracks"<<endl;
	}
	else{
		cout<<"Q: v2 = "<< sqrt(corrQ)<<endl<<endl;
		v2Avg += sqrt(corrQ);
	}
	
	}
	
	cout<<"The average v2 using the Q-vector method: "<<v2Avg/nEvents<<endl;
	
	
}
