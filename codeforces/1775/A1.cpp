#include<bits/stdc++.h>
using namespace std;


int main() {

    int t;
    cin>>t;
    string str;
    while(t--){
        cin>>str;
        int j =1; 
        int len = str.size();
        while(str[j] != 'a' && j<len-1){
            j++;
        }
        if(j==len-1){
            cout<<str[0]<<" "<<str.substr(1,len-2)<<" "<<str[len-1]<<endl;
        }
        else{
            cout<<str.substr(0,j)<<" "<<'a'<<" "<<str.substr(j+1, len-j-1)<<endl;
        }
        
    }

}
