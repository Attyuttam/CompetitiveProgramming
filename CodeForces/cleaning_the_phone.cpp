#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll getVal(vector<ll> mem,vector<ll> con, int totalMem,int totalCon, int minMem){
	if(mem.size()==0){
		if(totalMem>=minMem)return totalCon;
		return INT_MAX;
	}
	
	
	vector<ll> tempMem = mem;
	vector<ll> tempCon = con;
	
	tempMem.pop_back();
	tempCon.pop_back();
	
	return min(getVal(tempMem,tempCon,totalMem,totalCon,minMem),getVal(tempMem,tempCon,totalMem+mem[mem.size()-1],totalCon+con[con.size()-1],minMem));
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	cin>>t;
	
	while(t--){
		ll n,m;
		cin>>n>>m;
		vector<ll> mem;
		vector<ll> con;
		
		for(ll i=0;i<n;i++){
			ll temp;
			cin>>temp;
			mem.push_back(temp);
		}
		for(ll i=0;i<n;i++){
			ll temp;
			cin>>temp;
			con.push_back(temp);
		}
		ll res = getVal(mem,con,0,0,m);
		if(res == INT_MAX)cout<<"-1"<<endl;
		else cout<<res<<endl;
	}
	return 0;
}

