#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll n;
	cin>>n;
	vector<ll> v;
	for(ll i=0;i<n;i++){
		ll t;
		cin>>t;
		v.push_back(t);
	}
	ll q;
	cin>>q;
	vector<ll> rr;
	for(ll i=0;i<n;i++){
		rr.push_back(0L);
	}
	while(q--){
		ll l,r, val;
		cin>>l>>r>>val;
		rr[l]+=val;
		rr[r+1]-=val;
		
	}
	cout<<"\nfinal:\n";
	cout<<v[0]+rr[0]<<" ";
	for(ll i=1;i<n;i++){
		rr[i]+=rr[i-1];
		cout<<v[i]+rr[i]<<" ";
	}
	
	
	
	return 0;
}

