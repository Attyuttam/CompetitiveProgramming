#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int k,d,n;
	cin>>k>>d>>n;
	
	int amt=0;
	if(n%2==0){
		amt=(n/2)*k*(n+1);
	}else{
		amt=((n+1)/2)*k*n;
	}
	cout<<max(0,amt-d)<<endl;
	return 0;
}

