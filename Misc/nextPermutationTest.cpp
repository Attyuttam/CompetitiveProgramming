#include <algorithm>
#include <string>
#include <iostream>
#include<bits/stdc++.h>
using namespace std;
 
int main()
{
    //std::string s = "aba";
    vector<int> s;
    int n=5;
    for(int i=1;i<=n;i++){
    	s.push_back(i);
	}
	sort(s.begin(), s.end());
    do {
    	for(int i=0;i<s.size();i++){
    		cout<<s[i]<<" ";
		}
        std::cout << '\n';
    } while(std::next_permutation(s.begin(), s.end()));
}
