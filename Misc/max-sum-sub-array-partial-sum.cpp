#include<bits/stdc++.h>
using namespace std;
int maxSumSubArray(vector<int> v,int n){
	vector<int> partialSum;
	partialSum.push_back(v[0]);
	for(int i=1;i<n;i++){
		partialSum.push_back(partialSum[i-1]+v[i]);
	}
	
	int minEl = partialSum[0];
	int ans = INT_MIN;
	
	for(int i=1;i<n;i++){
		if(partialSum[i]-minEl>ans){
			ans = partialSum[i]-minEl;
		}
		if(partialSum[i]<minEl){
			minEl = partialSum[i];
		}
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	vector<int> v;
	
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	
	cout<<maxSumSubArray(v,n);
	return 0;
}

