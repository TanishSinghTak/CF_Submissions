#include<bits/stdc++.h>
using namespace std;


int main() {
 int t;
 cin>>t;
 
 while(t--){
  int n;
  cin>>n;
  vector<int> arr;
  for(int i=0; i<n; i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  vector<int> dp(n);
  int ans = 0;
  for(int i=0; i<n; i++){
    dp[i] = 1;

    for(int j=i-1; j>=max(i-256,0); j--){
      if((arr[j]^i) < (arr[i]^j)){
        dp[i]  =  max(dp[i], dp[j]+1);
      }
    }
    ans = max(ans, dp[i]);
  }

  // int ans = *max_element(dp.begin(), dp.end());
  
  cout<<ans<<endl;
  
  }
}