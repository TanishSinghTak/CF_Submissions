#include<bits/stdc++.h>
using namespace std;
#define int long long // comment if Space limit exceeds
const int N = 1e5+10; //change to 32000 if TLE happens for prime factors
const int mod = 1e9 +7; 
vector<int> isprime(N,1);
vector<int> primes;
vector<int> vis(N,0);
int parent[N]; // for DSU change it accordingly for something else
int size[N]; // for DSU change it accordingly for something else
map<int,int> size_map; // for kruskal 
int fact[N]; // factorial array


signed main() {
    int t;
    cin>>t;
    
    while(t--){
        int n;
        cin>>n;
        if(n<=10){
            cout<<n<<endl;
        }
        else if(10<n && n<100){
            cout<<9+(n/10)<<endl;
        }
        else if(100<= n && n<1000){
            cout<<18 + (n/100)<<endl;
        }
        else if(1000<=n && n<10000){
            cout<<27+(n/1000)<<endl;
        }
        else if(10000<=n && n<100000){
            cout<<36+(n/10000)<<endl;
        }
        else{
            cout<<45 + (n/100000)<<endl;
        }
    }
}
