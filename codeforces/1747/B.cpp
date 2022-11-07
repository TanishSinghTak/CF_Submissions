#include<bits/stdc++.h>
using namespace std;


int main() {
  long long t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int x = (n+1)/2;
    int y = 2;
    int z = 3*n;
    cout<<x<<endl;
    for(int i=0; i<x; i++){
      cout<<y<<" "<<z<<endl;
      y+=3;
      z-=3;
    }
  }
}



