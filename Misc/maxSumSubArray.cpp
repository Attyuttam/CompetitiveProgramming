#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
void buildMaxSegmentTree(int *segmentTree, int index, int s,int e,int *arr){
	if(s>e)return;
	if(s==e){
		segmentTree[index]=arr[s];
		return;
	}
	int mid = (s+e)/2;
	buildMaxSegmentTree(segmentTree,2*index+1,s,mid,arr);
	buildMaxSegmentTree(segmentTree,2*index+2,mid+1,e,arr);
	segmentTree[index] = segmentTree[2*index+1]+segmentTree[2*index+2];
}
void print(int *a,int size){
	for(int i=0;i<size;i++){
		cout<<a[i]<<" ";
	}
	cout<<endl;
}
int findMax(int *segmentTree,int index,int s,int e,int i){
	if(s>e)return INT_MIN;
	if(i<s || i>e)return INT_MIN;
	if(s==e && i==s){
		return segmentTree[index];
	}else if(s==e && i!=s){
		return INT_MIN;
	}
	
	int mid = (s+e)/2;
	return max(segmentTree[index],max(findMax(segmentTree,2*index+1,s,mid,i),findMax(segmentTree,2*index+2,mid+1,e,i)));
	
}
int main(){
	int n;
	cin>>n;
	int *arr = new int[n];
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	
	int *segmentTree = new int[4*n+1];
	buildMaxSegmentTree(segmentTree,0,0,n-1,arr);
	for(int i=0;i<n;i++){
		cout<<findMax(segmentTree,0,0,n-1,i)<<" ";
	}
	cout<<endl;
	return 0;
}

