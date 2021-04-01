#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	long long n,m,a;
	cin>>n>>m>>a;
	
	
	cout<<setprecision(19)<<ceil((double)n/a)*ceil((double)m/a)<<endl;
	
	return 0;
}

