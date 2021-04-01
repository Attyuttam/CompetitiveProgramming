//Given n ropes with different lengths, we need to connect then into one. We can connect 2 ropes at a time and the cost of doing that is the sum
//of their lengths.
//Ex: Given ropes 4,3,2,6
// first we take 2 and 3, so the cost of connecting them is 5
// now we have 3 ropes of length 4 , 5 and 6
// now if we pick 4 and 5, the cost of connecting them is 9
// we now have two ropes of length 6 and 9 and we connect them the cost of which is 15
// we finally have only one rope of length 15 and hence no connections possible.
//Thus, the total cost is the intermediate cost at each connection, 5+9+15=29 

#include<bits/stdc++.h>
using namespace std;
void findMinCost(priority_queue<int> p){
	int sum = 0;
	while(p.size()>1){
		int min1 = abs(p.top());
		p.pop();
		int min2 = abs(p.top());
		p.pop();
		sum+=(min1+min2);
		p.push(-(min1+min2));
	}
	cout<<sum<<endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	priority_queue<int> p;
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		p.push(-temp);
	}
	findMinCost(p);
	return 0;
}

