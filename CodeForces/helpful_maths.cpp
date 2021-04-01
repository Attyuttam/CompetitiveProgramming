#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;
	
	vector<int> v;
	for(int i=0;i<s.length();i++){
		if(s[i]!='+'){
			v.push_back(s[i]-'0');
		}
	}
	sort(v.begin(),v.end());
	string res="";
	for(int i=0;i<v.size();i++){
		res=res+to_string(v[i])+"+";
	}
	res.erase(res.length()-1,1);
	cout<<res<<endl;
	
	return 0;
}

