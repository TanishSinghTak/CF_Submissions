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
      int k = n;
      int min = 9;
      int digit = 0;
      while(k!=0){
        if((k%10) < min){
            min = (k%10);
        }   
        k = k/10;
        digit+=1;
      }

      if(digit == 2){
        cout<<(n%10)<<endl;
      }
      else{
        cout<<min<<endl;
      }
    }
}

