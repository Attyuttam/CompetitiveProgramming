#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll getPairs(map<ll,ll> a,map<ll,ll> b, vector<ll> a_val,vector<ll> b_val,ll k){
	ll res=0;

	for(ll i=0;i<k;i++){
		res+=(k-1)-(a[a_val[i]]-1)-(b[b_val[i]]-1);
	}
	return res/2;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin>>t;
	
	while(t--){
		ll boys,girls,k;
		cin>>boys>>girls>>k;

		map<ll,ll> a;
		vector<ll> a_val;
		for(ll i=0;i<k;i++){
			ll val;
			cin>>val;
			a_val.push_back(val);
			std::map<ll, ll>::iterator it = a.find(val); 
			if (it != a.end())
    			it->second+=1;
			else
				a.insert(make_pair(val,1));
		}
		map<ll,ll> b;
		vector<ll> b_val;
		for(ll i=0;i<k;i++){
			ll val;
			cin>>val;
			b_val.push_back(val);
			std::map<ll, ll>::iterator it = b.find(val); 
			if (it != b.end())
    			it->second+=1;
			else
				b.insert(make_pair(val,1));
		}

		cout<<getPairs(a,b,a_val,b_val,k)<<endl;
	}
	return 0;
}

