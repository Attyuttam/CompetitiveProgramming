//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,q;
    cin>>n>>q;
    multiset<int> v;
    for(int i=0;i<n;i++){
        int temp;
        cin>>temp;
        v.insert(temp);
    }
    
    for(int i=0;i<q;i++){
        int num;
        cin>>num;
        //BS(num,v,0,n-1);
        auto it = v.find(num);
        if(it==v.end()){
            cout<<"NO"<<endl;
        }
        else{
            cout<<"YES"<<endl;
        }
    }
    
}
