#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin>>n;
	
	int flag=0;
	
	for(int i=2;i<=(n/2);i++){
		if(i%2==0 && (n-i)%2==0){
			cout<<"YES";
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"NO";
	}
	return 0;
}

