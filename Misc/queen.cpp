#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	
	int qr,qc;
	cin>>qr>>qc;
	qr=n-qr;
	qc-=1;
	
	vector<vector<int>> board;
	
	vector<pair<int,int>> ob;
	
	for(int i=1;i<=k;i++){
		int obr,obc;
		cin>>obr>>obc;
		
		ob.push_back(make_pair(n-obr,obc-1));
	}
	//qr,qc,ob,n
	
	int res=0;
	
	int i=qr-1;
	int j=qc+1;
	while(i>=0 && j<n){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i--;
		j++;
	}
	i=qr-1;
	j=qc-1;
	while(i>=0 && j>=0){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i--;
		j--;
	}
	i=qr+1;
	j=qc+1;
	while(i<n && j<n){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i++;
		j++;
	}
	i=qr+1;
	j=qc-1;
	while(i<n && j>=0){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i++;
		j--;
	}
	i=qr+1;
	j=qc;
	while(i<n){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i++;
	}
	i=qr-1;
	j=qc;
	while(i>=0){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		i--;
	}
	i=qr;
	j=qc-1;
	while(j>=0){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		j--;
	}
	i=qr;
	j=qc+1;
	while(j<n){
		if(find(ob.begin(),ob.end(),make_pair(i,j))!=ob.end()){
			break;
		}
		res++;
		j++;
	}
	
	cout<<res<<endl;
	return 0;
}

