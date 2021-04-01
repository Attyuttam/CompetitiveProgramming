#include<bits/stdc++.h>
using namespace std;
int parent(int ind){
	return (ind-1)/2;
}
vector<pair<int,int>> insertIntoMaxHeap(vector<pair<int,int>> maxHeap, int val,int pos){
	maxHeap.push_back(make_pair(val,pos));
	int currPos = maxHeap.size()-1;
	while(currPos!=0){
		int parentOfCurrPos = parent(currPos);
		if(maxHeap[parentOfCurrPos].first<maxHeap[currPos].first){
			pair<int,int> temp;
			temp = maxHeap[parentOfCurrPos];
			maxHeap[parentOfCurrPos] = maxHeap[currPos];
			maxHeap[currPos]=temp;
		}
		currPos = parentOfCurrPos;
	}
	return maxHeap;
}
vector<pair<int,int>> insertIntoMinHeap(vector<pair<int,int>> minHeap, int val,int pos){
	minHeap.push_back(make_pair(val,pos));
	int currPos = minHeap.size()-1;
	while(currPos!=0){
		int parentOfCurrPos = parent(currPos);
		if(minHeap[parentOfCurrPos].first>minHeap[currPos].first){
			pair<int,int> temp;
			temp = minHeap[parentOfCurrPos];
			minHeap[parentOfCurrPos] = minHeap[currPos];
			minHeap[currPos]=temp;
		}
		currPos = parentOfCurrPos;
	}
	return minHeap;
}

void print(vector<pair<int,int>> heap){
	for(int i=0;i<heap.size();i++){
		cout<<heap[i].first<<" -- "<<heap[i].second<<" , ";
	}
	cout<<endl;
}
int main(){
	int n;
	cin>>n;
	vector< pair<int,int> > maxHeap;
	vector< pair<int,int> > minHeap;
	int pos=1;
	while(n--){
		int val;
		cin>>val;
		maxHeap = insertIntoMaxHeap(maxHeap,val,pos);
		minHeap = insertIntoMinHeap(minHeap,val,pos);
		pos++;
		cout<<min(maxHeap[0].second,minHeap[0].second)<<" "<<max(maxHeap[0].second,minHeap[0].second)<<endl;
		//print(maxHeap);
		//print(minHeap);
	}
	return 0;
}

