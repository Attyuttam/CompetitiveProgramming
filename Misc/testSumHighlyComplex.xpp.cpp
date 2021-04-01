#include<bits/stdc++.h>
using namespace std;
int findSum(vector<int> v,int target){
	int n = v.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(v[i]+v[j]+v[k]==target){
					cout<<v[i]<<" "<<v[j]<<" "<<v[k]<<endl;
				}
			}
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,target;
	cin>>n>>target;
	
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	findSum(v,target);
	return 0;
}

