#include<bits/stdc++.h>
using namespace std;


int main() {
  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    int x = 2*arr[0]-1;
    int ans = 0; 
    for(int i=1; i<n; i++){
        int y = arr[i]/x;
        if(arr[i]%x == 0){
            ans+=(y-1);
        }
        else{
            ans+=y;
        }
    }
    cout<<ans<<endl;
  }
  
}



