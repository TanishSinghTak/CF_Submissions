#include "bits/stdc++.h"
 
using namespace std;
 
typedef long long int ll;
 

const int  N = 1e6+10;
vector<int> ans(N,1);

int main(){
    int n;
    cin>>n;
    for(int i = 2; i < n+2; i++){
        if(ans[i] == 1){
            for(int j = 2*i; j < n+2; j+=i){
                ans[j] = 2;
            }
        }
    }
    if(n==1 || n==2){
    cout<<1<<endl;}
    else{cout<<2<<endl;}
    for(int i = 2; i<n+2; i++){
        cout<<ans[i]<<" ";
    }
}