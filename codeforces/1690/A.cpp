#include "bits/stdc++.h"
using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        if(n%3 ==0){
            cout<<(n/3)<<" "<<((n/3)+1)<<" "<<((n/3)-1)<<endl;
        }
        if(n%3 ==1){
            if(n/3 != 2){
            cout<<((n/3)+1)<<" "<<((n/3)+2)<<" "<<((n/3)-2)<<endl;
            }
            else{
                cout<<"2 4 1"<<endl;
            }
        }
        if(n%3 ==2){
            cout<<((n/3)+1)<<" "<<((n/3)+2)<<" "<<((n/3)-1)<<endl;
        }
    }
}
