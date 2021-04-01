#include<bits/stdc++.h>
using namespace std;
void print(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}

void findSum(vector<int> v,int s,int n,vector<int> currentList){
	//how to stop the recursion in this ? 
	//Cause even if its larger we need to continue as there might be negative elements
	//to reduce the value.
	cout<<s<<endl;
	if(currentList.size()>6)return;
	if(accumulate(currentList.begin(),currentList.end(),0)==s){
		print(currentList);
		return;
	}
	
	for(int i=0;i<n;i++){
		vector<int> newCurrentList = currentList;
		currentList.push_back(v[i]);
		findSum(v,s-v[i],n,newCurrentList);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,s;
	vector<int> v;
	cin>>n>>s;
	for(int i=0;i<n;i++){
		int t;
		cin>>t;
		v.push_back(t);
	}
	vector<int> currentList;
	findSum(v,s,n,currentList);
	return 0;
}

