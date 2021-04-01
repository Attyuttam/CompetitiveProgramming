#include<bits/stdc++.h>
using namespace std;
// main logic is to find a minimum S[i] such that the position j with which I am comparing S[i] is such that the length
// of the sub array is within A and B
void maxSumSubArray(vector<int> v,int n,int a,int b){
	vector<int> partialSum;
	partialSum.push_back(v[0]);
	for(int i=1;i<n;i++){
		partialSum.push_back(partialSum[i-1]+v[i]);
	}
	deque<pair<int,int>> d;
	
	d.push_back(make_pair(partialSum[0],0));
	int ans=v[0];
	int leftPos = 0;
	int rightPos = 0;
	for(int i=1;i<n;i++){
		
		if(d.size()>0 && i-d.front().second>b){
			// if the current position - position of minimum Partial Sum exceeds b then its no use taking that minimum element, so delete that
			d.pop_front();
		}
		
		if(d.size()>0 && i-d.front().second>=a && i-d.front().second<=b && partialSum[i]-d.front().first>ans){
			// as we have discared all the invalid minimum elements, the front of the deque shall have a valid minimum element
			// So, we check whether the sum within the range is greater than what we have seen till now
			// If yes, then update
			
			ans = partialSum[i]-d.front().first;
			leftPos = d.front().second+1;
			rightPos = i;
		}
		
		while(!d.empty() && partialSum[i]<=d.back().first){
			d.pop_back();
		}
		d.push_back(make_pair(partialSum[i],i));
		
	}
	cout<<ans<<" "<<leftPos<<" "<<rightPos<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	int a,b;
	cin>>a>>b;
	
	vector<int> v;
	
	int temp;
	for(int i=0;i<n;i++){
		cin>>temp;
		v.push_back(temp);
	}
	
	maxSumSubArray(v,n,a,b);
	return 0;
}

