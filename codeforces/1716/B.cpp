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
    int arr[n];
    cout<<n<<endl;
    for(int i =0; i<n; i++){
        arr[i] = i+1;
    }
    for(int i = 0; i<n; i++){
        for(int i = 0; i<n; i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        if(i!=n-1){
            swap(arr[n-i-1], arr[n-i-2]);
        }
    }
  }
}
