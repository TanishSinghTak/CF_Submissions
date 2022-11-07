#include<bits/stdc++.h>
using namespace std;


int main() {
  long long t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    long long ans=0;
    for(int i=0; i<n; i++){
      long long x;
      cin>>x;
      ans+=x;
    }
    cout<<abs(ans)<<endl;
  }
}



