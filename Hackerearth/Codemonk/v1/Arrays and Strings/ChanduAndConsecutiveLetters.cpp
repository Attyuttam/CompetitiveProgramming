//Created by Attyuttam Saha
#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        vector<int> alpha(26,0);
        string str;
        string goodStr;
        cin>>str;
        goodStr += str[0];
        for(int i=1;i<str.length();i++){
            if(str[i]!=str[i-1]){
                goodStr+=str[i];
            }
        }
        cout<<goodStr<<endl;
    }
}
