#include<bits/stdc++.h>
using namespace std;
int main(){
	cout<<pow(10,18)+1-pow(10,18)<<endl;//shall give 0 but should have been 1
	cout<<pow(2,9)<<endl;
	long long v = pow(2*pow(10,9),2)-pow((2*pow(10,9)+1),2);
	long long x = (2*pow(10,9)+(2*pow(10,9)+1))*(2*pow(10,9)-(2*pow(10,9)+1));
	cout<<v<<endl;
	cout<<x<<endl;
	cout<<numeric_limits<long>::digits<<endl;
	double t1 = 1.0;
	double t2 = 0.0;
	double t3 = t1/t2;
	cout<<t3<<endl;
	if(t3>45){
		cout<<"true"<<endl;
	}
	cout << (long long)10000 * 1000 * 10000 << '\n';
	return 0;
}

