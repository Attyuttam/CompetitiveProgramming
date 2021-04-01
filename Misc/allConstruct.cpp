#include<bits/stdc++.h>
using namespace std;
int totalIterations;
map<string,vector<vector<string>>> m;
vector<vector<string>> countConstructWithMemo(string t, vector<string> wb){
	if(m.find(t)!=m.end())return m[t];
	totalIterations+=1;

	if(t.compare("")==0){
		vector<vector<string>> temp;
		vector<string> temp_inner;
		temp.push_back(temp_inner);
		return temp;
	}
	
	int total = 0;
	vector<vector<string>> newListOfPossibleCombinations;
	for(int i=0;i<wb.size();i++){
		if(t.length()>=wb[i].length()){
			string prefix = t.substr(0,wb[i].length());
			if(prefix.compare(wb[i])==0){
				//so in this problem, even if you apply DP, the resulting complexity shall still be O(n^m*(internal work time)).
				//This is because, after getting all the combinations, we will have to traverse all of them to add the current word on them,
				//Hence, we will eventually be hitting all the possible n^m combinations, even if they are memoized. Hence, n^m.
				//Like say if you recursed and got 200 possible combinations. If it would have been just count, you could have just add 200 to the forming
				//result and thereby increased the count , but in this case, say you recursed and found that for a target string "axyz" you have 200 word combinations,
				// now when you tackle "axyz" again, you have all the 200 combinations ready, but you will have to traverse all the 200 and add the current 
				//word on them, hence even though you saved time on recursing, but you will have to traverse all the 200 in a loop again. So, you don't essentially save time.
				string suffix = t.substr(wb[i].length(),t.length());
				vector<vector<string>> listOfPossibleCombinations = countConstructWithMemo(suffix,wb);
				if(listOfPossibleCombinations.size()!=0){
					for(int j=0;j<listOfPossibleCombinations.size();j++){
						listOfPossibleCombinations[j].push_back(wb[i]);
						newListOfPossibleCombinations.push_back(listOfPossibleCombinations[j]);
					}
				}
			}
		}
	}

	m[t]=newListOfPossibleCombinations;
	return newListOfPossibleCombinations;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	
	vector<vector<string>> val;
	
	string t;
	vector<string> wb;
	
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
	
	cout<<"\nt="<<t<<" and total iterations="<<totalIterations<<endl;
	for(int i=0;i<val.size();i++){
		reverse(val[i].begin(),val[i].end());
		for(int j=0;j<val[i].size();j++){
			cout<<val[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
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
	
	cout<<"\nt="<<t<<" and total iterations="<<totalIterations<<endl;
	for(int i=0;i<val.size();i++){
		reverse(val[i].begin(),val[i].end());
		for(int j=0;j<val[i].size();j++){
			cout<<val[i][j]<<" ";
		}
		cout<<endl;
	}
	

	return 0;
}

