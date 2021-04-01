#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	cin>>n;
	
	int q1,q2;
	map<int, int> m;
	
	map<int, int>::iterator itr; 

	while(n--){
		cin>>q1>>q2;
		for(int i=q1;i<=q2;i++){
			int valToInsert = m[i]+1;
			if((itr = m.find(i)) != m.end())
			{
     			int curr = itr->second; // current number of occurrences
     			m.erase(i);
     			m.insert(make_pair(i, curr + 1)); 
			}
		}
	}

	for(itr = m.begin();itr!=m.end();itr++){
		cout<<itr->first<<" -- "<<itr->second<<endl;
	}
	return 0;
}

