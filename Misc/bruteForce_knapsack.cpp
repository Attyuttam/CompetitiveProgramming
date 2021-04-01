#include<bits/stdc++.h>
using namespace std;
#define LL long long 
//RECURSIVE BRUTE FORCE
vector<pair<LL,LL> > wv;
LL W;
LL maxVal=0;
void calculate(int n,LL startIndex, LL endIndex,int loopNum,int maxLoopNum, LL currVal,LL currWeight){
	//cout<<startIndex<<" "<<endIndex<<" "<<loopNum<<" "<<maxLoopNum<<" "<<currVal<<" "<<currWeight<<endl;
	if(endIndex<=n && startIndex>=0 && startIndex<endIndex){
		if(loopNum<maxLoopNum){
			for(int i=1;startIndex+i<=endIndex;i++)
				calculate(n,startIndex+i,endIndex+1,loopNum+1,maxLoopNum,currVal+wv[startIndex].second,wv[startIndex].first+currWeight);
		}
			
		else if(loopNum==maxLoopNum){
			//cout<<currWeight+wv[startIndex].first<<" "<<currVal+wv[startIndex].second<<" "<<maxVal<<endl;
			if(currWeight+wv[startIndex].first<=W && currVal+wv[startIndex].second>maxVal){
				maxVal = currVal+wv[startIndex].second;
			}
			calculate(n,startIndex+1,endIndex,loopNum,maxLoopNum,currVal,currWeight);
		}		
	}
}
int main(){
	int n;	
	cin>>n>>W;

	for(int i=0;i<n;i++){
		LL v,w;
		cin>>w>>v;
		wv.push_back(make_pair(w,v));
	}
	for(int i=1;i<=n;i++){
		calculate(n,0,n-(i-1),1,i,0,0);	
	}
	cout<<maxVal;
	
	return 0;
}

