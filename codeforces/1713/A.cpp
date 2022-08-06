#include "bits/stdc++.h"
using namespace std; 
typedef long long int ll;
const int N = 1e8;



int main() {
  int t;
  cin>>t;
  while(t--){
   int n;
   cin>>n;
   vector<int> arr_x;
   vector<int> arr_y;
   for(int i =0; i<n;i++){
    int x,y;
    cin>>x>>y;
    arr_x.push_back(x);
    arr_y.push_back(y);
   }

   int min_x =  *min_element(arr_x.begin(),arr_x.end());
   int max_x = *max_element(arr_x.begin(),arr_x.end());
   int min_y =  *min_element(arr_y.begin(),arr_y.end());
   int max_y = *max_element(arr_y.begin(),arr_y.end());

   int dist_x = 0;
   int dist_y = 0;
   if(min_x>=0 && max_x >= 0){
    dist_x =  2*max_x;
   }
   else if(min_x<=0 && max_x <= 0){
    dist_x =  -1*2*min_x;
   }
   else{
    dist_x =  2*(max_x - min_x);
   }

   if(min_y>=0 && max_y >= 0){
    dist_y =  2*max_y;
   }
   else if(min_y<=0 && max_y <= 0){
    dist_y =  -1*2*min_y;
   }
   else{
    dist_y =  2*(max_y - min_y);
   }

   cout<<dist_x+dist_y<<endl;
  }
}
