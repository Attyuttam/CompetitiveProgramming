#include<bits/stdc++.h>
#include <boost/algorithm/string.hpp> 

//THIS  PROGRAM WON'T RUN AS THERE IS NO BOOST
using namespace std;
long getSum(string n){
	long val=0;
	int i=0;
	while(i<n.length()){
		val=val*10+(n[i]-'0');
	}
	return val;
}
void evaluate(string s){
	vector<string> result; 
    boost::split(result, s, boost::is_any_of("+")); 
  	long sum=0;
    for (int i = 0; i < result.size(); i++) {
    	vector<string> subResult; 
  	 	boost::split(subResult, result[i], boost::is_any_of("-")); 
  	 	for(int j=0;j<subResult.size();j++){
  	 		sum+=getSum(subResult[i]);	
		}
  
	}
    cout << sum << endl; 	
}
int main(){
	string s;
	cin>>s;
	evaluate(s);
	return 0;
}

