#include "bits/stdc++.h"
using namespace std;

#define ll long long int;

const long long mod=10e7;

int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int z =c;
        int y = 2*c + b;
        int x = 2*y + a;
        cout<<x<<" "<<y<<" "<<z<<endl;
    }
}
