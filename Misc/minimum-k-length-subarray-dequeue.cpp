#include<bits/stdc++.h>
using namespace std;
void printMinInRange(vector<int> v,int n,int k){
	int i;
	int sv = 0;//starting value
	deque<pair<int,int>> d;
	
	while(sv<=n-k){
		i=sv;
		while(i<sv+k){
			if(d.empty()){
				d.push_back(make_pair(v[i],i));
			}else{
				while(!d.empty() && d.back().first>v[i]){
					d.pop_back();
				}
				d.push_back(make_pair(v[i],i));
			}
			i++;
		}
		while(!d.empty() && (d.front().second<sv || d.front().second>=sv+k)){
			d.pop_front();
		}
		cout<<d.front().first<<" ";
		sv++;
	}
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,k;
	cin>>n>>k;
	vector<int> v;
	for(int i=0;i<n;i++){
		int tmp;
		cin>>tmp;
		v.push_back(tmp);
	}
	printMinInRange(v,n,k);
	return 0;
}

