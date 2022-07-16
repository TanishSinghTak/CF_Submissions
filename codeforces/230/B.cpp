#include "bits/stdc++.h"
 
using namespace std;
 
#define ll long long int;
 
const long long mod=10e7;
 
bool isPrime(int n)
{
    // Corner case
    if (n <= 1)
        return false;
    if(n==2){
      return true;
    }
    // Check from 2 to n-1
    for (int i = 2; i < sqrt(n)+1; i++)
        if (n % i == 0)
            return false;
 
    return true;
}
 
int main(){

  int n;
  cin>>n;
  while(n--){
    long long x; 
    cin>>x;
    if(x==1){
      cout<<"NO"<<endl;
    }
    else{
    long  long lo =1;long long hi = x;
    long long mid,sq;
    while(hi-lo>1){
      mid = (hi+lo)/2;
      sq = mid*mid;
      if(mid > 1e7 || sq >= x){
        hi = mid;
      }
      else{
        lo = mid+1;
      }
    }
    if((lo*lo == x) ){
      if(isPrime(lo)){cout<<"YES"<<endl;}
      else{cout<<"NO"<<endl;}
    }
    else if(hi*hi == x){
      if(isPrime(hi)){cout<<"YES"<<endl;}
      else{cout<<"NO"<<endl;}
    }
    else cout<<"NO"<<endl;
    }
  }
}