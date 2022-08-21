#include<bits/stdc++.h>
using namespace std;




int main() {
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    if(n==1 && m==1){
      cout<<0<<endl;
    }
    else if(n==1){
      cout<<m<<endl;
    }
    else if(m==1){
      cout<<n<<endl;
    }
    else{
      int x = min(n,m);
      int y = max(n,m);
      cout<<2*(x-1)+y<<endl;
    }
  }
  

}




