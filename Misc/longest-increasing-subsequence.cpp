#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	//trial 1: when I think, I get that when I am looking at an element, I need to look back at all the elements to the left of it and check 
	// which one is less than my current element and also if I take my current element what is the max length of subsequence I can get
	// ISSUE ? If for element I look at all the elements behind it, I get an n^2 problem, is that okay?  --> YES !!!
	
	//So, the solution below is a DP solution and is of complexity O(n^2).
	//But, the optimal solution is O(nlogn), check the next code out to find that
	
	int n;
	cin>>n;
	
	vector<int> v;
	vector<int> dp;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		v.push_back(temp);
		dp.push_back(-1);
	}
	dp[0]=1;
	for(int i=1;i<n;i++){
		for(int j=0;j<i;j++){
			if(v[j]<v[i]){
				dp[i] = max(dp[i],1+dp[j]);
			}
		}
	}
	cout<<dp[n-1]<<endl;
	return 0;
}

