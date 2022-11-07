#include<bits/stdc++.h>
using namespace std;


int main() {
  long long t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int x;
    cin>>x;
    int m = x;
    int f= 0;
    for(int i =1; i<n ; i++){
      int y;
      cin>>y;
      if(y<x && f ==0){
        cout<<"Alice"<<endl;
        f= 1;
      }
    }
    if(f==0){
      cout<<"Bob"<<endl;
    }
  }
}



