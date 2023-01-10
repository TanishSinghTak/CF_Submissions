#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'     //Comment out if interactive

signed main() {

    Fast_io;
    // cout.precision(30);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        // cout<<n<<endl;
        int N = 2e5;
        map<int,int> arr;
        vector<vector<int>> grid;
        for(int i=0;i<n;i++){
            int x;
            cin>>x;
            // cout<<x<<" ";
            vector<int> a;
            for(int j=0;j<x;j++){
                int y;
                cin>>y;
                // cout<<y<<" ";
                a.push_back(y);
                arr[y]++;
            }
            // cout<<endl;
            grid.push_back(a);
        }
        bool f =0;
        for(auto elem:grid){
            bool f2 =1;
            for(auto e:elem){
                if(arr[e]<2){
                    f2 = 0;
                    break;
                }
            }
            if(f2==1){
                f=1;
                break;
            }
        }
        if(f==1){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }

    return 0;
}
