#include<bits/stdc++.h>
using namespace std;
int rec(int i,int n){
	if(i<n){
		cout<<"X"<<endl;
		int v = rec(i+1,n);
		
		cout<<"function: rec("<<i<<","<<n<<") will return: "<<v+1<<endl;
		return v+1;
	}
	cout<<"No more recursion: "<<i<<endl;
	return i;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout<<"finally received: "<<rec(5,7)<<endl;
	return 0;
}

