#include<bits/stdc++.h>
using namespace std;
void calcError(long double sum,long double val){
	double absError = abs(sum-val);
	cout<<absError<<endl;
	double relError = abs(sum-val)/val;
	cout<<relError<<endl;
}
int main(){
	int n;
	cin>>n;
	
	long double sum=0.0;
	
	for(int i=0;i<n;i++){
		long double x;
		cin>>x;
		sum = sum + x+(1.0/x);
	}
	cout<<setprecision(10)<<fixed<<sum<<endl;
	//calcError(sum,-4.0000000483);
	
	return 0;
}




