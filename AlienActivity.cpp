#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
	ifstream inFile("detReadout.dat");
	if(!inFile){
		cout<<"Can´t open detReadout.dat"<<endl;
		return 1;
	}
	
	double time = 0.;
	int count = 0;
	bool isOk = false;
	
	vector<double> times;
	vector<int> counts;
	
	while(inFile>>time) {
		inFile >>count;
		inFile>>isOk;
		if(isOk){
			times.push_back(time);
			counts.push_back(count);
		}
	}
	inFile.close();
	
	double countSum = 0;
	for(int i=0;i<counts.size();i++){
		countSum = countSum + counts[i];
	}
	
	double mean = countSum / counts.size();
	
	double Sum = 0;
	for(int j=0;j<counts.size();j++){
		Sum=Sum+(counts[j]-mean)*(counts[j]-mean);
	}
	int size=counts.size();
	double standardDeviation = sqrt (Sum/size);
	
	cout<<"Mean: "<<mean<<endl;
	cout<<"Standard deviation: "<< standardDeviation <<endl;
	
	for(int l=0; l<size; l++){
		if(counts[l]-mean > 5*standardDeviation){
			cout<<"Ailiens at time "<<times[l]<<"h\n";
		}
	}
	
}
		
