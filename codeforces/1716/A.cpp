#include "bits/stdc++.h"
using namespace std; 
typedef long long int ll;
const int N = 1e8;

int minsteps(int n){
   if(n==0){return 0;}
   if(n==1){return 2;}
   if(n==2 || n==3){return 1;}
   else{
    if(n%3 == 0){
        return n/3;
    }
    else{
        return (n/3) +1; 
    }
   }
}

int main() {
  int t;
  cin>>t;
  while(t--){
    int x;
    cin>>x;
    cout<<minsteps(x)<<endl;
  }
}