#include<bits/stdc++.h>
#define ut uint64_t
using namespace std;
string check(ut n){
	if(n%2!=0){
		return "YES";
	}
	for(ut i =3;i<=sqrt(n);i+=2){
		if(n%i==0){
			return "YES";
		}
	}
	return "NO";
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	ut t;
	cin>>t;
	while(t--){
		ut n;
		cin>>n;
		cout<<check(n)<<endl;
	}
	

	return 0;
}

