#include<bits/stdc++.h>
using namespace std;
vector<int> takeInput(){
	vector<int> v;
	int n;
	cin>>n;
	for(int i=0;i<n;i++){
		int temp; cin>>temp;v.push_back(temp);
	}
	return v;
}
void findMaxSumSubArray(vector<int> v){
	int max = -1;
	for(int i=0;i<v.size();i++){
		for(int j=i;j<v.size();j++){
			int sum=0;
			for(int k=i;k<=j;k++){
				sum+=v[k];
				cout<<v[k]<<" ";
			}
			cout<<"---"<<sum<<endl;
			if(sum>max)max=sum;
		}
	}
	cout<<max<<endl;
}
int main(){
	vector<int> v;
	v = takeInput();
	findMaxSumSubArray(v);
}
