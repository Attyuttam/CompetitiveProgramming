#include<bits/stdc++.h>
using namespace std;
int totalIterations;
map<string,int> m;
int countConstructWithMemo(string t, vector<string> wb){
	if(m.find(t)!=m.end())return m[t];
	totalIterations+=1;

	if(t.compare("")==0){
		return 1;
	}
	
	int total = 0;
	
	for(int i=0;i<wb.size();i++){
		if(t.length()>=wb[i].length()){
			string prefix = t.substr(0,wb[i].length());
			if(prefix.compare(wb[i])==0){
				
				string suffix = t.substr(wb[i].length(),t.length());
				total+=countConstructWithMemo(suffix,wb);
			}
		}
	}
	m[t]=total;
	return total;
}
int countConstruct(string t, vector<string> wb){
	totalIterations+=1;

	if(t.compare("")==0){
		return 1;
	}
	
	int total = 0;
	
	for(int i=0;i<wb.size();i++){
		if(t.length()>=wb[i].length()){
			string prefix = t.substr(0,wb[i].length());
			if(prefix.compare(wb[i])==0){
				
				string suffix = t.substr(wb[i].length(),t.length());
				total+=countConstruct(suffix,wb);
			}
		}
	}
	return total;
}
print(map<string,int> m){
	map<string, int>::iterator itr; 
	cout<<m.size()<<endl;
    for (itr = m.begin(); itr != m.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << endl;
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	string t;
	vector<string> wb;
	
	int val=-1;
	
	
	totalIterations=0;
	t="aaaaaaaa";
	wb.push_back("a");
	wb.push_back("aa");
	wb.push_back("aaa");
	wb.push_back("aaaa");
	wb.push_back("aaaaa");

	val=countConstructWithMemo(t,wb);
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="aaaaaaaa";
	wb.push_back("a");
	wb.push_back("aa");
	wb.push_back("aaa");
	wb.push_back("aaaa");
	wb.push_back("aaaaa");

	val=countConstruct(t,wb);
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="enterapotentpot";
	wb.push_back("a");
	wb.push_back("p");
	wb.push_back("enter");
	wb.push_back("ent");
	wb.push_back("ot");
	wb.push_back("o");
	wb.push_back("t");

	val=countConstructWithMemo(t,wb);
	
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="enterapotentpot";
	wb.push_back("a");
	wb.push_back("p");
	wb.push_back("enter");
	wb.push_back("ent");
	wb.push_back("ot");
	wb.push_back("o");
	wb.push_back("t");

	val=countConstruct(t,wb);
	
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="babloo";
	wb.push_back("bab");
	wb.push_back("ho");
	wb.push_back("loo");

	val=countConstructWithMemo(t,wb);
	cout<<"\nt="<<t<<"result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="babloo";
	wb.push_back("bab");
	wb.push_back("ho");
	wb.push_back("loo");

	val=countConstruct(t,wb);
	cout<<"\nt="<<t<<"result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	totalIterations=0;
	wb.clear();
	m.clear();
	t="aaaaaaaaaaaaaaaaaaaaaaaaaa";
	wb.push_back("a");
	wb.push_back("aa");
	wb.push_back("aaa");
	wb.push_back("aaaa");
	wb.push_back("aaaaa");

	val=countConstructWithMemo(t,wb);
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	totalIterations=0;
	wb.clear();
	m.clear();
	t="aaaaaaaaaaaaaaaaaaaaaaaaaa";
	wb.push_back("a");
	wb.push_back("aa");
	wb.push_back("aaa");
	wb.push_back("aaaa");
	wb.push_back("aaaaa");

	val=countConstruct(t,wb);
	cout<<"\nt="<<t<<" result= "<<val<<" and total iterations="<<totalIterations<<endl;
	
	return 0;
}

