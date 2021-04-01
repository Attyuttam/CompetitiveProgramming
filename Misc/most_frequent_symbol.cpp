#include<bits/stdc++.h>
using namespace std;
#define VP vector< pair<char,int> >
VP combineLeftAndRightTrees(VP firstChild, VP secondChild){
	VP left = firstChild;
	VP right = secondChild;
	VP res;
	for(int i=0;i<left.size();i++){
		int sum=left[i].second;
		for(int j=0;j<right.size();j++){
			if(left[i].first == right[j].first){
				sum+=right[j].second;
				right.erase(right.begin()+j);
			}
		}
		res.push_back(make_pair(left[i].first,sum));
	}
	for(int i=0;i<right.size();i++){
		res.push_back(make_pair(right[i].first,right[i].second));
	}
	return res;
}
void buildSegmentTree(VP *segmentTree,int index,int s,int e,string str){
	if(s>e)return;
	if(s==e){
		VP v;
		v.push_back(make_pair(str[s],1));
		segmentTree[index] = v;
		return;
	}
	int mid = (s+e)/2;
	buildSegmentTree(segmentTree,2*index+1,s,mid,str);
	buildSegmentTree(segmentTree,2*index+2,mid+1,e,str);
	segmentTree[index] = combineLeftAndRightTrees(segmentTree[2*index+1],segmentTree[2*index+2]);
}
void printSegmentTree(VP *segmentTree, int n){
	for(int i=0;i<n;i++){
		for(int j=0;j<segmentTree[i].size();j++){
			cout<<segmentTree[i][j].first<<":"<<segmentTree[i][j].second<<" -- ";
		}
		cout<<endl;
	}
}
VP findFrequentSymbol(VP *segmentTree,int index,int s,int e,int ql,int qr){
	// no overlap
	if(qr<s || ql>e){
		VP temp;
		return temp;
	}
	//exact range or leaf
	if(((s==e && ql>=s && s<=qr) || (s>=ql && e<=qr))){
		return segmentTree[index];
	}
	int mid=(s+e)/2;
	return combineLeftAndRightTrees(findFrequentSymbol(segmentTree,2*index+1,s,mid,ql,qr),findFrequentSymbol(segmentTree,2*index+2,mid+1,e,ql,qr));
}
void printMostFrequentSymbol(VP res){
	if(res.size()>0){
		char symbol = res[0].first;
		int max = res[0].second;
		
		for(int i=1;i<res.size();i++){
			if(res[i].second>=max){
				max=res[i].second;
				symbol=res[i].first;
			}
		}
		cout<<"Most frequent symbol: "<<symbol<<endl;
	}
}
int main(){
	string s;
	cin>>s;
	VP *segmentTree = new VP[4*s.length() + 1];
	buildSegmentTree(segmentTree,0,0,s.length()-1,s);
	printSegmentTree(segmentTree,4*s.length()+1);
	int numQ;
	cin>>numQ;
	while(numQ--){
		int ql,qr;
		cin>>ql>>qr;
		VP res = findFrequentSymbol(segmentTree,0,0,s.length()-1,ql-1,qr-1);
		printMostFrequentSymbol(res);
	}
	return 0;
}

