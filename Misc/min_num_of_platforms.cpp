#include<bits/stdc++.h>
using namespace std;
bool sortbysec(const pair<int,int> &a, const pair<int,int> &b){
	return (a.second<b.second);
}
int startTimeOfIncomingTrainGreaterThanDepartureTimeOfLastTrainInAnyPlatform(double st,map<int,vector<pair<double,double> > > m){
	for(auto it=m.begin();it!=m.end();it++){
		if(it->second[it->second.size()-1].second<=st){
			return it->first;
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	vector<pair<double,double>> v;
	
	for(int i=0;i<n;i++){
		double st,et;
		cin>>st>>et;
		v.push_back(make_pair(st,et));	
	}
	sort(v.begin(),v.end(),sortbysec);
	
	int numPlatform=0;
	map<int,vector<pair<double,double>>> m;
	
	
	//add the first train
	numPlatform++;
	m[numPlatform].push_back(v[0]);
	v.erase(v.begin());
	
	//add the other trains
	while(!v.empty()){
		int platform = startTimeOfIncomingTrainGreaterThanDepartureTimeOfLastTrainInAnyPlatform(v[0].first,m);
		if(platform==-1){
			m[++numPlatform].push_back(v[0]);
		}else{
			m[platform].push_back(v[0]);
		}
		v.erase(v.begin());
	}
	cout<<numPlatform<<endl;
	return 0;
}

