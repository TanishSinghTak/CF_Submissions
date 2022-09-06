#include<bits/stdc++.h>
using namespace std;


    vector<vector<int>> valid;
        
    void generate(set<int> &remain, vector<int> &nums){
        if(remain.empty()){
            valid.push_back(nums);
            return;
        }
        for(auto elem:remain){
            nums.push_back(elem);
            remain.erase(elem);
            generate(remain, nums);
            nums.pop_back();
            remain.insert(elem);
        }

    }

    vector<vector<int>> permute(vector<int>& nums) {
        set<int> remain; 
        cout<<1<<endl;
        for(int i = 0; i<nums.size(); i++){
            remain.insert(nums[i]);
        }
        
        vector<int> temp;
        for(int elem:remain){
            cout<<elem<<" ";
        }
        // generate(remain, temp);
        // return valid;
    }

int main() {
    // int n = 10000;
    // vector<int> arr(n,-1);
    // vector<vector<int>> dp(n, arr);
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        if(n>m || (n%2 == 0 && m%2 == 1)){
            cout<<"NO"<<endl;
        }
        else{
            int x = m%n;
            int y = m/n;
            if(n%2 == 1){
                cout<<"YES"<<endl;
                cout<<x+y<<" ";
                for(int i = 1; i<n; i++){
                    cout<<y<<" ";
                }
                cout<<endl;
            }
            else{
                cout<<"YES"<<endl;
                cout<<x/2 + y<<" ";
                cout<<x/2 + y<<" ";
                for(int i = 2; i<n; i++){
                    cout<<y<<" ";
                }
                cout<<endl;
            }
        }
    }
}



