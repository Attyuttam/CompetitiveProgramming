#include<bits/stdc++.h>

using namespace std;
string generateNewStringAfterComparison(string s1,string s2,int m){
	vector<int> posList;
	for(int i=0;i<m;i++){
		if(s1[i]!=s2[i]){
			posList.push_back(i);
		}
		if(posList.size()>2)return "";
	}
	if(posList.size()==1)return s1;
	string ans;
	ans=s1;
	ans[posList[1]]=s2[posList[1]];
	//cout<<"-->"<<posList.size()<<" -- "<<posList[0]<<" -- "<<posList[1]<<endl;
	//cout<<"==>"<<ans<<endl;
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		
		string ans;
		cin>>ans;
		n--;
		
		string s;
		while(n--){	
			cin>>s;
			ans = generateNewStringAfterComparison(ans,s,m);
		}
		if(ans=="")
			cout<<"-1"<<endl;
		else
			cout<<ans<<endl;
	}
	return 0;
}

