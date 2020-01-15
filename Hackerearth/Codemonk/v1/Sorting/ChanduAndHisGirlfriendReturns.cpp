//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        vector<int> v1,v2;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v1.push_back(temp);
        }
        for(int i=0;i<m;i++){
            int temp;
            cin>>temp;
            v2.push_back(temp);
        }
        vector<int> fa;
        int i=0,j=0;
        while(i<n && j<m){
            if(v1[i]>v2[j]){
                fa.push_back(v1[i]);
                i++;
            }
            else{
                fa.push_back(v2[j]);
                j++;
            }
        }
        while(i<n){
            fa.push_back(v1[i]);
            i++;
        }
        while(j<m){
            fa.push_back(v2[j]);
            j++;
        }
        for(int k=0;k<n+m;k++){
            cout<<fa[k]<<" ";
        }
        cout<<endl;
    }
}