#include "bits/stdc++.h"

using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
  int n;
  cin>>n;
  map<string,int> m;
  for(int i=0;i<n;i++){
    string s;
    cin>>s;
    if(m.find(s) == m.end()){
        m.insert({s,0});
        cout<<"OK"<<endl;
    }
    else{
        m[s] +=1;
        s = s + to_string(m[s]);
        m.insert({s,0});
        cout<<s<<endl;
    }
  }
  
}