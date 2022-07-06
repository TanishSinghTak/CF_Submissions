#include "bits/stdc++.h"

using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
  int n;
  string s;
  cin>>n>>s;
  n--;
  int k = n;
  map<char,int> m;
  int ans=0;

  while(k--){
    int i = n-k-1;
    int key = 2*i;
    int door= 2*i+1;
    m[s[key]] += 1; 
    if(m[tolower(s[door])] > 0 ){
        m[tolower(s[door])]--;
    }
    else{
        ans+=1;
    }
  }
  
  cout<<ans<<endl;
}