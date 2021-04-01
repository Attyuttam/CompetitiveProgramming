#include<bits/stdc++.h>
#define ut uint64_t
using namespace std;
//LOGIC 1: the explanation is in the code itself
string check(ut n){
	// if the number is odd, then definitely it can divide itself and hence has an odd divisor
	if(n%2!=0){
		return "YES";
	}
	// if the number is even, continue dividing by 2 
	// (because even numbers are divisible by 2, 
	// so if we divide by 2 we get the factor and we can continue exploring the factor further.
	while(n!=0){
		n/=2;
		if(n>1 && n%2!=0)return "YES";
	}
	
	return "NO";
}

//LOGIC 2: 
//So, there's this theorem, any number can be represented as a product of primes
//All prime numbers except 2 is odd.
//So, if a number does not have an odd divisor, then essentially its prime factorization shall only contain 2's
//So, to check if a number has any odd divisor or not, we can check if its a power of 2 or not ?
//If, its a power of 2, then its prime factorization shall only have 2's and hence no odd divisor.
//Else, if its not a power of 2, then its prime factorization shall have prime numbers other than 2, right ?
//Hence, we just need to check if the number is a power of 2 or not.
//So, we can do this in 2 ways:
// 		1. Keep on dividing the number by 2, if we arrive at 1, then its a power of 2, else we will hit an odd number --> works with O(log n)
//		2. Since, in the binary representation of a number n which is a power of 2, only one place shall have 1 and hence n-1 shall have all the places to the left of 1(in n) as 1,
//			Thus, n&(n-1) = 0 if n is a power of 2
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	ut t;
	cin>>t;
	while(t--){
		ut n;
		cin>>n;
		cout<<check(n)<<endl;
	}
	
	return 0;
}

