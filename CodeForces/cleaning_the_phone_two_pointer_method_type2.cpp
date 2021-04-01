#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll getVal(vector<ll> mem,vector<ll> con, int minMem){
	//if the memory of total number of applications is less than minMem, then you cannot delete minMem memory at all, hence inf
	ll res = accumulate(mem.begin(),mem.end(),0ll);
	if(res<minMem)return INT_MAX;
	
	//possible to delete
	res=INT_MAX;
	
	vector<ll> twoPointers;
	vector<ll> onePointers;
	
	for(ll i=0;i<con.size();i++){
		if(con[i]==1){
			onePointers.push_back(mem[i]);
		}else{
			twoPointers.push_back(mem[i]);
		}
	}
	sort(onePointers.begin(),onePointers.end());
	reverse(onePointers.begin(),onePointers.end());
	sort(twoPointers.begin(),twoPointers.end());
	reverse(twoPointers.begin(),twoPointers.end());
	
	
	ll sumOfOnePointers = 0ll;
	ll sumOfTwoPointers = accumulate(twoPointers.begin(),twoPointers.end(),0ll);

	ll r=twoPointers.size()-1;
	ll l=0;
	
	while(r>=0 && sumOfOnePointers+sumOfTwoPointers-twoPointers[r]>=minMem){
			sumOfTwoPointers-=twoPointers[r];
			r--;
	}
	if(sumOfOnePointers+sumOfTwoPointers>=minMem){
		res = min(res,2*(r+1));
	}
	while(l<onePointers.size()){
		sumOfOnePointers+=onePointers[l];
		while(r>=0 && sumOfOnePointers+sumOfTwoPointers-twoPointers[r]>=minMem){
			sumOfTwoPointers-=twoPointers[r];
			r--;
		}	
		if(sumOfOnePointers+sumOfTwoPointers>=minMem){
			res = min(res,(2*(r+1))+(l+1));
		}
		l++;	
	}
	return res;
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
		ll res = getVal(mem,con,m);
		if(res == INT_MAX)cout<<"-1"<<endl;
		else cout<<res<<endl;
	}
	return 0;
}


