#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
char parent[N];
int size[N];

void make(char v){
	parent[int(v) - int('a')] =v;
  size[int(v) - int('a')] = 1;
}

char find(char v){
	if(parent[int(v) - int('a')] == v){return v;}
	return parent[int(v) - int('a')] = find(parent[int(v) - int('a')]);
}

void Union(char a, char b){
  a = find(a);
  b = find(b);
	if(a!=b){
    if(size[int(a) - int('a')]<size[int(b) - int('a')]){
      swap(a,b);
    }
		parent[int(b) - int('a')] = a;
    size[int(a) - int('a')]+=size[int(b) - int('a')];
	}
}

int main() {

	int T;
    cin>>T;
    while(T--){
        int n;
        cin>>n;
        set<char> list;
        for(int i =0 ; i<26; i++){
            make(char(97+i));
            list.insert(char(97+i));
        }
        string t;
        cin>>t;
        string ans;
        map<char,char> mp;
        int count =0; 
        for(int i =0; i<n; i++){
            char x = t[i];
            if(mp.find(x) != mp.end()){
                ans+=mp[x];
             
            }
            else if(count == 25){
                char y = *list.begin();
                ans+=y;
                mp[x] = y;

            }
            else{
                auto it = list.begin();
                char y = *it;
                if(find(x) == find(y)){
                    it++;
                }
                y = *it;
                list.erase(y);
                count++;
                Union(x,y);
                mp[x] = y;
                ans+=y;
              
            }
        }
        cout<<ans<<endl;
      
    }

    
}