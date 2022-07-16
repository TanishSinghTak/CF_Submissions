#include "bits/stdc++.h"

using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
  int n;
  cin>>n;
  long long  a[n];
  for(int i = 0; i<n; i++){
    int x;
    cin>>x;
    if(i == 0){
      a[i] =x;
    }
    else{
      a[i] = a[i-1] +x;
    }
  }
  int q;
  cin>>q;
  
  while(q--){
    int lo = 0; int hi = n-1;
    int x;
    cin>>x;
    
    while(hi-lo>1){
      int mid = (hi+lo)/2;
      if(a[mid]<x){
        lo = mid+1;
      }
      else{
        hi = mid;
      }
    }
    if(a[lo] >= x){
      cout<<lo+1<<endl;
    }
    else if(a[hi] >= x){cout<<hi+1<<endl;}
  }
}