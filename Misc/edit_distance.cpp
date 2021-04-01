#include<bits/stdc++.h>
using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string s1="polynomial";
	string s2="exponential";

	cout<<s1<<" , length = "<<s1.length()<<"\n";
	cout<<s2<<" , length = "<<s2.length()<<"\n";
	
	vector< vector<int> > T;
	
	for(int i=0;i<s1.length();i++){
		vector<int> temp;
		for(int j=0;j<s2.length();j++){
			temp.push_back(0);
		}
		T.push_back(temp);
	}
	
	for(int i=0;i<s1.length();i++){
		T[i][0]=i;
	}
	for(int i=0;i<s2.length();i++){
		T[0][i]=i;
	}
	
	for(int i=1;i<s1.length();i++){
		for(int j=1;j<s2.length();j++){
			T[i][j] = min(min(T[i-1][j]+1,T[i][j-1]+1),T[i-1][j-1]+(s1[i]==s2[j]?0:1));
		}
	}
	for(int i=0;i<s1.length();i++){
		for(int j=0;j<s2.length();j++){
			cout<<T[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<T[s1.length()-1][s2.length()-1]<<endl;
	return 0;
}

