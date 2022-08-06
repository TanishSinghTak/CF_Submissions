#include "bits/stdc++.h"
using namespace std; 
typedef long long int ll;
const int N = 1e8;



int main() {
  int t;
  cin>>t;
  while(t--){
   int n;
   cin>>n;
   vector<int> arr;
   int order[n];
   for(int i=0; i<n; i++){
        int x;
        cin>>x;
        arr.push_back(x);
    }
    int ans = 0;
    for(int i=0; i<n-1; i++){
        if(ans == 0){
            if(arr[i] > arr[i+1]){
                ans =1;
            }
        }
        if(ans == 1){
            if(arr[i] < arr[i+1]){
                ans =2;
                break;
            }
        }
    }

    if(ans == 2){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES"<<endl;
    }
   }
}
