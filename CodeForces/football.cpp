#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	string s;
	cin>>s;
	
	char lc = s[0];
	int count=0;
	int flag=0;
	for(int i=1;i<s.length();i++){
		if(s[i]==lc){
			count++;
		}else{
			count=0;
			lc=s[i];
		}
		if(count==6){
			flag=1;
			break;
		}
	}
	if(flag==1){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}

