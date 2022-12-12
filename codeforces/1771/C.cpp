#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 35000;
vector<long long> isprime(N,1);
vector<long long> primes;
void sieve(){
    isprime[0] = isprime[1] =0;
    for(long long i=2;i<N; i++){
        if(isprime[i] == 1){
            for(long long j = 2*i ; j<N; j+=i){
                isprime[j] = 0;
            }
            primes.push_back(i);
        }
    }
}
vector<long long> getPrimeFactors(int a) {
    vector<long long> f;
    for (auto p : primes) {
        if (p*p > a) break;
        if (a % p == 0) {
            f.push_back(p);
            do {
                a /= p;
            } while (a % p == 0);
        }
    }
    if (a > 1) f.push_back(a);

    return f;
}
signed main(){
    sieve();
    long long t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        for (int i=0; i<n; i++){
            int x; 
            cin>>x;
            arr.push_back(x);
        }
        map<long long , long long> factors;
        int flag =0;
        for (int i=0; i<n; i++){
            vector<long long> primefactors = getPrimeFactors(arr[i]);
            for(int j= 0 ; j<primefactors.size(); j++){
                if(factors[primefactors[j]] == 0){
                    factors[primefactors[j]] +=1;
                }
                else{
                    flag =1;
                    break;
                }
            }
            if(flag ==1){
                break;
            }
        }
        if(flag ==1 ){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
        }
    }
}