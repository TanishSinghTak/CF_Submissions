#include<bits/stdc++.h>
using namespace std;

int main(void) {
 int t;
 cin>>t;
 while(t--){
  int n;
  cin>>n;
  int n1,n2;
  n1 = 0; n2= 0;
  for(int i = 0 ; i <3; i++){
      n1+=(n%10);
      n/=10;
  }
  for(int i = 0 ; i <3; i++){
      n2+=(n%10);
      // cout<<n2<<endl;
      n/=10;
  }
  // cout<<n1<<" "<<n2<<endl;
  if(n1==n2){
      cout<<"YES"<<endl;
  }
  else{
      cout<<"NO"<<endl;
  }
 }
}