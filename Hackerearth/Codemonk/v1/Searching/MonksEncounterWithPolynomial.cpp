//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        double a,b,c,k;
        cin>>a>>b>>c>>k;
        c=c-k;
        if(b*b-4*a*c<0){
            cout<<"0"<<endl;
        }
        else{
        double x1 = (-1*b+sqrt(b*b-4*a*c))/(2*a);
        double x2 = (-1*b-sqrt(b*b-4*a*c))/(2*a);
        //cout<<x1<<","<<x2<<",";
        if(x1<0 && x2<0){
            cout<<"0"<<endl;
        }
        else if(x1<0 && x2>=0){
            cout<< ceil(x2)<<endl;
        }
        else if(x1>=0 && x2<0){
            cout<< ceil(x1)<<endl;
        }
        else{
            cout<<ceil(min(x1,x2))<<endl;
        }
        }
    
    }
}