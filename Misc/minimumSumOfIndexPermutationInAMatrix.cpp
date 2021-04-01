#include<bits/stdc++.h>
#include<limits.h>
using namespace std;
void calculateMin(vector< vector<int> > A,int n){
	vector<int> listOfIntegers;
	vector<int> minPermList;
	for(int i=0;i<n;i++){
		listOfIntegers.push_back(i);
	}
	long min=LONG_MAX;
	do{
		long sum=0;	
		for(int i=0;i<n-1;i++){
			sum+=A[listOfIntegers[i]][listOfIntegers[i+1]];
		}
		if(sum<min){
			min=sum;
			minPermList=listOfIntegers;
		}
	}while(next_permutation(listOfIntegers.begin(), listOfIntegers.end()));
	
	for(int i=0;i<n;i++){
		cout<<minPermList[i]+1<<" ";
	}
	cout<<endl;
}
int main(){
	//take input n
	int n;
	cin>>n;
	//take input the matrix
	vector< vector<int> > A;
	for(int i=0;i<n;i++){
		vector<int> tempVec;
		for(int j=0;j<n;j++){
			int temp;
			cin>>temp;
			tempVec.push_back(temp);
		}
		A.push_back(tempVec);
	}
	//calculate minimum
	calculateMin(A,n);
}
