#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll n;
	cin>>n;
	
	vector<ll> v;
	vector<ll>zeroToIndexSum;
	for(ll i=0;i<n;i++){
		ll temp;
		cin>>temp;
		v.push_back(temp);
	}
	zeroToIndexSum.push_back(v[0]);
	for(ll i=1;i<v.size();i++){
		zeroToIndexSum.push_back(v[i]+zeroToIndexSum[i-1]);
	}
	zeroToIndexSum.insert(zeroToIndexSum.begin(),0);
	ll minSumFromLeft,maxSumFromRight,minSumIndexFromLeft,maxSumIndexFromRight;
	
	minSumFromLeft=INT_MAX;
	maxSumFromRight=INT_MIN;
	
	ll i = 0;
	ll j = zeroToIndexSum.size()-1;
	
	while(i<j){
		if(zeroToIndexSum[i]<minSumFromLeft){
			minSumFromLeft = zeroToIndexSum[i];
			minSumIndexFromLeft = i;
		}
		if(zeroToIndexSum[j]>maxSumFromRight){
			maxSumFromRight = zeroToIndexSum[j];
			maxSumIndexFromRight = j;
		}
		i++;
		j--;
	}
	cout<<"\nMax Sum of subarray from position "<<minSumIndexFromLeft+1<<" to "<<maxSumIndexFromRight<<" is: "<<maxSumFromRight-minSumFromLeft<<endl;
	return 0;
}

