#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
	return (a.second<b.second);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	vector<pair<int,int>> v;
	
	for(int i=0;i<n;i++){
		int st,et;
		cin>>st>>et;
		v.push_back(make_pair(st,et));	
	}
	sort(v.begin(),v.end(),sortbysec);
	int count = 0;
	
	int lastEndTime = 0;
	while(!v.empty()){
		if(v[0].first>lastEndTime){
			cout<<" Picking activity: ("<<v[0].first<<","<<v[0].second<<")\n";
			lastEndTime = v[0].second;
			count++;
		}
		v.erase(v.begin());
	}
	cout<<"Total activities that can be done: "<<count<<endl;
	return 0;
}

