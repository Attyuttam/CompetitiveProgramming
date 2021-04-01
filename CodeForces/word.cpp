#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;
	int countLower=0;
	for(int i=0;i<s.length();i++){
		if(islower(s[i])){
			countLower++;
		}
	}
	//cout<<countLower<<endl;
	if(countLower>=ceil((double)s.length()/2)){
		for(int i=0;i<s.length();i++){
			s[i]=tolower(s[i]);
		}
	}else{
		for(int i=0;i<s.length();i++){
			s[i]=toupper(s[i]);
		}
	}
	cout<<s<<endl;
	return 0;
}

