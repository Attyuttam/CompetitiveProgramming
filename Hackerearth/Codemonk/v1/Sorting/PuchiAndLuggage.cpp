/Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, int b, int e, unordered_map<int,int> &um){
    int mid = (b+e)/2;
    int i=b;
    int j=mid+1;
    vector<int> temp;
    while(i<=mid && j<=e){
        if(v[i]>v[j]){
            temp.push_back(v[i]);
            um[v[i]]+=e-j+1;
            i++;
        }
        else{
            temp.push_back(v[j]);
            j++;
        }
    }
    while(i<=mid){
        temp.push_back(v[i]);
        i++;
    }
    while(j<=e){
        temp.push_back(v[j]);
        j++;
    }
    
    int k=0;
    for(int i=b;i<=e;i++){
        v[i]=temp[k];
        k++;
    }

}
void mergeSort(vector<int> &v, int b,int e,unordered_map<int,int> &um){
    if(b<e){
        int mid = (b+e)/2;
        mergeSort(v,b,mid,um);
        mergeSort(v,mid+1,e,um);
        merge(v,b,e,um);
    }
  
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> v;
        vector<int> v_temp;;
        for(int i=0;i<n;i++){
            int temp;
            cin>>temp;
            v.push_back(temp);
        }
        v_temp = v;
       unordered_map<int,int> um;
       //initializing the count of all the elements to 0(inversion count)
       for(int i=0;i<n;i++){
           um[v[i]]=0;
       }
       mergeSort(v,0,n-1,um);
       for(int i=0;i<n;i++){
           cout<<um[v_temp[i]]<<" ";
       }
      
       cout<<endl;
    }
}
