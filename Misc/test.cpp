#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
	int r,c;
	for(int i=1;i<=50;i++){
		for(int j=1;j<=50;j++){
			r=i;
			c=j;
			cout<<floor((c-1)/3.0)<<endl;
			cout<<floor(r/2.0)<<endl;
			long val = floor(r/2.0)*c + (floor((c-1)/3.0)*2.0 + ((c-1)%3==1?0:1) + 1)*(r-floor(r/2.0));
			cout<<r<<"--"<<j<<" : "<<val<<endl; 
		}
		
	}
	return 0;
}

