#include<bits/stdc++.h>
using namespace std;
int getResult(int v1,int v2,char op){
	switch(op){
		case '+':
			return v1+v2;
			break;
		case '-':
			return v1-v2;
			break;
		case '*':
			return v1*v2;
		case '/':
			return v1/v2;
			break;
	}
}
vector<int> findMaxVal(string ex,int s,int e){
	if(s==e){
		vector<int> result;
		result.push_back(ex[s]-'0');
		return result;
	}

	vector<int> res;

	for(int i=s+1;i<e;i+=2){
		vector<int> val1 = findMaxVal(ex,s,i-1);
		vector<int> val2 = findMaxVal(ex,i+1,e);
		
		for(int m=0;m<val1.size();m++){
			for(int n=0;n<val2.size();n++){
				res.push_back(getResult(val1[m],val2[n],ex[i]));
			}
		}
	}
	return res;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string ex;
	cin>>ex;
	vector<int> res = findMaxVal(ex,0,ex.length()-1);
	sort(res.begin(),res.end());
	for(int i=0;i<res.size();i++){
		cout<<res[i]<<" ";
	}
	cout<<endl;
	cout<<res[res.size()-1];
	return 0;
}

