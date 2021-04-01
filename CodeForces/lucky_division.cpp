#include<bits/stdc++.h>
using namespace std;
bool isLucky(int n){
	while(n!=0){
		int r=n%10;
		//cout<<n<<" "<<r<<endl;
		if(!(r==4 || r==7)){
			//cout<<"--"<<r<<endl;
			return false;
		}
		n/=10;
	}
	return true;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int flag=0;
	for(int i=4;i<=n;i++){
		
		if(isLucky(i) && n%i==0){
			cout<<"YES"<<endl;
			flag=1;
			break;
		}
	}
	if(flag==0){
		cout<<"NO"<<endl;
	}
	return 0;
}

