#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
ll gcd(ll a, ll b)
{
    if (a == 0)
        return b;
    return gcd(b % a, a);
}
void yesorno(bool f){
    if(f)
        cout<<"YES\n";
    else
        cout<<"NO\n";
    return;
}
ll mod = 1000000007;//998244353;

ll power(ll x, ll y, ll p = mod)
{
 
    // Initialize answer
    ll res = 1;
 
    // Check till the number becomes zero
    while (y > 0) {
 
        // If y is odd, multiply x with result
        if (y % 2 == 1)
            res = (res * x)%mod;
 
        // y = y/2
        y = y >> 1;
 
        // Change x to x^2
        x = (x * x)%mod;
    }
    return res % p;
}

ll modinv(ll a, ll p = mod){
    return power(a,p-2);
}
vector<ll> facts(int(1e6)+1,1);

ll ncr(ll n, ll r){
    ll res = facts[n];
    res%=mod;
    res*=modinv((facts[r]*facts[n-r])%mod);
    res%=mod;
    return res;
}
map<pair<ll,ll>,ll> edges;
vector<vector<ll>> adj;
ll nice(ll n){
    ll ans = n*(n+1);
    ans%=mod;
    ans*=(2*n+1);
    ans%=mod;
    ll z = modinv(6);
    ans*=z;
    ans%=mod;
    return ans;
}
int main()
{
    Fast_io;
    
    
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin); //file input.txt is opened in reading mode i.e "r"
    freopen("output.txt","w",stdout);  //file output.txt is opened in writing mode i.e "w"
    #endif

    string s;

    ll t=1,k,z,i,j,n,m,a,q,c,h,b,l,r,u,d,y;
    ll x,ans;
    cin>>t;
        //cout.precision(30);
    bool f;
    
    

    while(t--)
    {   
        cin>>n;

        vector<ll> x(n),y(n),x1,y1;

        vector<pair<ll,ll>> a(n); 

        for(i=0;i<n;++i){
            cin>>a[i].first;
            a[i].second = i;
        }

        sort(a.begin(),a.end());
        z = 1;
        f = 1;
        j = 0;
        
        for(i=1;i<=n;++i){
            if(a[j].first==i){
                //cout<<j<<"\n";
                z = 0;
                while(j<n && a[j].first==i){
                    j++;
                    z++;
                }

                if(z>2){
                    f = 0;
                    break;
                }

                if(z==1){
                    x[a[j-1].second] = y[a[j-1].second] = i;
                    //cout<<"hi";
                }
                else if(z==2){
                    if(x1.size()){
                        k = x1[int(x1.size())-1];
                        //cout<<k<<"\n";
                        x1.pop_back();
                        //cout<<a[j-1].second<<"i\n";
                        x[a[j-2].second] = i;
                        y[a[j-1].second] = i;
                        x[a[j-1].second] = k;
                        y[a[j-2].second] = k;
                    }
                    else{
                        f = 0;
                        break;
                    }
                }
                z = 1;
            }
            else{
                x1.push_back(i);
                //cout<<"hi";
            }
                
                
        }

        yesorno(f);
        if(f){
            for(auto &it : x)cout<<it<<" ";
            cout<<"\n";
            for(auto &it : y)cout<<it<<" ";
            cout<<"\n";
        }

    }
}