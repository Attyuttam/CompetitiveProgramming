#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> v;
int val;

void z_trav(int n,int br,int er,int bc,int ec){
	//cout<<"n="<<n<<", br="<<br<<", er="<<er<<", bc="<<bc<<", ec="<<ec<<endl;
	if(n==1){
		for(int i=br;i<=er;i++){
			for(int j=bc;j<=ec;j++){
				v[i][j]=val++;			
			}
		}
		return;
	}
	z_trav(n-1,br,(br+er)/2,bc,(bc+ec)/2);
	z_trav(n-1,br,(br+er)/2,(bc+ec)/2+1,ec);
	z_trav(n-1,(br+er)/2+1,er,bc,(bc+ec)/2);
	z_trav(n-1,(br+er)/2+1,er,(bc+ec)/2+1,ec);
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin>>n;
	val = 1;
	
	for(int i=0;i<pow(2,n);i++){
		vector<int> tmp;
		for(int j=0;j<pow(2,n);j++){
			tmp.push_back(0);
		}
		v.push_back(tmp);
	}
	
	z_trav(n,0,(pow(2,n)-1),0,(pow(2,n)-1));
	
	for(int i=0;i<pow(2,n);i++){
		for(int j=0;j<pow(2,n);j++){
			cout<<setw(3)<<v[i][j]<<"    ";
		}
		cout<<endl;
	}
	return 0;
}

