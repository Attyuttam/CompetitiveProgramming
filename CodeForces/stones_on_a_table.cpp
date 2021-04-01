#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	char lc;
	cin>>lc;
	int count=0;
	for(int i=1;i<n;i++){
		char t;
		cin>>t;
		if(t!=lc){
			lc=t;
		}else{
			count++;
		}
	}
	cout<<count<<endl;
	return 0;
}

