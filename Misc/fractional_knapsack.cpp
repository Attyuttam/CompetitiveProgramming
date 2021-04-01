#include<bits/stdc++.h>
using namespace std;

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,s;
	cin>>n>>s;
	priority_queue<pair<double,int>> wv;
	
	for(int i=0;i<n;i++){
		int w,v;
		cin>>w>>v;
		wv.push(make_pair((v/(double)w),w));
	}

	double kv = 0.0;
	while(s>0 && !wv.empty()){
		
		kv+=wv.top().first;
		pair<double,int> temp_top = wv.top();
		temp_top.second = temp_top.second-1;
		wv.pop();
		if(temp_top.second>0){
			wv.push(make_pair(temp_top.first,temp_top.second));	
		}
		
		s--;
		
	}
	cout<<"Net value: "<<kv<<endl; 
	return 0;
}

