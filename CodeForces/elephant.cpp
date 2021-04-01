#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	
	long long count=0;
	while(n!=0){
		for(int i=v.size()-1;i>=0;i--){
			if(v[i]<=n){		
				count++;
				n-=v[i];
				break;
			}
		}
	}
	cout<<count<<endl;
	return 0;
}

