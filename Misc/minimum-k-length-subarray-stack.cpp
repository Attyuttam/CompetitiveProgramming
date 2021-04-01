#include<bits/stdc++.h>
using namespace std;
stack<pair<int,int>> initialize(vector<int> v,int k){
	stack<pair<int,int>> s;
	for(int i=0;i<k;i++){
		if(s.empty()){
			s.push(make_pair(v[i],i));
		}else{
			while(v[i]<s.top()){
				s.pop();
			}
			s.push(make_pair(v[i],i));
		}
	}
	return s;
}
void printMinInRange(vector<int> v, int n,int k){
	int sp=0, ep=k-1;
	stack<pair<int,int>> s;
	s = initialize(v,k);
	while(ep<n){
		cout<<s.
		//HENCE, we cannot use stack as we would need the lowermost element of the stack which has the minimum but stack can only return the
		//topmost element, hence in this case, we work on the back side of the DS but need the FS, hence a queue comes into picture, but
		//as we need to remove elements from the back when a smaller element comes up to ensure that the queue is in increasing order and also need
		//to remove elements from the front to provide the minimum element, this implies that we would need a dequeue !
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

