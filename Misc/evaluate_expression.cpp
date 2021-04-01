#include<bits/stdc++.h>
using namespace std;
void evaluate(string s){
	stack<int> result;
	int currVal = 0;
	int i=0;
	
	//1. get the first number
	while(i<s.length()&&s[i]!='+' && s[i]!='-'){
		currVal = currVal*10+(s[i]-'0');
		i++;
		
	}
	//edgeCase: when there's just a digit 
	if(i==s.length()){
		cout<<currVal<<endl;
		return;	
	}
	//2. get the first operation
	char currOp = s[i];
	
	//3.initialize the stack with the first number
	result.push(currVal);
	//cout<<"Initial value in stack: "<<result.top()<<endl;
	//4. set i to the next index(which is the first digit of the 2nd number)
	i++;
	
	//5. set currVal to 0
	currVal=0;
	
	//6. start the iteration
	while(i<s.length()){
		if(s[i]=='+'||s[i]=='-'){
			//perform operation based on currOp
			int val = result.top();
			result.pop();
			if(currOp=='+')
				result.push(val+currVal);
			else if(currOp=='-')
				result.push(val-currVal);
				
			//set currOp to s[i]
			currOp=s[i];
			currVal=0;
		}else{
			currVal = currVal*10+(s[i]-'0');	
		}
		i++;
	}
	int val = result.top();
	//cout<<"here: "<<val<<"--"<<currVal<<endl;
	result.pop();
	if(currOp=='+')
		result.push(val+currVal);
	else if(currOp=='-')
		result.push(val-currVal);
			
	cout<<result.top();
}
int main(){
	string s;
	cin>>s;
	evaluate(s);
	return 0;
}

