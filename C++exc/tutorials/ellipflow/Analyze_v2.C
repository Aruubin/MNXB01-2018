#include <iostream>
#include <fstream>

using namespace std;


#include <TF1.h>  
#include <TH1.h> 
#include <TStyle.h>
#include <TMath.h> 
#include <TCanvas.h>

void analyze_v2_2particle();


void analyze_v2_2particle()
{
	Int_t nEvents =0;
	string helpString;
	
	ifstream file("phi_dist.dat");
	Int_t eventNo=-1;
	Double_t sum_cos2_diff = 0;
	Int_t nTracks = -1;
	Double_t sum_cos2 = 0;
	Double_t sum_sin2 = 0;
	Double_t corrAvg=0;
	Double_t corrQAvg=0;
	
	TH1D* hPhi = new TH1D("hPhi", "ROOT func generated v2 distribution; Phi; Counts", 
			100, 0, 2*TMath::Pi());
	
	while(file>> helpString >> eventNo){
		
		cout<< "Reading event : " << eventNo << endl;
		nEvents++;
		
		
		file>>helpString>>nTracks;
		cout << "Event contains " << nTracks << " tracks" << endl;
		
		Double_t phi[nTracks];
		Int_t trackNo;
		
		for(Int_t nt=0; nt < nTracks; nt++) {		
			file>>trackNo>>helpString>>phi[nt];
			hPhi->Fill(phi[nt]);
		}

	//2-particle
		
		for(Int_t i = 0; i < nTracks; i++) {
			
			sum_cos2 +=TMath::Cos(2*phi[i]);
			sum_sin2 +=TMath::Sin(2*phi[i]);
			
			for(Int_t j = i+1; j < nTracks; j++) {
			
				sum_cos2_diff += 2*TMath::Cos(2*(phi[i]-phi[j]));
			}
		}
	
	
	Double_t corr = (1./(nTracks*(nTracks-1)))*sum_cos2_diff;
	corrAvg += corr;
	
	Double_t corrQ = (pow(sum_cos2, 2) + pow(sum_sin2, 2) - nTracks)/(nTracks*(nTracks-1));
	corrQAvg += corrQ;
	
	cout<<"From 2-particle method: <2> = "<<corr<<endl;
	sum_cos2_diff=0;
	if(corr<0){
		cout<<"<2> is negative, please choose larger number of tracks"<<endl;
	}
	else{
		cout<<"v2 = "<< sqrt(corr)<<endl;
	}
	
	cout<<"From Q-vector method: <2>= "<<corrQ<<endl;
	sum_cos2 = 0;
	sum_sin2 = 0;
	if(corrQ<0){
		cout<<"<2> is negative, please choose larger number of tracks"<<endl;
	}
	else{
		cout<<"Q: v2 = "<< sqrt(corrQ)<<endl<<endl;
	}
	
	}
	file.close();
	
	cout<<"Average of 2-particle method: <2>= "<<corrAvg/nEvents<<endl;
	cout<<"Average of Q-vector method: <2>= "<<corrQAvg/nEvents<<endl;
	
	if(corrAvg<0){
		cout<<"<2> is negative, please choose larger number of tracks"<<endl;
	}
	else{
		cout<<"The average v2 using the 2-particle method: "<<sqrt(corrAvg/nEvents)<<endl;
	}
	
	if(corrQAvg<0){
		cout<<"<2> is negative, please choose larger number of tracks"<<endl;
	}
	else{
		cout<<"The average v2 using the Q-vector method: "<<sqrt(corrQAvg/nEvents)<<endl;
	}
	
	TCanvas* c1 = new TCanvas("c1read", "v2 canvas", 900, 600);
  hPhi->SetMinimum(0);
  hPhi->Draw();
}
