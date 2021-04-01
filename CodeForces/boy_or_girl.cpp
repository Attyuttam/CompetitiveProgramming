#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	vector<char> v;
	cin>>s;
	
	for(int i=0;i<s.length();i++){
		if(!(find(v.begin(),v.end(),s[i])!=v.end())){
			v.push_back(s[i]);
		}
	}
	
	if(v.size()%2==0){
		cout<<"CHAT WITH HER!";
	}else{
		cout<<"IGNORE HIM!";
	}
	return 0;
}

