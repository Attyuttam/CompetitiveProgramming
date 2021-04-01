#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n,k;
	cin>>n>>k;
	
	int qr,qc;
	cin>>qr>>qc;
	qr=n-qr;
	qc-=1;
	
	vector<vector<int>> board;
	
	vector<pair<int,int>> ob;
	
	for(int i=1;i<=k;i++){
		int obr,obc;
		cin>>obr>>obc;
		
		ob.push_back(make_pair(n-obr,obc-1));
	}
	//qr,qc,ob,n
	int east=INT_MAX,west=INT_MAX,north=INT_MAX,south=INT_MAX,ne=INT_MAX,nw=INT_MAX,se=INT_MAX,sw=INT_MAX;
	for(int i=0;i<ob.size();i++){
		//east
		//the obstacle is in east
		if(ob[i].first==qr && ob[i].second>qc){
			if(ob[i].second-qc-1<east){
				east=ob[i].second-qc-1;
				continue;
			}
		}
		//west
		//the obstacle is in west
		if(ob[i].first==qr && ob[i].second<qc){
			if(qc-ob[i].second-1<west){
				west=qc-ob[i].second-1;
				continue;
			}
		}
		//south
		//obstacle in south
		if(ob[i].second==qc && ob[i].first>qr){
			if(ob[i].first-qr-1<south){
				south=ob[i].first-qr-1;
				continue;
			}
		}
		//north
		//obstacle in north
		if(ob[i].second==qc && ob[i].first<qr){
			if(qr-ob[i].first-1<north){
				north=qr-ob[i].first-1;
				continue;
			}
		}
		//diagonal check
		if(abs(ob[i].first-qr)==abs(ob[i].second-qc)){
		//	cout<<"===++++==>>>"<<ob[i].first<<" "<<ob[i].second<<endl;
			//north-east
			if(ob[i].second-qc-1>=0 && qr-ob[i].first-1>=0){
				//cout<<"=====>>>"<<ob[i].first<<" "<<ob[i].second<<endl;
				int val = ob[i].second-qc-1;
				if(val<ne){
					ne=val;
					continue;
				}
			}
			//north-west
			if(qc-ob[i].second-1>=0 && qr-ob[i].first-1>=0){
				int val = qc-ob[i].second-1;
				if(val<nw){
					nw=val;
					continue;
				}
			}
			//south-east
			if(ob[i].second-qc-1>=0 && ob[i].first-qr-1>=0){
				int val = ob[i].second-qc-1;
				if(val<se){
					se=val;
					continue;	
				}
			}
			//south-west
			if(qc-ob[i].second-1>=0 && ob[i].first-qr-1>=0){
				//cout<<ob[i].first<<"---"<<ob[i].second<<endl;
				int val = qc-ob[i].second-1;
				if(val<sw){
					sw=val;	
					continue;
				}
			}
		}
		
		
	}
	int res=0;
	
	if(north==INT_MAX && qr>0){
		north=qr;	
	}
	if(south==INT_MAX && qr<n-1){
		south=n-qr-1;
	}
	if(east==INT_MAX && qc<n-1){
		east=n-qc-1;
	}
	if(west==INT_MAX && qc>0){
		west=qc;
	}
	if(ne==INT_MAX && qr>0 && qc<n-1){
		ne=min(qr,n-qc-1);
	}
	if(nw==INT_MAX && qr>0 && qc>0){
		nw=min(qc,qr);
	}
	if(se==INT_MAX && qr<n-1 && qc<n-1){
		se=min(n-qr-1,n-qc-1);
	}
	if(sw==INT_MAX && qr<n-1 && qc>0){
		sw=min(n-qr-1,qc);
	}
	//cout<<"--->"<<north<<" "<<east<<" "<<west<<" "<<south<<" "<<ne<<" "<<nw<<" "<<se<<" "<<sw<<endl;
	if(north!=INT_MAX)res+=north;
	if(south!=INT_MAX)res+=south;
	if(east!=INT_MAX)res+=east;
	if(west!=INT_MAX)res+=west;
	if(ne!=INT_MAX)res+=ne;
	if(nw!=INT_MAX)res+=nw;
	if(se!=INT_MAX)res+=se;
	if(sw!=INT_MAX)res+=sw;

	cout<<res<<endl;
	
	return 0;
}

