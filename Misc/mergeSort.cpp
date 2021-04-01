#include<bits/stdc++.h>
using namespace std;
vector<int> v;
void merge(int b,int mid,int e){
	int i=b;
	int j=mid+1;
	
	vector<int>tmp;
	while(i<=mid && j<=e){
		if(v[i]<v[j]){
			tmp.push_back(v[i]);
			i++;
		}else if(v[j]<v[i]){
			tmp.push_back(v[j]);
			j++;
		}
	}
	while(i<=mid){
		tmp.push_back(v[i]);
		i++;
	}
	while(j<=e){
		tmp.push_back(v[j]);
		j++;
	}
	int k = 0;
	for(int i=b;i<=e;i++){
		v[i] = tmp[k];
		k++;
	}
}
mergeSort(int b,int e){
	if(b<e){
		int mid = (b+e)/2;
		mergeSort(b,mid);
		mergeSort(mid+1,e);
		merge(b,mid,e);
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	mergeSort(0,v.size()-1);
	for(int i=0;i<v.size();i++){
		cout<<v[i]<<" ";
	}
	cout<<endl;
	
	return 0;
}

