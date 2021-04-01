#include<bits/stdc++.h>
#include<limits.h>
using namespace std;

//building a min range segment tree
void buildSegmentTree(int *segmentTree, int *orig_arr,int index, int s, int e){
	//Base case 1 --> invalid segment;
	if(s>e)return;
	
	//Base case 2 --> leaf node
	if(s==e){
		segmentTree[index]=orig_arr[s];
		return;
	}	
	//calculate mid
	int mid = (s+e)/2;
	
	//build left subtree
	buildSegmentTree(segmentTree,orig_arr,2*index+1,s,mid);
	
	//build right subtree
	buildSegmentTree(segmentTree,orig_arr,2*index+2,mid+1,e);
	
	//set the value at index in segmentTree
	segmentTree[index] = min(segmentTree[2*index+1],segmentTree[2*index+2]);
	
}
int findMin(int *segmentTree,int ql, int qr,int s,int e,int index){
	//complete overlap
	if(s>=ql && qr>=e){
		return segmentTree[index];
	}
	//no overlap
	if(qr<s||e<ql){
		return INT_MAX;
	}
	//partial overlap
	int mid = (s+e)/2;
	return min(findMin(segmentTree,ql,qr,s,mid,2*index+1),findMin(segmentTree,ql,qr,mid+1,e,2*index+2));
}
void printSegmentTree(int *tree,int n){
	cout<<"The segment Tree: "<<endl;
	for(int i=0;i<n;i++){
		cout<<tree[i]<<" ";
	}
	cout<<endl;
	cout<<endl;
}
void updateNode(int *segmentTree,int index,int s,int e,int ind,int val){
	//index is out of the range
	if(ind<s || ind>e){
		return ;
	}
	//leaf node reached
	if(s==e && s==ind){
		segmentTree[index]=val;
		return ;
	}
	//ind lies within the range of s and e
	if(ind>=s && ind<=e){
		int mid = (s+e)/2;
		updateNode(segmentTree,2*index+1,s,mid,ind,val);
		updateNode(segmentTree,2*index+2,mid+1,e,ind,val);
		segmentTree[index] = min(segmentTree[2*index+1],segmentTree[2*index+2]);
	}
}
void updateRange(int *segmentTree,int index,int s,int e,int qs,int qe,int val){
	//no overlap
	if(qe<s||qs>e){
		return;
	}
	//complete overlap of the leaf node
	if(s==e && s>=qs && s<=qe){
		segmentTree[index]+=val;
		return;
	}
	//partial overlap
	int mid=(s+e)/2;
	updateRange(segmentTree,2*index+1,s,mid,qs,qe,val);
	updateRange(segmentTree,2*index+2,mid+1,e,qs,qe,val);
	segmentTree[index]=min(segmentTree[2*index+1],segmentTree[2*index+2]);
}
void executeMinimumFind(int *segmentTree,int n){
	cout<<"Enter number of Queries for finding minimum: ";
	int numQ;
	cin>>numQ;
	int ql,qr;
	cout<<endl;
	while(numQ--){
		cout<<"Enter start and end range: ";
		cin>>ql>>qr;
		int min = findMin(segmentTree,ql,qr,0,n-1,0);
		cout<<"Minimum in range: "<<ql<<" to "<<qr<<" is: "<<min<<endl;
	}
	
}
void executeSingleValueUpdate(int *segmentTree,int n){
	int numQ;
	cout<<"Enter number of Queries for single value update: ";
	cin>>numQ;
	int ind;
	int val;
	while(numQ--){	
		cout<<"Enter index to be updated: ";
		cin>>ind;
		cout<<endl;
		cout<<"Enter the value with which it is to be updated: ";
		cin>>val;
		updateNode(segmentTree,0,0,n-1,ind,val);
		printSegmentTree(segmentTree,4*n+1);
	}
	
}
void executeRangeValueUpdate(int *segmentTree,int n){
	int numQ;
	cout<<"Enter number of Queries for range value update: ";
	cin>>numQ;
	int rs,re;
	int val;
	while(numQ--){	
		cout<<"Enter start and end value of range to be updated: ";
		cin>>rs>>re;
		cout<<endl;
		cout<<"Enter the value with which is to be added to the values in the range: ";
		cin>>val;
		updateRange(segmentTree,0,0,n-1,rs,re,val);
		printSegmentTree(segmentTree,4*n+1);
	}
	
}
void buildSumSegmentTree(int *sumSegmentTree,int index,int s,int e,int *orig_arr){
	if(s>e)return;
	if(s==e){
		sumSegmentTree[index]=orig_arr[s];
		return;
	}
	int mid = (s+e)/2;
	buildSumSegmentTree(sumSegmentTree,2*index+1,s,mid,orig_arr);
	buildSumSegmentTree(sumSegmentTree,2*index+2,mid+1,e,orig_arr);
	sumSegmentTree[index]= sumSegmentTree[2*index+1]+sumSegmentTree[2*index+2];
}
int findRangeSum(int *sumSegmentTree,int index,int s,int e,int ql,int qe){
	if(qe<s||ql>e)return 0;
	if(s>e)return 0;
	if(s==e || (ql==s&&qe==e))return sumSegmentTree[index];
	int mid=(s+e)/2;
	return findRangeSum(sumSegmentTree,2*index+1,s,mid,ql,qe) + findRangeSum(sumSegmentTree,2*index+2,mid+1,e,ql,qe);
}
void executeRangeSum(int n,int *orig_arr){
	int numQ;
	cout<<"Enter number of Queries for range sum: ";
	cin>>numQ;
	int ql,qe;
	int *sumSegmentTree = new int[4*n+1];
	buildSumSegmentTree(sumSegmentTree,0,0,n-1,orig_arr);
	while(numQ--){
		cout<<"Enter start and end value of range to be updated: ";
		cin>>ql>>qe;
		cout<<endl;
		cout<<findRangeSum(sumSegmentTree,0,0,n-1,ql,qe)<<endl;
	}
	return;
}
int main(){
	int n;
	cout<<"Enter length of array: ";
	cin>>n;
	int *orig_arr = new int[n];
	cout<<"\nEnter elements of the array: "<<endl;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		orig_arr[i] = temp;
	}
	int *segmentTree = new int[4*n+1];
	//building the minimum storing segment tree
	buildSegmentTree(segmentTree,orig_arr,0,0,n-1);
	printSegmentTree(segmentTree,4*n+1);
	int ch;
	int flag=1;
	while(flag==1){
		cout<<"1.Find minimum"<<endl;
		cout<<"2.Single value update"<<endl;
		cout<<"3.Range value update"<<endl;
		cout<<"4.Range sum"<<endl;
		cout<<"Select your option(1/2/3/4)(press any key to exit): ";
		cin>>ch;
		switch(ch){
			case 1: {executeMinimumFind(segmentTree,n);break;}
			case 2: {executeSingleValueUpdate(segmentTree,n);break;}
			case 3: {executeRangeValueUpdate(segmentTree,n);break;}
			case 4: {executeRangeSum(n,orig_arr);break;}
			default: {
				flag=0;
				break;
			}
		}
	}
	return 0;
}

