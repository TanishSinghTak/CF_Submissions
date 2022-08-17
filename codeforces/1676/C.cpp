#include<bits/stdc++.h>
using namespace std;

int main(void) {
 int t;
 cin>>t;
 while(t--){
  int n,m;
  cin>>n>>m;
  // cout<<n<<" "<<m<<endl;
  vector<string> arr;
  int ans = INT_MAX;
  for(int i = 0; i<n; i++){
    string x;
    cin>>x;
    arr.push_back(x);
  }
  
  for(int i = 0; i<n; i++){
    for(int j = i+1; j<n; j++){
      string s1 = arr[i], s2 = arr[j];
      int value = 0;
      for(int k = 0; k<m; k++){
        
        value+=abs(s1[k] - s2[k]);
        
      }
      
      ans = min(value,ans);
    }
  }
  cout<<ans<<endl;
 }
}