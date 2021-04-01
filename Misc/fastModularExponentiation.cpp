#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll mod = 1000000009;
ll findExpVal(ll a,ll b){
	if(b==0||a==0||a==1)return 1;
	if(b==1)return a;
	if(b%2==0){
		ll res = findExpVal(a,b/2);
		return res*res;
	}else
		return a*findExpVal(a,b-1);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	vector<pair<ll,ll>>v;
	v.push_back(make_pair(1,1)); 
	v.push_back(make_pair(0,2));
	v.push_back(make_pair(0,0));
	v.push_back(make_pair(500,0));
	v.push_back(make_pair(3,5)); 
	v.push_back(make_pair(10,5));
	v.push_back(make_pair(7,10));
	v.push_back(make_pair(10,18));
	for(int i=0;i<v.size();i++)
		cout<<findExpVal(v[i].first,v[i].second)<<endl;
	
	return 0;
}

