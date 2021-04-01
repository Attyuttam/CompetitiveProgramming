#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	
	int x=0;
	while(n--){
		string ex;
		cin>>ex;
		if(ex[0]=='+'||ex[ex.length()-1]=='+'){
			x++;
		}else{
			x--;
		}
	}
	cout<<x<<endl;
	return 0;
}

