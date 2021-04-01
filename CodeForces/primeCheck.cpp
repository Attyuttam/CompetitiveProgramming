#include<bits/stdc++.h>
using namespace std;
bool prime(int n){
	if(n<=2)return false;
	cout<<"sqrt("<<n<<") = "<<sqrt(n)<<endl;
	for(int i=2;i<=sqrt(n);i++){
		if(n%i==0)return false;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<prime(6);
	return 0;
}

