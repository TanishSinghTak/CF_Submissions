#include <bits/stdc++.h>
using namespace std;

signed main(){
    ios_base::sync_with_stdio(false); cin.tie(0);

    int tt=1;
    cin>>tt;

    while(tt--){
        int n;
        cin>>n;
        string s;
        cin>>s;
        int ans=0;
        for(int i=0;i<n;i++){
            if(ans==0){
                if(s[i]=='m' || s[i]=='M'){
                    ans=1;
                }
                else{
                    ans=-1;
                    break;
                }
            }
            else if(ans==1){
                if(s[i]=='m' || s[i]=='M'){
                    ans=1;
                }
                else if(s[i]=='e' || s[i]=='E'){
                    ans=2;
                }
                else{
                    ans=-1;
                    break;
                }
            }
            else if(ans==2){
                if(s[i]=='e' || s[i]=='E'){
                    ans=2;
                }
                else if(s[i]=='o' || s[i]=='O'){
                    ans=3;
                }
                else{
                    ans=-1;
                    break;
                }
            }
            else if(ans==3){
                if(s[i]=='o' || s[i]=='O'){
                    ans=3;
                }
                else if(s[i]=='w' || s[i]=='W'){
                    ans=4;
                }
                else{
                    ans=-1;
                    break;
                }
            }
            else if(ans==4){
                if(s[i]=='w' || s[i]=='W'){
                    ans=4;
                }
                else{
                    ans=-1;
                    break;
                }
            }
            else{
                break;
            }
        }
        if(ans!=4){
            cout<<"NO"<<'\n';
        }
        else{
            cout<<"YES"<<'\n';
        }
    }
    return 0;
}
/*
1. Check borderline constraints. Can a variable you are dividing by be 0?
2. Use ll while using bitshifts
3. Do not erase from set while iterating it
4. Initialise everything
5. Read the task carefully, is something unique, sorted, adjacent, guaranteed??
6. DO NOT use if(!mp[x]) if you want to iterate the map later
7. Are you using i in all loops? Are the i's conflicting?
8. Use iterator to iterate thorugh maps if you want to changes the values
9. Use vector in place of pair to speed up typing
10. Try to make function outside all the loops in open space in order to reduce numerous compiling
11. Try not to INT_MAX because of out of bounds issues
*/ 