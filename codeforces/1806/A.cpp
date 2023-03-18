#include<bits/stdc++.h>
using namespace std;
#define Fast_io ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
#define endl '\n'     
#define int long long 

signed main() {

	Fast_io;
	int t;
	cin>>t;
	while(t--){
		int x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(y2<y1 || (y2+x1)<(x2+y1)){
			cout<<-1<<endl;
		}else{
			int ans = abs(y2-y1);
			ans += (x1+(y2-y1) -x2);
			cout<<ans<<endl;
		}
	}

	return 0;
}
