#include<bits/stdc++.h>
using namespace std;
int findMinNumBoats(vector<int> v,int n,int w,int b){
	sort(v.begin(),v.end());
	priority_queue<pair<int,int>> pq;
	int numBoats = 0;
	
	vector<bool> isTaken(n,false);
	
	int j=0;
	for(int i=n-1;i>=0;i--){
		// if first condition is okay, then push it into the priority queue
		while(j<i && v[i]+v[j]<=w){
			pq.push({v[j],j++});
		}
		
		if(isTaken[i])continue;
		
		//check for the second condition
		while(!pq.empty() && abs(v[i]-pq.top().first)<=b){
			if(isTaken[pq.top().second] || i==pq.top().second){
				pq.pop();
				continue;
			}
			isTaken[pq.top().second] = true;
			isTaken[i] = true;
			pq.pop();
			break;
		}
		numBoats++;
	}
	return numBoats;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,w,b;
	cin>>n>>w>>b;
	
	vector<int> v;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
	}	
	
	cout<<findMinNumBoats(v,n,w,b);
	return 0;
}

