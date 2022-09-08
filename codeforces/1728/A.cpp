#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int m = -1;
        int ans = 0;
        for(int i=1; i<=n; i++){
            int x;
            cin>>x;
            if(x>m){
                m = max(m,x);
                ans = i;
            }
        }
        cout<<ans<<endl;
    }
}



