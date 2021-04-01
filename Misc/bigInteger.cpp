#include<bits/stdc++.h>

using namespace std;

string addOne(string n){
	int c=1;
	string result = "";
	for(int i=n.length()-1;i>=0;i--){
		int val = n[i]-'0'+c;
		if(val>9){
			result+='0';
			c=1;
		}else{
			result+=(val+'0');
			c=0;
		}
	}
	if(c==1){
		result+='1';
	}
	reverse(result.begin(),result.end());
	return result;
	
}
int main(){
	string n;
	cin>>n;
	string result = addOne(n);
	cout<<result.length()<<endl;
}
