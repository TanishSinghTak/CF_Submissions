#include<bits/stdc++.h>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%2 ==0){
            int m = n-2;
            while(m>0){
                cout<<m<<" ";
                m--;
            }
            cout<<n-1<<" "<<n<<endl;
        }
        else{
            int m = n-5;
            while(m>0){
                cout<<m<<" ";
                m--;
            }
            cout<<n-4<<" "<<n-3<<" "<<n-2<<" "<<n-1<<" "<<n<<endl;
        }
        
    }
}



