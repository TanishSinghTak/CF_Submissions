#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'     //Comment out if interactive
#define int long long // comment if Space limit exceeds
const int N = 1e7+10; //change to 32000 if TLE happens for prime factors
const int mod = 1e9 +7; 
int isprime[N]; // for sieve
vector<int> primes; // for storing primes
vector<int> vis(N,0); // visited array
int parent[N]; // for DSU change it accordingly for something else
int size[N]; // for DSU change it accordingly for something else
map<int,int> size_map; // for kruskal 
int fact[N]; // factorial array



// binary multiply with mod
int binMultiply(long long a, long long b,long long m){
    int ans =0;
    while(b){
        if(b&1){
            ans = (ans + a)%m;
        }
        a = (a +a)%m;
        b >>= 1;
    }
    return ans;
}

//binary exponentiation with mod
int binexp(long long a, long long b, long long m){
    int ans =1;
    while(b){
        if(b&1){
            ans = binMultiply(ans,a,m)%m;
        }
        a = binMultiply(a,a,m)%m;
        b >>= 1;
    }
    return ans;
}

//Factorial Pre-compute
void factorial(long long m){
    fact[0] = 1;
    for(int i = 0; i<N; i++){
        fact[i] = (fact[i-1]*1LL*i)%m;
    }
}

// Modulo multiplicative inverse MMI
// (A^-1)%m = (A^(m-2))%m
int moduloinverse(long long x , long long m){
    return binexp(x,m-2,m);
}


int nCr(long long n, long long r, long long m){
    int num = fact[n];//numerator
    int den = (fact[n-r]*1LL*fact[r])%m; // denominator
    int ans = (num*1LL*moduloinverse(den,m))%m; // using MMI for denominator
    return ans;
}


// Sieve Algorithm
void sieve(){
    for(int  i = 0; i<N; i++){
        isprime[i] = i;
    }
    for(int i=2;i<N; i++){
        if(isprime[i] != i){
            continue;}
        for(int j = 2*i ; j<N; j+=i){
            isprime[j] = min(isprime[j], i);
        }
        primes.push_back(i);
    }
}


// Function for prime factors
vector<int> getPrimeFactors(int a) {
    vector<int> f;
    while(a>1){
        if(f.empty()||f.back() != isprime[a])
            f.push_back(isprime[a]);
        a/=isprime[a];
    }
    return f;
}

/////----------------------------Main Function---------------------------------/////


signed main() {

    Fast_io;
    // cout.precision(30);
    sieve();
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        if(__gcd(a,b) != 1){
            cout<<0<<endl;
        }
        else if((b-a)%2 == 0){
            cout<<1<<endl;
        }
        else if(b-a == 1){
            cout<<-1<<endl;
        }
        else{
            int x = b-a;
            long long ans = 1e7+10;
            for(auto f : getPrimeFactors(x)){
                ans =  min(ans, f*1LL*((a/f) +1));
            }
            cout<< ans -a <<endl;
        }
    }

    return 0;
}

