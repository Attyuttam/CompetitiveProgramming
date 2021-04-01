#include<bits/stdc++.h>
using namespace std;
bool asPowerSum(int w, int m) 
{ 
    while (m) { 
        if ((m - 1) % w == 0)  
            m = (m - 1) / w; 
       else if ((m + 1) % w == 0)  
            m = (m + 1) / w; 
          
        else if (m % w == 0)  
            m = m / w; 
          
        else
            break; // None of 3 worked. 
    } 
  
    // If m is not zero means, it can't be  
    // represented in terms of powers of w. 
    return (m == 0); 
} 
int main(){
	int n,W;
	cin>>n>>W;
	if(asPowerSum(W,2)){
		
	}else{
		cout<<"0"
	}
	return 0;
}

