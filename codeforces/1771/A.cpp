#include<bits/stdc++.h>
using namespace std;
#define int long long


signed main() {
    int t; 
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i=0; i<n;i++){
            cin>>arr[i];
        }
        sort(arr.begin(), arr.end());
        int min = arr[0];
        int max = arr[n-1];
        int min_no = 0;
        int max_no = 0;
        for(int i=0; i<n;i++){
            if(arr[i] == min){
                min_no++;
            }
            else{
                break;
            }
        }
        for(int i=n-1; i>=0;i--){
            if(arr[i] == max){
                max_no++;
            }
            else{
                break;
            }
        }
        if(min==max){
            if(n==2){
                cout<<2<<endl;
            }
            else{
            cout<<n*(n-1)<<endl;
            }
        }
        else{
            cout<<2*min_no*max_no<<endl;
        }
    }
    

    
}



