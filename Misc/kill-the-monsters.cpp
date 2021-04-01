#include<bits/stdc++.h>
using namespace std;
int numMonstersKilled(vector<int> mon, int n,int h,int k){
	int ch = h;
	int ck = k;
	priority_queue<int> killed;
	int numKilled=0;
	for(int i=0;i<n;i++){
		//if monster's damage is <0 then we surely kill it as it increases our health 
		if(mon[i]<=0){
			ch-=mon[i];
			numKilled++;		
		}else if(ch>=mon[i]){ //if my health is more than the monster's damage, kill it
			killed.push(mon[i]);
			ch-=mon[i];
			numKilled++;
		}else{//if my health is less then I have to check my previous decisions
			if(ck>0){
				while(ck>0 && ch<mon[i] && !killed.empty()){//among all the monsters killed, pick the one which had the highest damage and use potion to kill it, so its damage is added back to your health, keep on doing this till your current health increases or you are out of potion
					//take potion
					ck-=1;
					//increase health
					ch+=killed.top();
					//remove from killed list
					killed.pop();
				}
				//even after making correct choice of using potions on the previous kills, health is not enough, then I can't continue
				if(ch>mon[i]){
					ch-=mon[i];
					killed.push(mon[i]);
					numKilled++;	
				}else{
					break;
				}
			}
		}
	}
	return numKilled;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	int n,h,k;
	vector<int> mon;
	
	cin>>n>>h>>k;
	
	for(int i=0;i<n;i++){
		int temp;
		cin>>temp;
		mon.push_back(temp);
	}
	
	cout<<numMonstersKilled(mon,n,h,k);
	return 0;
}

