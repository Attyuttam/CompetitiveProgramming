#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	int count = k;
	if(k>=n){
		count=0;
		for(int j=0;j<n;j++){
			if(v[j]>0){
				count++;
			}
		}
	}
	else if(v[k-1]<=0){
		count=0;
		for(int j=0;j<=k && v[j]>0;j++){
			count++;
		}
	}
	else{
		for(int i=k;i<n;i++){
			if(v[i]<v[k-1]){
				break;
			}
			count++;
		}
	}
	
	
	cout<<count<<endl;
	return 0;
}

