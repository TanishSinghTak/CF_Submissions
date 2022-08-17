#include<bits/stdc++.h>
using namespace std;

int main(void) {
 int t;
 cin>>t;
 while(t--){
  int n;
  cin>>n;
  map<int,int> boxes;
  int min =  INT_MAX;
  for(int i = 0; i < n; i++){
    int x; 
    cin>>x;
    if(x<min){min = x;}
    boxes[x]++;
  }
  int ans = 0;
  for(auto elem:boxes){
    int num =  elem.first;
    int diff = num-min;
    ans+=(diff*elem.second);
  }
  cout<<ans<<endl;
 }
}