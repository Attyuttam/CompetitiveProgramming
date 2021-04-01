#include<bits/stdc++.h>
using namespace std;

void print(vector<vector<int>> v,int m, int n){
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<v[i][j]<<" ";
		}
		cout<<endl;
	}
}
vector<vector<int>> initialize(vector<vector<int>> v, int m,int n){
	for(int i=0;i<m;i++){
		vector<int> tmp;
		for(int j=0;j<n;j++){
			tmp.push_back(0);
		}
		v.push_back(tmp);
	}
	return v;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int m,n;
	cin>>m>>n;
	
	vector<vector<int>> a;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			int var;
			cin>>var;
			temp.push_back(var);
		}
		a.push_back(temp);
	}
	
	vector<vector<int>> rangeSum;
	rangeSum = initialize(rangeSum,m,n);
	
	rangeSum[0][0]=a[0][0];
	
	for(int i=1;i<n;i++){
		rangeSum[0][i]=rangeSum[0][i-1]+a[0][i];	
	}
	for(int i=1;i<m;i++){
		rangeSum[i][0]=rangeSum[i-1][0]+a[i][0];	
	}
	for(int i=1;i<m;i++){
		for(int j=1;j<n;j++){
			rangeSum[i][j]=rangeSum[i-1][j]+rangeSum[i][j-1]-rangeSum[i-1][j-1]+a[i][j];
		}
	}
	cout<<endl;
	print(a,m,n);
	cout<<endl;
	print(rangeSum,m,n);

	int q;
	cin>>q;
	while(q--){
		int r1,c1,r2,c2;
		cin>>r1>>c1>>r2>>c2;
		int res = 0;
		
		if(r1-1>=0 && c1-1>=0){
			res = rangeSum[r2][c2]-rangeSum[r1-1][c2]-rangeSum[r2][c1-1]+rangeSum[r1-1][c1-1];
		}else if(r1-1>=0){
			res = rangeSum[r2][c2]-rangeSum[r1-1][c2];
		}else if(c1-1>=0){
			res = rangeSum[r2][c2]-rangeSum[r2][c1-1];
		}else{
			res = rangeSum[r2][c2];
		}
		cout<<"\nAnswer: "<<res<<endl;
	}	
	return 0;
}

