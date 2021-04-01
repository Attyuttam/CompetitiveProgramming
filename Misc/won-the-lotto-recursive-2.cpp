#include<bits/stdc++.h>
using namespace std;
void print(vector<int> vec){
	for(int i=0;i<vec.size();i++){
		cout<<vec[i]<<" ";
	}
	cout<<endl;
}
int calcSum(vector<int> v){
	int sum=0;
	for(int i=0;i<v.size();i++){
		sum+=v[i];
	}
	return sum;
}
void findSum(vector<int> v,int s,int n,vector<int> currentList){
	if(currentList.size()>6)return;
	
	if(calcSum(currentList)==s){
		print(currentList);
		return;
	}
	
	for(int i=0;i<n;i++){
		vector<int> newCurrentList(currentList);
		newCurrentList.push_back(v[i]);
		//cout<<i<<" "<<newCurrentList.size()<<endl;
		findSum(v,s,n,newCurrentList);
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

