#include<bits/stdc++.h>

using namespace std;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	string s1,s2;
	cin>>s1>>s2;
	transform(s1.begin(), s1.end(), s1.begin(),[](unsigned char c){ return std::tolower(c); });
	transform(s2.begin(), s2.end(), s2.begin(),[](unsigned char c){ return std::tolower(c); });
	cout<<s1.compare(s2)<<endl;
	return 0;
}

