#include<bits/stdc++.h>
using namespace std;


int main() {
 int t;
 cin>>t;
 while(t--){
  
  long long a,b,c,d;
  cin>>a>>b>>c>>d;
  long long x =  1LL*a*d;
  long long y = 1LL*b*c; 
  if(x == y){
    cout<<0<<endl;
  }
  else if(y == 0 || x%y == 0 || x == 0|| y%x == 0  ){
    cout<<1<<endl;

  }
  else{
    cout<<2<<endl;
  }
 }
}