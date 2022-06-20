#include "bits/stdc++.h"

using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
    int t;
    cin>>t;
    while(t--){
      long long int n;
      cin>>n;
      if(n == 1){
        cout<<3<<endl;
      }
      else{
        string s = bitset<31>(n).to_string();
        int ans[31] = {0};
        int one_num = 0;
        int one_ind;
        for (int i = 31; i >= 0; i--)
        {
          if(s[i] == '1'){
            one_num+=1;
            if(one_num ==1){
              one_ind = i;
            }
          }
        }
        ans[one_ind] = 1;
        if(one_num == 1){
          ans[30] = 1;
        }
        string final_ans;
        for (int i = 0; i < 31; i++)
        {
          final_ans += to_string(ans[i]);
        }
        
        int anss = stoi(final_ans, 0, 2);
        cout<<anss<<endl;
      }
    }
}

