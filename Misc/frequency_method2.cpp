#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
int findNumOcc(int i,vector<pair<int,int> > v){
	vector<pair<int,int>> :: iterator itr;
	int count=0;
	for(itr=v.begin();itr!=v.end();itr++){
		if(i>=itr->first && i<=itr->second)count++;
	}
	return count;
}
int main(){
	int n;
	cin>>n;
	vector<pair<int,int> >v;
	int min=INT_MAX;
	int max=INT_MIN;
	
	int q1,q2;
	while(n--){
		cin>>q1>>q2;
		if(q1<min){
			min=q1;
		}
		if(q2>max){
			max=q2;
		}
		v.push_back(make_pair(q1,q2));
	}
	for(int i=min;i<=max;i++){
		int numOcc = findNumOcc(i,v);
		cout<<i<<" "<<numOcc<<endl;
	}
	return 0;
}

