#include<bits/stdc++.h>
using namespace std;
void findMinSum(vector<long> val){
	long sum=0;
	for(auto i=val.begin();i!=val.end();i++){
		for(auto j=i;j!=val.end();j++){
			//cout<<*i<<" -- "<<*j<<" --min:-- "<<*min_element(i,j+1)<<endl;
			sum+=*min_element(i,j+1);
		}	
	}
	cout<<sum<<endl;
}
int main(){
	long n;
	cin>>n;
	vector<long> val; 
	for(long i=0;i<n;i++){
		int t;
		cin>>t;
		val.push_back(t);
	}
	findMinSum(val);
	return 0;
}

