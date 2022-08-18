#include<bits/stdc++.h>
using namespace std;


int main() {
 int t;
 cin>>t;
 while(t--){
  int n,m;
  cin>>n>>m;
  int num_ones = 0;
  vector<vector<int>> grid;
   for(int i=0;i<n;i++){
    vector<int> arr;
    string x;
    cin>>x;
    for(int j=0;j<m; j++){
      int y;
      if(x[j] == '1'){
        y=1;
      }
      else{
        y =0;
      }
      if(y ==1 ){
        num_ones+=1;
      }
      arr.push_back(y);
      // cout<<y<<" ";
    }
    // cout<<endl;
    grid.push_back(arr);
  }

  bool alone_zero = 1;
  for(int i=1;i<n;i++){
    if(grid[i][0] == 0 && (grid[i-1][0] == 0 || grid[i][1] == 0 || grid[i-1][1] == 0)){
      alone_zero = 0;
      break;
    }
  }
  if(alone_zero){
    for(int i=1;i<n;i++){
    if(grid[i][m-1] == 0 && (grid[i-1][m-1] == 0 || grid[i][m-2] == 0 || grid[i-1][m-2] == 0)){
      alone_zero = 0;
      break;
    }
  }
  }

  if(alone_zero){
    for(int i=1;i<m;i++){
    if(grid[0][i] == 0 && (grid[0][i-1] == 0 || grid[1][i] == 0 || grid[1][i-1] == 0 )){
      alone_zero = 0;
      break;
    }
  }
  }

  if(alone_zero){
    for(int i=1;i<m;i++){
    if(grid[n-1][i] == 0 && (grid[n-1][i-1] == 0 || grid[n-2][i] == 0 || grid[n-2][i-1] == 0)){
      alone_zero = 0;
      break;
    }
  }
  }
  if(grid[n-2][m-1] == 0 && grid[n-1][m-2] == 0){
    alone_zero = 0;
  }
  if(alone_zero){
  for(int i = 1; i<n-1; i++){
    for(int j = 1; j<m-1; j++){
      if(grid[i][j] == 0 && (grid[i][j-1] == 0 || grid[i+1][j] == 0 || grid[i][j+1] == 0 || grid[i-1][j] == 0 || grid[i+1][j-1] == 0 || grid[i+1][j+1] == 0 || grid[i-1][j-1] == 0 || grid[i-1][j+1] == 0)){
        alone_zero = 0;
        break;
      }
    }
  }
  }
  if(num_ones == 0){
    cout<<0<<endl;
  }
  else if( num_ones == n*m){
    cout<<num_ones-2<<endl;

  }
  else if(alone_zero == 1){
    cout<<num_ones-1<<endl;

  }
  else{
    cout<<num_ones<<endl;

  }
  
  }
}