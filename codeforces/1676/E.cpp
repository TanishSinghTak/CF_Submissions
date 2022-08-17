#include<bits/stdc++.h>
using namespace std;


bool comp(int a, int b){
  return a>b;}

int main(void) {
 int t;
 cin>>t;
 while(t--){
  int n,q;
  cin>>n>>q;
  vector<int> arr;
  for(int i=0;i<n;i++){
    int x;
    cin>>x;
    arr.push_back(x);
  }
  sort(arr.begin(),arr.end(),comp);
  for(int i=1;i<arr.size();i++){
    arr[i]+=arr[i-1];
  }

  while(q--){
    int x;
    cin>>x;
    if(x>arr[n-1]){cout<<-1<<endl;}
    else{
      int l =0, r =  n-1; 
      while(r-l>1){
        int mid = (r+l)/2;
        if(x<=arr[mid]){
           r = mid;
        }
        else{
          l = mid+ 1;
        }
      }
      if(arr[l]>= x){cout<<l+1<<endl;}
      else{cout<<r+1<<endl;}
    }
  }
 }
}