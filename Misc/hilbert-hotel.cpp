//https://codeforces.com/contest/1345/problem/C
#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int t;
	cin>>t;
	while(t--){
		int flag=0;
		int n;
		cin>>n;
		vector<int> foundRooms;
		vector<int> v;
		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			v.push_back(temp);
		}
		int f=0;
		for(int i=0;i<n;i++){
			int val = (i%n+(v[i]%n+n))%n;
			auto it = find(foundRooms.begin(),foundRooms.end(),val);
			if(it!=foundRooms.end()){
				f=1;
				cout<<"NO"<<endl;
				break;
			}else{
				foundRooms.push_back(val);
			}
		}
		if(f==0){
			cout<<"YES\n";
		}
		
	}
	
	return 0;
}

