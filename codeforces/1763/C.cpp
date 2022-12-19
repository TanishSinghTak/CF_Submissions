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


signed main() {

    Fast_io;
    // cout.precision(30);

    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int> arr;
        int max_n = -1;
        int max_i = 0;
        for(int i=0; i<n; i++){
            int x;
            cin>>x;
            if(x>=max_n){
                max_n = x;
                max_i = i;
            }
            arr.push_back(x);
        }
        if(n==1){
            cout<<arr[0]<<endl;
        }
        else if(n==2){
            int ans = max(arr[0]+arr[1],2*abs(arr[0]-arr[1]));
            cout<<ans<<endl;
        }
        else if(n==3){
            if(max_i == 0 || max_i == 2){
                int ans = 3*max_n;
                cout<<ans<<endl;
            }
            else{
                int ans = arr[0]+arr[1]+arr[2];
                if(arr[0]<arr[2]){
                    swap(arr[0],arr[2]);
                }
                ans = max(ans,3*arr[0]);
                ans = max(ans,2*(arr[1]-arr[2])+arr[0]);
                ans = max(ans,3*(arr[1]-arr[2]));
                cout<<ans<<endl;
            }
        }
        else{
                cout<<max_n*n<<endl;
        }

        
    }

    return 0;
}
