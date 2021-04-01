#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s;
	cin>>s;
	vector<bool> flag;
	flag.push_back(false);
	flag.push_back(false);
	flag.push_back(false);
	flag.push_back(false);
	flag.push_back(false);
	int pos=0;
	
	for(int i=pos;i<s.length();i++){
		if(s[i]=='h'){
			flag[0]=true;
			pos=i+1;
			break;
		}
	}
	for(int i=pos;i<s.length();i++){
		if(s[i]=='e'){
			flag[1]=true;
			pos=i+1;
			break;
		}
	}
	for(int i=pos;i<s.length();i++){
		if(s[i]=='l'){
			flag[2]=true;
			pos=i+1;
			break;
		}
	}
	for(int i=pos;i<s.length();i++){
		if(s[i]=='l'){
			flag[3]=true;
			pos=i+1;
			break;
		}
	}
	for(int i=pos;i<s.length();i++){
		if(s[i]=='o'){
			flag[4]=true;
			pos=i+1;
			break;
		}
	}
	bool f=true;
	for(int i=0;i<flag.size();i++){
		if(flag[i]==false){
			f=false;
			cout<<"NO"<<endl;
			break;
		}
	}
	if(f==true){
		cout<<"YES"<<endl;
	}
	return 0;
}

