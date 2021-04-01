#include<bits/stdc++.h>
#define ll long long
using namespace std;
//If a number has a number of 2020s and b number of 2021s, then,

// when a>0 and b>0
//we start subtracting 2021 from it, so if we keep on subtracting 2021, then we will end up with some multiple of 2020
//so, we check if its a multiple of 2020 or not, if yes then return "YES" else "NO"

//when a>0 and b=0
//This means that there are no 2021s in the number, hence we keep on subtracting 2020 and at the end we will get 0 

//when a=0 and b>0
//This means the number is a multiple of 2021

//when a and b does not exist
//we keep on subtracting 2021, soon we will come to a number less than 2021 or maybe negative, both of which are not a multiple of 2020, hence "NO"
string check(ll val){
	while(val>=2021 && val%2020!=0){
		val-=2021;
	}
	if(val%2020==0)
		return "YES";
	return "NO";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	ll t;
	vector<ll> v;
	cin>>t;
	while(t--){
		ll n;
		cin>>n;
		v.push_back(n);	
	}
	for(ll i=0;i<v.size();i++){
		cout<<check(v[i])<<endl;
	}
	return 0;
}

