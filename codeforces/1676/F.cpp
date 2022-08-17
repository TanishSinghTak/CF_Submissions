#include<bits/stdc++.h>
using namespace std;


bool comp(int a, int b){
  return a<b;}

int main(void) {
 int t;
 cin>>t;
 while(t--){
  int n , k;
  cin>>n>>k;
  map<int,int> count; 
  for(int i = 0; i < n; i++){
    int x;
    cin>>x;
    count[x]++;
  }
  vector<int> poss_no;
  for(auto elem:count){
    int value = elem.first;
    int val_count = elem.second;
    if(val_count>=k){
      poss_no.push_back(value);
    }
  }
  sort(poss_no.begin(), poss_no.end(),comp);
  int ans = 0;

  if(poss_no.empty()){cout<<-1<<endl;}
  else{
    int min = poss_no[0];
    int max = poss_no[0];
    int curr_min =  poss_no[0];
    int curr_max = poss_no[0];
    for(int i = 1; i<poss_no.size();i++){
      if(poss_no[i] == poss_no[i-1]+1){
        curr_max = poss_no[i];
      }
      else{
        if(curr_max - curr_min >= ans){
          ans =  curr_max - curr_min;
          max =  curr_max;
          min = curr_min; 
        }
        curr_min =  poss_no[i];
        curr_max =  poss_no[i];
      }
    }
    if(curr_max- curr_min >= ans){
      max =  curr_max;
      min  = curr_min;
    }
    cout<<min<<" "<<max<<endl;
  }
 }
}