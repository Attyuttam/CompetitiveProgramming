#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll getVal(ll v1,ll v2){
	return v2-v1;
}
ll findNum(ll n){
	ll curr_rem = 0;
	vector<ll> remDigitHolder;
	for(ll i=0;i<n;i++){
		remDigitHolder.push_back(-1);
	}
	for(ll i=1;i<=n;i++){
		curr_rem = (curr_rem*10+1);
		if(curr_num%n==0)return curr_num;
		// if duplicate remainder found
		if(numHolder[curr_num%n]!=-1){//here is where the PHP is applied, as there will be at least one remainder which is the same for 2 numbers
			ll val1,val2;
			if(curr_num<numHolder[curr_num%n]){
				val1=curr_num;
				val2=numHolder[curr_num%n];
			}else{
				val2=curr_num;
				val1=numHolder[curr_num%n];
			}
			cout<<"here: "<<getVal(val1,val2)<<" --> "<<val1<<" -- "<<val2<<endl;
			return getVal(val1,val2);
		}else{
			numHolder[curr_num%n]=curr_num;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<ll> v;
	//v.push_back(3);
	//v.push_back(300);
	//v.push_back(234);
	v.push_back(23);
	//v.push_back(11);
	//v.push_back(5);
	//v.push_back(10);
	
	for(int i=0;i<v.size();i++){
		cout<<findNum(v[i])<<endl;
	}

	return 0;
}

