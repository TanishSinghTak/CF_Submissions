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
      for (int i = 0; i < n; i++)
      {
        cin>>arr[i];
      }
      int sum = 0;
      int m;
      cin>>m;
      for (int i = 0; i < m; i++)
      {
        int k;
        cin>>k;
        sum = (sum + k)%n;
      }
      int ans = sum%n;
      cout<<arr[ans]<<endl;
    }
}

