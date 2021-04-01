#include<bits/stdc++.h>
using namespace std;
int numberOfDistinctElements(map<int,int> f){
	map<int, int>::iterator itr; 
	int c=0;
    for (itr = f.begin(); itr != f.end(); ++itr) { 
        if(itr->second>0)c++;
    } 
    return c;
}
int findMaxArraySizeWithKDistinctElements(int k, vector<int> v){
	map<int,int> freq;
	
	int l=0,r=1;
	int n=v.size();
	
	int currentSubArraySize=1;
	int bestSubArraySize=1;	
	freq.insert(pair<int, int>(v[0], 1));

	while(l<n){		
		while(r<n){
			
			std::map<int, int>::iterator it = freq.find(v[r]); 
			
			if (it != freq.end())
				it->second = freq[v[r]]+1;
			else
				freq.insert(pair<int, int>(v[r], 1));
				
			currentSubArraySize+=1;
			
			if(numberOfDistinctElements(freq)>k){
				currentSubArraySize-=2;
				freq[v[l]]--;
				l++;
				freq[v[r]]--;
				break;
			}
			r++;
		}
		bestSubArraySize = max(currentSubArraySize+1,bestSubArraySize);
	
		if(r==n){
			return bestSubArraySize;
		}
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	vector<int> v;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}
	cout<<findMaxArraySizeWithKDistinctElements(k,v);
	return 0;
}

