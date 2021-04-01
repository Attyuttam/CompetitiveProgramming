#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll mod = 1e9 + 7;

ll findExpVal(ll a, ll p) {
  ll res = 1;
  while (p) {
    if (p % 2 == 0) {
      a = a * a % mod;
      p /= 2;
    } else {
      res = res * a % mod;
      p--;
    }
  }
  return res;
}

ll fact(ll n) {
  ll res = 1;
  for (ll i = 1; i <= n; i++) {
    res = res * 1ll * i % mod;
  }
  return res;
}

ll getCombValue(ll n, ll k) {
  return fact(n)%mod * findExpVal(fact(k), mod - 2) % mod * findExpVal(fact(n - k), mod - 2) % mod;
}
ll blogger(vector<ll> v,ll k){
	sort(v.begin(),v.end());
	reverse(v.begin(),v.end());
	ll totalMin=0;
	for(ll i=0;i<v.size();i++){
		if(v[i]==v[k-1])totalMin++;
	}
	ll r = 0;
	for(ll i=0;i<k;i++){
		if(v[i]==v[k-1])r++;
	}
	
	ll n = totalMin;
	
	return getCombValue(n,r);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ll t;
	cin>>t;
	while(t--){
		ll n,k;
		cin>>n>>k;
		vector<ll> v;
		for(ll i=0;i<n;i++){
			ll temp;
			cin>>temp;
			v.push_back(temp);
		}
		cout<<blogger(v,k)<<endl;
		
	}
	
	return 0;
}

