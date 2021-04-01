#include<bits/stdc++.h>
#include<chrono>
using namespace std;
using namespace std::chrono; 

void generateAllOfLengthN(int N,string toPrint){
	if(N!=0){
		generateAllOfLengthN(N-1,toPrint+"a");
		generateAllOfLengthN(N-1,toPrint+"b");
	}else{
		cout<<toPrint<<endl;
	}
	
}
int main(){
	int N;
	for(int i=3;i<=3;i++){
		auto start = chrono::high_resolution_clock::now(); 
		generateAllOfLengthN(i,"");
		auto stop = chrono::high_resolution_clock::now();
		auto duration = duration_cast<microseconds>(stop - start);
		cout << "TIME TAKEN TO GENERATE STRING OF LENGTH "<<i<<": "<<duration.count() << endl; 

	}
	
}
