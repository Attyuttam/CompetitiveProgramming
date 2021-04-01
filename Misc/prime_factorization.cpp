#include<bits/stdc++.h>
using namespace std;
vector<pair<int,int>> findPrimeFactors(int n){
	int d=2;
	vector<pair<int,int>> res;
	while(n>1 && d*d<=n){
		int expVal=0;
		while(n%d==0){
			n/=d;
			expVal++;
		}
		if(expVal>0){
			res.push_back(make_pair(d,expVal));
		}
		
		d++;
	}
	if(n>1){
		res.push_back(make_pair(n,1));
	}
	return res;
}
vector<pair<int,int>> genericStyleFindPrimeFactors(int n){
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	vector<pair<int,int>> res;
	res = findPrimeFactors(n);
	for(int i=0;i<res.size();i++){
		cout<<res[i].first<<"^"<<res[i].second<<"*";
	}
	cout<<1<<endl;
	return 0;
}

