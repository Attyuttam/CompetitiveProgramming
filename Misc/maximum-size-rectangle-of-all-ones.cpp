#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> buildTower (vector<vector<int>> arr,int n,int m){
	vector<vector<int>> tower = arr;
	for(int i=1;i<n;i++){
		for(int j=0;j<m;j++){
			if(arr[i][j] == 0){
				tower[i][j] = 0;	
			}
			else{
				tower[i][j] = tower[i-1][j] + tower[i][j];
			}
		}
	}
	return tower;
}
void print(vector<vector<int>> mat){
	for(int i=0;i<mat.size();i++){
		for(int j=0;j<mat[i].size();j++){
			cout<<setw(3)<<mat[i][j]<<" ";
		}
		cout<<endl;
	}
}
vector<pair<int,int> > nextSmallerElementToTheRight(vector<int> v){
	stack<pair<int,int>> st;
	vector<pair<int, int> > resVec (v.size(), std::make_pair(-1, -1));
	
	for(int i=0;i<v.size();i++){
		int tmp = v[i];
		
		while(st.size()>0 && tmp<st.top().first){
		
			pair<int,int> topEl = st.top();
			st.pop();
			resVec[topEl.second]=make_pair(tmp,i);
		}
		st.push(make_pair(tmp,i));
	}
	return resVec;
}
vector<pair<int,int>> nextSmallerElementToTheLeft(vector<int> v){
	stack<pair<int,int>> st;
	vector<pair<int, int> > resVec (v.size(), std::make_pair(-1, -1));
	
	for(int i=v.size();i>=0;i--){
		int tmp = v[i];
		
		while(st.size()>0 && tmp<st.top().first){
			pair<int,int> topEl = st.top();
			st.pop();
			resVec[topEl.second]=make_pair(tmp,i);
		}
		st.push(make_pair(tmp,i));
	}
	return resVec;
}
int getMaxRectInTower(vector<int> v){
	vector<pair<int,int>> resVecR = nextSmallerElementToTheRight(v);
	vector<pair<int,int>> resVecL = nextSmallerElementToTheLeft(v);
	
	auto itR = resVecR.begin();
	auto itL = resVecL.begin();
	int maxArea = INT_MIN;
	int i=0;
	while(i<v.size() && itR!=resVecR.end() && itL!=resVecL.end()){
		if(itL->first!=-1 && itR->first!=-1){
			if((v[i]*(itR->second-itL->second-1))>maxArea){
				maxArea = v[i]*(itR->second-itL->second-1);
			}	
		}else if(itL->first == -1 &&  itR->first!=-1){
			if((itR->second)*v[i]>maxArea){
				maxArea = (itR->second)*v[i];
			}
		}else if(itL->first != -1 &&  itR->first==-1){
			if((v.size()-itL->second-1)*v[i]>maxArea){
				maxArea = (v.size()-itL->second-1)*v[i]; 
			}
		}else{
			int res = v.size()*v[i];
			if(res>maxArea){
				maxArea = res;
			}
		}
		i++;
		itL++;
		itR++;
	}
	if(maxArea==INT_MIN){
		return *max_element(v.begin(),v.end());
	}else{
		return maxArea;
	}
}
int maxRect(vector<vector<int>> arr,int n,int m){
	vector<vector<int>> tower = buildTower(arr,n,m);
	int ans = INT_MIN;
	for(int i=0;i<n;i++){
		ans = max(ans,getMaxRectInTower(tower[i]));
	}
	return ans;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n,m;
	cin>>n>>m;
	
	vector<vector<int>> arr;
	
	for(int i=0;i<n;i++){
		vector<int> temp;
		for(int j=0;j<m;j++){
			int tmp;
			cin>>tmp;
			temp.push_back(tmp);
		}
		arr.push_back(temp);
	}
	cout<<maxRect(arr,n,m)<<endl;
	return 0;
}

