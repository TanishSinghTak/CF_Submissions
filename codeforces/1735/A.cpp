#include<bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int x;
    if(n%3 == 0){
    x = 2*((n-3)/3) -1;}
    if(n%3 != 0){
    x = 2*((n)/3) -2;}
    int ans = min(abs(n-5-x), abs(2*x-n+4));
    cout<<ans<<endl;
  }
  
}