#include<bits/stdc++.h>
using namespace std;
void print(map<pair<int,int>,vector<int>>mp,int n){
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			cout<<"("<<i<<","<<j<<") --> ";
			for(int k=0;k<mp[{i,j}].size();k++){
				cout<<mp[{i,j}][k]<<" ";
			}
			cout<<endl;
		}
	}
}
int obtainMaxSum(map<pair<int,int>,vector<int>>mp,int n){
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int sum=0;
			for(int k=0;k<mp[{i,j}].size();k++){
				sum+=mp[{i,j}][k];
				ans = max(ans,sum);
				if(sum<0)sum=0;
			}
		}
	}
	return ans;
}
void partialSum(vector<vector<int>> a, int m,int n){
	map<pair<int,int>,vector<int>> mp;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			vector<int> tmp;
			for(int k=0;k<m;k++){
				int tmpSum=0;
				for(int l=i;l<=j;l++){
					tmpSum+=a[l][k];
				}
				tmp.push_back(tmpSum);
			}
			mp.insert(make_pair(make_pair(i,j),tmp));
		}
	}
	print(mp,n);
	cout<<obtainMaxSum(mp,n);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m,n;
	cin>>m>>n;
	
	vector<vector<int>> a;
	
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int var;
			cin>>var;
			temp.push_back(var);
		}
		a.push_back(temp);
	}
	partialSum(a,m,n);
	return 0;
}

