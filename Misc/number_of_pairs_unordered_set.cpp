#include<bits/stdc++.h>
using namespace std;
int findNumPairs(vector<int> v,int n,int s){
	unordered_map<int,vector<int>> us;
	for(int i=0;i<n;i++){
		us[v[i]].push_back(i);
	}
	int numPairs=0;
	for(int i=0;i<n;i++){
		
		if(us.find(s-v[i])!=us.end()){
			for(int j=0;j<us[s-v[i]].size();j++){
				if(us[s-v[i]][j]>i)numPairs++;
			}
		}
	}
	return numPairs;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,s;
	cin>>n>>s;
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp; 
		v.push_back(temp);
	}
	cout<<findNumPairs(v,n,s);
	return 0;
}

