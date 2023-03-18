#include<bits/stdc++.h>
using namespace std;
#define endl '\n'    
#define int long long 


signed main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int c0 = 0;
        int c1 = 0;
        for(int i =0; i<n; i++){
            int x;
            cin>>x;
            arr.push_back(x);
            if(x == 0){
                c0++;
            }
            else if(x == 1){
                c1++;
            }
        }
        if(c0 ==0 || c0 <= (n+1)/2){
            cout<<0<<endl;
        }
        else{
            int y  = n - c0 - c1;
            if(  c0 ==n || y>=1){cout<<1<<endl;}
            else{cout<<2<<endl;}
        }


    }

    return 0;
}
