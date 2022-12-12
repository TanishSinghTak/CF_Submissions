#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main() {
  int t;
  cin>>t;
  while(t--){
    int n,m;
    cin>>n>>m;
    vector<int> closest_nonfriend;
    for(int i=0;i<n;i++){
      closest_nonfriend.push_back(n);
    }
    for(int i=0;i<m;i++){
      int x,y;
      cin>>x>>y;
      if(x<y){
        if(y-1<closest_nonfriend[x-1]){
          closest_nonfriend[x-1] = y-1;
        }
      }
      else{
        if(x-1<closest_nonfriend[y-1]){
          closest_nonfriend[y-1] = x-1;
        }
      }
    }
    int ans = 0;
    int max = n;
    for(int i=n-1; i>=0;  i--){
      if(closest_nonfriend[i]<max){
        max = closest_nonfriend[i];
      }
      else{
        closest_nonfriend[i] = max;
      }
      ans += (closest_nonfriend[i] - i);
    }
    cout<<ans<<endl;
  }
  
}



