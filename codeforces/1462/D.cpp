#include "bits/stdc++.h"

using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int arr[n];
    int s = 0;
    int ans = n;
    for(int i =0; i<n; i++){
      int k;
      cin>>k;
      arr[i] = k;
      s += arr[i];
    }
    int ss = 0;
    for (int i = 0; i < n; i++)
    {
      ss += arr[i];
      if(s%ss ==0){
        int l = i+1;
        int sss =0;
        while(l < n){
          sss+=arr[l++];
          if(ss == sss){
            sss =0;
          }
        }
        if(sss == 0){
          ans = min(ans, n - (s/ss));
        }
      }
      
    }
    cout<<ans<<endl;
  } 
}