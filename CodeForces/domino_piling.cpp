#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int m,n;
	cin>>m>>n;
	
	vector< vector<int>> v;
	for(int i=0;i<m;i++){
		vector<int> temp;
		for(int j=0;j<n;j++){
			temp.push_back(0);
		}		
		v.push_back(temp);
	}	
	int count=0;
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(v[i][j]==0){
				v[i][j]=1;
				int flag=0;
				if(i-1>0 && i-1<m && v[i-1][j]==0){
					v[i-1][j]=1;
					flag=1;
					count++;
				}else if(i+1>0 && i+1<m && v[i+1][j]==0){
					v[i+1][j]=1;
					flag=1;
					count++;
				}else if(j-1>0 && j-1<n && v[i][j-1]==0){
					v[i][j-1]=1;
					flag=1;
					count++;
				}else if(j+1>0 && j+1<n && v[i][j+1]==0){
					v[i][j+1]=1;
					flag=1;
					count++;
				}
				if(flag==0){
					v[i][j]=0;
				}
			}
		}		
	}
	cout<<count<<endl;
	return 0;
}

