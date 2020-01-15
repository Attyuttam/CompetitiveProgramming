//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long n;
        cin>>n;
        vector<long> a;
        vector<long> b;
        for(long i=0;i<n;i++){
            long temp;
            cin>>temp;
            a.push_back(temp);
        }
        for(long i=0;i<n;i++){
            long temp;
            cin>>temp;
            b.push_back(temp);
        }
        //LOGIC 1
        long max_monk = 0;
        for(long i=0;i<n;i++){
            if(b[i]<a[i])continue;
            long sPos = i;
            long ePos;
            
            long beg = sPos;
            long end = n-1;
            long m=-1;
            long key = a[i];
            
            while(beg<=end){
                m = (beg+end)/2;    
                if(m!=0 && b[m]<key && b[m-1]>=key)break;
                if(b[m]==key && m==end){m+=1;break;}
                else if(b[m]>=key)beg=m+1;
                else if(b[m]<key)end=m-1;
            }
            ePos=m;
            
            //cout<<i<<" --- "<<ePos<<endl;
            if(ePos==-1)continue;
            
            if(ePos-1-i>max_monk)max_monk = ePos-i-1 ;
            //cout<<i<<" "<<ePos<<" "<<max_monk<<endl;
        }
        cout<<max_monk<<endl;
        //LOGIC 2
        /*long max_monk = 0;
        long i=0,j=0;
        while(j>=i && j<n){
            if(b[j]>=a[i]){
                if(j-i>max_monk)max_monk=j-i;
                j++;
            }
            else{
                i++;
                j=i;
            }
        }
        cout<<max_monk<<endl;*/
        //LOGIC 3
        /*for(long i=0;i<n;i++){
            for(long j=i;j<n;j++){
                if(b[j]>=a[i]){
                    if(j-i>max_monk)max_monk=j-i;
                }
                else{
                    break;
                }
            }
        }
        cout<<max_monk<<endl;*/
    }
}