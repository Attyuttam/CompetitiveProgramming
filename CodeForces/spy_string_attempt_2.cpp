#include<bits/stdc++.h>
using namespace std;
bool isValid(string ans, vector<string> v){
	for(int i=0;i<v.size();i++){
		int cnt=0;
		for(int j=0;j<v[i].length();j++){
			if(ans[j]!=v[i][j]){
				cnt++;
			}
		}
		if(cnt>1)return false;
	}
	return true;
}
string getOptimalString(vector<string> v, int n,int m){
	string ans = v[0];
	if(isValid(ans,v)){
		return ans;
	}
	for(int i=0;i<m;i++){
		string temp = ans;
		for(char j='a';j<='z';j++){
			temp[i]=j;
			if(isValid(temp,v)){
				return temp;
			}
		}
	}
	return "-1";
} 
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		vector<string> v;
		for(int i=0;i<n;i++){
			string temp;
			cin>>temp;
			v.push_back(temp);
		}
		cout<<getOptimalString(v,n,m)<<endl;
	}
	return 0;
}

