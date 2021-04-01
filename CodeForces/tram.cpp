#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n;
	cin>>n;
	
	int minPersonInTrain=0;
	int currPersonInTrain=0;
	while(n--){
		int a,b;
		
		cin>>a>>b;//a exit and b enter
		
		currPersonInTrain=currPersonInTrain-a+b;
		if(currPersonInTrain>minPersonInTrain){
			minPersonInTrain=currPersonInTrain;
		}
		
		
	}
	cout<<minPersonInTrain<<endl;
	return 0;
}

