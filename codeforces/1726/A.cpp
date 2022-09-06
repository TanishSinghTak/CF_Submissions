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
        int n;
        cin>>n;
        
        vector<int> arr(n);
        int Max = 0;
        int min_ind, max_ind;
        int Min = 10000;
        for(int i = 0; i < n; i++){
            cin>>arr[i];
            if(arr[i] < Min){
                Min = arr[i];
                min_ind = i;
            } 
            if(arr[i] > Max){
                 Max = arr[i];
                 max_ind = i;
            }
        }
        int ans = arr[n-1] - arr[0];
        for(int i = 1; i <n; i++){
            ans = max(ans, arr[i-1] - arr[i]);
        }
        if(n==1){
            ans = 0;
        }
        else if(n==2){
            ans = abs(arr[1] - arr[0]);
        }
        else if( min_ind == 0 || max_ind == n-1 || max_ind == min_ind -1 ){
            ans =  Max - Min;
        }
        ans =  max(ans, arr[n-1] - Min);
        ans = max(ans, Max- arr[0]);

        cout<<ans<<endl;
    }
}



