#include<bits/stdc++.h>
using namespace std;
bool check(vector<int> v,int k,int C){

	int i = 0, num = 0;
	while(i<v.size()){
		int sum = 0;
		while(i<v.size() && sum+v[i]<=C){
			sum+=v[i];
			i++;
		}
		num++;
	}
	if(num<=k)return 1;
	return 0;
}
int findMinCapacity(vector<int> v, int k){
	int Cl = *max_element(v.begin(),v.end());
	int Cr = accumulate(v.begin(),v.end(),0);
 
	int Cmin = INT_MAX;
	while(Cl<=Cr){
		int Cmid = (Cl+Cr)/2;
		bool res = check(v,k,Cmid);
		if(res){
			Cmin = min(Cmin,Cmid);
			Cr = Cmid-1;
		}else{
			Cl = Cmid+1;
		}
	}
	return Cmin;
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
		cout<<findMinCapacity(v,k)<<endl;
	}
	return 0;
}

