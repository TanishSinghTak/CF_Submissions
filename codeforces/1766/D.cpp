#include<bits/stdc++.h>

using namespace std;

#define fore(i, l, r) for(int i = int(l); i < int(r); i++)
#define sz(a) int((a).size())

typedef long long li;

const int INF = int(1e9);
const int N = int(1e7) + 5;

int mind[N];

void precalc() {
	fore (i, 0, N)
		mind[i] = i;
	
	for (int p = 2; p < N; p++) {
		if (mind[p] != p)
			continue;
		for (int d = 2 * p; d < N; d += p)
			mind[d] = min(mind[d], p);
	}
}

int x, y;

inline bool read() {
	if(!(cin >> x >> y))
		return false;
	return true;
}

vector<int> getPrimes(int v) {
	vector<int> ps;
	while (v > 1) {
		if (ps.empty() || ps.back() != mind[v])
			ps.push_back(mind[v]);
		v /= mind[v];
	}
	return ps;
}

inline void solve() {
	int d = y - x;
	if (d == 1) {
		cout << -1 << '\n';
		return;
	}
	
	int r = INF;
	for (int p : getPrimes(d))
		r = min(r, ((x + p - 1) / p) * p);
	cout << r - x << '\n';
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	int tt = clock();
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cout << fixed << setprecision(15);
	
	precalc();
	
	int t; cin >> t;
	while (t--) {
		read();
		solve();
		
#ifdef _DEBUG
		cerr << "TIME = " << clock() - tt << endl;
		tt = clock();
#endif
	}
	return 0;
}