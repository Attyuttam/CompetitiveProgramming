#include<bits/stdc++.h>
using namespace std;
string abbreviate(string s){
	int len = s.length();
	if(len>10){
		
		return s[0]+to_string(len-2)+s[len-1];
	}
	return s;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	while(n--){
		string s;
		cin>>s;
		cout<<abbreviate(s)<<endl;
	}
	return 0;
}

