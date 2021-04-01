#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int Ai,Aj;
	for(int i=0;i<5;i++){
		int flag=0;
		for(int j=0;j<5;j++){
			int t;
			cin>>t;
			if(t==1){
				flag=1;
				Ai=i+1;
				Aj=j+1;
				break;
			}
		}
		if(flag==1){
			break;
		}
	}
	cout<<abs(Ai-3)+abs(Aj-3)<<endl;
	return 0;
}

