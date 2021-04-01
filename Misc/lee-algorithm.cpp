#include<bits/stdc++.h>
using namespace std;
struct cellDet{
	int x;
	int y;
	int cost;
};
int findShortestPath(vector<vector<int>> v, int sx, int sy,int dx,int dy){
	vector<vector<int>> visited(v.size(),vector<int>(v[0].size(),0));
	queue<cellDet> q;
	struct cellDet cell;
	
	cell.x=sx;
	cell.y=sy;
	cell.cost=0;
	
	q.push(cell);
	
	while(!q.empty()){
		
		struct cellDet currentCell = q.front();
		q.pop();
		
		
		int i = currentCell.x;
		int j = currentCell.y;
		int cost = currentCell.cost;
		visited[i][j] = 1;
		if(i == dx && j == dy){
			return cost;
		}
		
		if(i-1>=0 && visited[i-1][j]==0 && v[i-1][j]==1){
			struct cellDet neighborCell;
			neighborCell.x = i-1;
			neighborCell.y = j;
			neighborCell.cost = cost+1;
			q.push(neighborCell);
		}
		if(i+1<v.size() && visited[i+1][j]==0 && v[i+1][j]==1){
			struct cellDet neighborCell;
			neighborCell.x = i+1;
			neighborCell.y = j;
			neighborCell.cost = cost+1;
			q.push(neighborCell);
		}
		if(j-1>=0 && visited[i][j-1]==0 && v[i][j-1]==1){
			struct cellDet neighborCell;
			neighborCell.x = i;
			neighborCell.y = j-1;
			neighborCell.cost = cost+1;
			q.push(neighborCell);
		}
		if(j+1<v[0].size() && visited[i][j+1]==0 && v[i][j+1]==1){
			struct cellDet neighborCell;
			neighborCell.x = i;
			neighborCell.y = j+1;
			neighborCell.cost = cost+1;
			q.push(neighborCell);
		}
	}
	return -1;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> v;
	
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<m;j++){
			int tmp;
			cin>>tmp;
			temp.push_back(tmp);
		}
		v.push_back(temp);
	}
	
	int sx,sy,dx,dy;
	cin>>sx>>sy>>dx>>dy;
	
	cout<<findShortestPath(v,sx,sy,dx,dy)<<endl;
	
	return 0;
}

