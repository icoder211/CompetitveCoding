/**
 * Author: icoder211
 */

#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(ll i = 0;i < n;i++)
#define forsn(i, s, n) for(ll i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
 
typedef long double ld;
typedef long long ll;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};

ll exp(ll n, ll m, ll md) {
	ll res = 1;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*n) % md;
		m /= 2;
	}
	return res;
}
ll gcd(ll c, ll d, ll &x, ll &y) {
	if(d == 0) {
		x = 1;
		y = 0;
		return c;
	}
	ll g = gcd(d, c%d, x, y);
	ll x0 = y;
	ll y0 = x - y*(c/d);
	x=x0;
	y=y0;
	return g;
}
vector<int> pr;
void seive() {
	vector<int> vis;
	pr.clear();
	vis.assign(1e7+1, 0);
	int i =0 ;
	for(int i = 2;i * i <= 1e7; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		// cout << i << " ";
		for(int j = i*i;j <= 1e7;j += i) {
			vis[j] = 1;
		}
	}
}

int n, d;
ll md = 1e9 + 7;
int a[1025];
vector<string> s;
vector<int> ans;

bool contain(string ss, string t) {
	forn(it, d) {
		if(ss[it] == '1' and t[it] == '0') return false;
	}
	return true;
}

vector<vector<int>> ad;
set<pair<int, int>> in;
vector<int> indeg;
vector<int> nxt, prv;
void go() {
	cin >> d >> n;
	s.assign(n, {});
	forn(i,n) {
		cin >> s[i];
	}
	// sort(s, s+n);
	ad.assign(n, {});
	indeg.assign(n, 0);
	nxt.assign(n, -1);
	prv.assign(n, -1);

	forn(i,n) {
		forn(j,n) {
			if(i==j) continue;
			if(contain(s[i], s[j])) {
				ad[i].pb(j);
				indeg[j]++;
			}
		}
	}
	// vector<int> end;
	forn(i,n) {
		// if(ad[i].size() == 0) {
		// 	end.pb(i);
		// }
		in.insert({indeg[i], i});
	}
	int mxwidht = 0;
	set<int> end; forn(i,n) end.insert(i);
	while(!in.empty()) {
		vector<int> b;
		while(!in.empty() && in.begin()->first == 0) {
			b.pb(in.begin()->second);
			in.erase(in.begin());
		}
		mxwidht = max(mxwidht, (int)b.size());
		forn(i, b.size()) {
			forn(j, ad[b[i]].size()) {
				in.erase( { indeg[ ad[b[i]][j] ],  ad[b[i]][j] }) ;
				indeg[ ad[b[i]][j] ] --;
				if(indeg[ ad[b[i]][j] ] == 0 && prv[ ad[b[i]][j] ] == -1) {
					prv[ ad[b[i]][j] ] = b[i];
					end.erase(b[i]);
				}
				in.insert( { indeg[ ad[b[i]][j] ],  ad[b[i]][j] }) ;
			}
		}
	}

	// cout << "prev ";
	// forn(i,n) {
	// 	cout << prv[i] << " ";
	// } cout << ln;

	// cout << mxwidht << ln;

	// cout << "end ";
	// for(auto u: end) cout << u << " ";
	// cout << ln;

	vector<vector<int>> paths;
	for(auto it: end) {
		paths.pb({});
		paths.back().pb(it);
		int u = it;
		while(prv[u] != -1) {
			paths.back().pb(prv[u]);
			u = prv[u];
		}
		reverse(all(paths.back()));
	}

	// forn(i, paths.size()) {
		// cout << "i" << i << " ";
	// 	forn(j, paths[i].size()) {
	// 		cout << paths[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	
	forn(i, paths.size()) {
		if(!ans.empty()) ans.pb(-1);
		set<int> st;
		forn(j, paths[i].size()) {
			forn(it, d) {
				if(s [ paths[i][j] ][ it ] == '1' && !st.count(it)) {
					st.insert(it);
					ans.pb(it);
				}
			}
		}
		st.clear();
	}
	cout << ans.size() << ln;
	forn(it, ans.size()) {
		if(ans[it] == -1) cout << "R ";
		else cout << ans[it] << " ";
	}
	
}


int main() {
    IO;
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    // cin >> t;
    while(t--) 
		go();
}