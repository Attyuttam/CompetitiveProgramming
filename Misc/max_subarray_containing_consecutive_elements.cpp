#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
//pigeon hole principle
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	
	unordered_map<int,int> freq;
	int maxVal=INT_MIN;
	int minVal=INT_MAX;
	int res=0;
	for(int i=0;i<n;i++){
		freq.clear();
		maxVal=v[i];
		minVal=v[i];
		for(int j=i;j<n;j++){
			if(freq[v[j]]!=0){
				break;
			}
			freq[v[j]]++;
			maxVal=max(maxVal,v[j]);
			minVal=min(minVal,v[j]);
			
			if(j-i==maxVal-minVal){
				res=max(res,maxVal-minVal+1);	
			}
		}
	}
	cout<<res<<endl;
	return 0;
}

