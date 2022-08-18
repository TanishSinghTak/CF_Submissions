#include<bits/stdc++.h>
using namespace std;


int main() {
 int t;
 cin>>t;
 while(t--){
  int n;
  cin>>n;
  vector<pair<int,int>> arr;
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    arr.push_back({x,i});
  }
  sort(arr.begin(), arr.end());
  int min_1 = arr[0].first;
  // int min_1_ind = arr[0].second;
  int min_2 = arr[1].first;
  // int min_2_ind = arr[1].second;
  int max_1 = arr[n-1].first;
  // int max_1_ind = arr[n-1].second;
  int max_2 = arr[n-2].first;
  // int max_2_ind = arr[n-2].second;

  cout<<max_2+max_1-min_1-min_2<<endl;
 }
}