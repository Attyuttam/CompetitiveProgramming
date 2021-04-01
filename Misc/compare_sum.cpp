#include<bits/stdc++.h>
using namespace std;

string compareSum(vector<double> a,vector<double>b){
	double sumA = accumulate(a.begin(),a.end(),0.0);
	double sumB = accumulate(b.begin(),b.end(),0.0);
	double epsilon = 0.0001;
	cout<<sumA<<endl<<sumB<<endl<<abs(sumA - sumB)<<endl;
	if(abs(sumA - sumB) < epsilon){
		return "SUM(A)=SUM(B)";
	}else if(sumA > sumB+epsilon){
		return "SUM(A)>SUM(B)";
	}else {
		return "SUM(A)<SUM(B)";
	}
}
int main(){
	int n;
	cin>>n;
	vector<double> a;
	vector<double> b;
	for(int i=0;i<n;i++){
		double temp;
		cin>>temp;
		a.push_back(temp);
	}
	for(int i=0;i<n;i++){
		double temp;
		cin>>temp;
		b.push_back(temp);
	}
	cout<<compareSum(a,b)<<endl;
	return 0;
}

