//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n,x;
        cin>>n>>x;
        vector<long> v;
        for(long i=0;i<n;i++){
            long temp;
            cin>>temp;
        
            v.push_back(temp);
        }
        v.push_back(0);
        long sum=0;
        long sp=0;
        int flag=0;
        
        for(long i=0;i<v.size();i++){
            //cout<<sum<<endl;
            if(sum==x){
                flag=1;
                break;
            }
            else if(sum>x && sp>=0 && sp<v.size()){
                sum-=v[sp];
                sp++;
                i--;
                continue;
            }
            sum+=v[i];
        }
        if(flag==1){
            cout<<"YES"<<endl;
        }
        else{
                cout<<"NO"<<endl;
        }
    }
}
