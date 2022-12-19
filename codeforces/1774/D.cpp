#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'     //Comment out if interactive


/////----------------------------Main Function---------------------------------/////


signed main() {

    Fast_io;
    // cout.precision(30);

    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        int x;
        vector<vector<int>> grid;
        vector<pair<int,int>> ones;
        int ones_count = 0;
        for(int i=0;i<n;i++){
            vector<int> arr;
            int curr =0;
            for(int j=0;j<m;j++){
                cin>>x;
                arr.push_back(x);
                if(x==1){
                    ones_count++;
                    curr++;
                }
            }

            ones.push_back({curr,i+1});
            grid.push_back(arr);
        }
        if(ones_count%n != 0){
            cout<<-1<<endl;
        }
        else{
            vector<vector<int>> ans;
            sort(ones.begin(),ones.end());
            int avg = ones_count/n;
            int l =0; int r =n-1;
            while(l<r){
                int index = 0;
                while(ones[l].first<avg && ones[r].first>avg && index<m){
                    if(grid[ones[l].second -1][index] == 0 && grid[ones[r].second -1][index] == 1){
                        swap(grid[ones[l].second -1][index],grid[ones[r].second -1][index]);
                        ones[l].first++;
                        ones[r].first--;
                        ans.push_back({ones[l].second, ones[r].second,index+1});
                    }
                    index++;
                }
                if(ones[l].first==avg){
                    l++;
                }
                if(ones[r].first == avg){
                    r--;
                }
            }

            int sz = ans.size();
            cout<<sz<<endl;
            for(int i=0; i<sz; i++){
                cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<endl;
            }
        }

    }

    return 0;
}
