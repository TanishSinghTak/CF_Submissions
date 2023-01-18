#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'     //Comment out if interactive
#define int long long // comment if Space limit exceeds
const int N = 1e5+10; //change to 32000 if TLE happens for prime factors
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

//DSU begin
void make(int v){
    parent[v] =v;
  size[v] = 1;
}

int find(int v){
    if(parent[v] == v){return v;}
    return parent[v] = find(parent[v]);
}

void Union(int a, int b){
  a = find(a);
  b = find(b);
    if(a!=b){
    if(size[a]<size[b]){
      swap(a,b);
    }
        parent[b] = a;
    size[a]+=size[b];
    }
}

//merge used for kruskal
void merge(int a, int b){
    size_map[size[a]]--;
    if(size_map[size[a]] == 0){
        size_map.erase(size[a]);
    }
    size_map[size[b]]--;
    if(size_map[size[b]] == 0){
        size_map.erase(size[b]);
    }
    size_map[size[a] + size[b]]++;
}
// DSU end

//subset generation using bitMasking
vector<vector<int>> subsets(vector<int>& nums ){
    int n = nums.size();
    int subset_ct = 1<<n;
    vector<vector<int>> subsets_list;
    for(int mask = 0; mask < subset_ct; ++mask){
        vector<int> subset;
        for(int i = 0; i < n; ++i){
            if((mask & (1<<i)) != 0){
                subset.push_back(nums[i]);
            }
        }
        subsets_list.push_back(subset);
    }
    return subsets_list;
} 

//general DFS
void DFS(int vertex, vector<vector<int>> graph){
    //1. take action on vertex after entering vertex
    for(int child : graph[vertex]){
        //2. take action on child node before entering child node
        DFS(child, graph);
        //3. take action on child node after exiting child node
    }
    //4. take action on vertex before exiting vertex
}

/////----------------------------Main Function---------------------------------/////

bool comp(int a ,int b){
    return b<a;
}

signed main() {

    Fast_io;
    // cout.precision(30);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> count(26,0);
        for(int i =0; i<n; i++){
            count[s[i]-'a']++;
        }
        vector<pair<int,int>> counts(26);
        for(int i =0; i<26; i++){
            counts[i] = {count[i],i};
        }
        sort(counts.rbegin(), counts.rend());
        int max_f = counts[0].first;
        int ans = n-max_f;
        int min_f = 1; 
        for(int i = 2; i<=26  && i<=n; i++){
            int change = 0;
            int change2 = 0;
            if(n%i == 0){
                int x = n/i;
                // cout<<x<<endl;
                for(int j = 0; j<i && counts[j].first >0 ; j++){
                    if(counts[j].first - x >0){
                        change+=counts[j].first - x;
                    }
                    else{
                        change2-=(counts[j].first - x);
                    }
                    
                }
                if(max(change,change2) <ans){
                ans = max(change,change2);    
                min_f = i;
            }
            }
            
        }   
        // pbcbkswittsjcsdcsbifkllsy
        // bbcblstlttsbcsccsbiclllst
        // cout<<min_f<<endl;
        cout<<ans<<endl;
        int x = n/min_f;
        vector<vector<int>> changes(26);
        for(int i =0; i<min_f; i++){
            if(counts[i].first == x){
                continue;
            }
            else if(counts[i].first>x){
                int b = counts[i].first - x;
                counts[i].first = x;
                int j = i+1;
                while(b>0 && j<26){
                    if(counts[j].first>=x){
                        j++;
                    }
                    else{
                        int a  = x - counts[j].first;
                        if(a<=b){
                            counts[j].first  = x;
                            b-=a;
                            for(int k =0; k<a; k++){
                                changes[counts[i].second].push_back(counts[j].second);
                            }
                            
                        }
                        else{
                            counts[j].first+=b;
                            for(int k =0; k<b; k++){
                                changes[counts[i].second].push_back(counts[j].second);
                            }
                            b =0;
                        }
                        j++;
                    }
                }
            }
            else{
                int b = x - counts[i].first;
                // cout<<b<<endl;
                counts[i].first = x;
                int j = 25;
                while(b>0 && j>i){
                    int a = counts[j].first;
                    if(a<=b && a!=0){
                        // cout<<j<<" ";
                        b-=a;
                        counts[j].first = 0;
                        for(int k =0; k<a; k++){
                            changes[counts[j].second].push_back(counts[i].second);
                        }
                    }
                    else if(a>b && a!=0){
                        // cout<<j<<" ";
                        counts[j].first-=b;
                        for(int k =0; k<b; k++){
                            changes[counts[j].second].push_back(counts[i].second);
                        }
                        b =0;
                    }
                    j--;
                }
            }
        }
        for(int i =0; i<n; i++){
            int len = changes[s[i]-'a'].size();
            // cout<<len<<endl;
            if(len!=0){
                char z = char(97+changes[s[i]-'a'][len-1]);
                changes[s[i]-'a'].pop_back();
                swap(s[i],z);
            }
        }
        cout<<s<<endl;
    }

    return 0;
}
