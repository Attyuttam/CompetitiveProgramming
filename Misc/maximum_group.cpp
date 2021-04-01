#include<bits/stdc++.h>
using namespace std;
bool isValid(vector<int> v, int k,int x){
	long long cnt = 0;
	for(int i=0;i<v.size();i++){
		cnt+=min(x,v[i]);
	}
	cout<<"--->"<<cnt<<" "<<1LL*x*k<<endl;
	return cnt>=1LL*x*k;
}
int bSearch(vector<int> v, int k){
	int l=0,r=accumulate(v.begin(),v.end(),0)/k,ans;
	while(l<=r){
		int m=(l+r)/2;
		cout<<m<<endl;
		if(isValid(v,k,m)){
			cout<<m<<" is valid"<<endl;
			ans = m;
			l = m + 1;
		}else{
			r = m - 1;
		}
	}
	return ans;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		vector<int> v;
		for(int i=0;i<n;i++){
			int tmp;
			cin>>tmp;
			v.push_back(tmp);
		}
		cout<<bSearch(v,k)<<endl;
	}
	return 0;
}

