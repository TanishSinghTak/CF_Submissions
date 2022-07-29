#include "bits/stdc++.h"
using namespace std;
const int N = 1e5+10;
int parent[N];
int size[N];
multiset<int> sizes;
map<int,int> size_map;
void make(int v){
	parent[v] =v;
    size[v] = 1;

	size_map[1] ++;
}

int find(int v){
	if(parent[v] == v){return v;}
	return parent[v] = find(parent[v]);
}

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

void Union(int a, int b){
  a = find(a);
  b = find(b);
	if(a!=b){
    	if(size[a]<size[b]){
      		swap(a,b);
    	}
		parent[b] = a;
		merge(a,b);
    	size[a]+=size[b];
	}
}

int main() {
	int n;
	cin>>n;
	vector<pair<int,int>> cities(n+1);
	for(int i = 1; i<n+1; i++){
		int x,y;
		cin>>x>>y;
		pair<int,int> city = {x,y};
		cities[i] = city;
	}

	vector<int> c(n+1), k(n+1);
	for(int i = 1; i <=n; i++){
		cin>>c[i];
	}
	for(int i = 1; i <=n; i++){
		cin>>k[i];
	}

	vector<pair<long long,pair<int,int>>> edges;

	for(int i=1;i<=n;i++){
		edges.push_back({c[i],{0,i}});
	}

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			long long dist = abs(cities[i].first - cities[j].first) + abs(cities[i].second - cities[j].second);
			long long cost = dist*1LL*(k[i]+k[j]);
			edges.push_back({cost,{i,j}});
		}
	}

	sort(edges.begin(), edges.end());

	for(int i = 0; i<=n;i++) make(i);

	long long total_cost = 0;
	long long power_stations = 0;
	vector<int> power_cities;
	long long connections= 0;
	vector<pair<int,int>> city_connections;
	for(auto edge : edges){
		int first = edge.second.first;
		int second = edge.second.second;
		if(find(first) != find(second)){
			Union(first, second);
			total_cost+=edge.first;
			if(first == 0){
				power_stations++;
				power_cities.push_back(second);
			}
			else{
				connections++;
				city_connections.push_back(edge.second);
			}
		}
	}
	
	cout<<total_cost<<endl;
	cout<<power_stations<<endl;
	for(auto power_city : power_cities){
		cout<<power_city<<" ";
	}
	cout<<endl;
	cout<<connections<<endl;
	for(auto city_pair : city_connections){
		int first = city_pair.first;
		int second = city_pair.second;
		cout<<first<<" "<<second<<endl;
	}
}