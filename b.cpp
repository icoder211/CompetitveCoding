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
	n %= md;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*1ll*n) % md;
		if(n<0) {
			// cout << n << " " << m << " " << md << endl;
			assert(n>=0);
		}
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
 
const ll N = 101010;
vector<ll> pr;
vector<ll> lp;
// vector<int> g[N];
void seive() {
	int N = 2e5+1;
	vector<ll> vis;
	lp.assign(N, -1);
	pr.clear();
	vis.assign(N, 0);
	ll i = 0;
	for(ll i = 2;i <= N; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		for(ll j = i;j <= N;j += i) {
			vis[j] = 1;
			if(lp[j] == -1) lp[j] = i;
			// g[j].pb(i);
		}
	}
}
 
 
ll mod = 1e9+7;
// ll mod = 998244353;
 
int n, m;
vector<int> ad[N];
int cl[N] = {0};
int a1[3*N], a2[3*N]; int ans=0;
bool ok = true;
int lev[N];
int low[N];
void dfs(int y, int p, int level) {
	lev[y] = level;
	low[y] = level;
	cl[y]=1;
	for(auto u: ad[y]) {
		if(u==p) continue;
		if(cl[u] == 2) continue;
		a1[ans]=y; a2[ans++]=u;
		if(cl[u] == 1) {
			assert(lev[u] < level);
			low[y] = min(low[y], lev[u]);
			continue;
		}
		dfs(u,y,level+1);
		low[y] = min(low[y], low[u]);
	}
	cl[y] = 2;
	if(low[y] > level-1 and y>0) {
		// bridge -> y and par[y]
		ok = false;
	}

}
void go() {
	cin >> n;
	cin >> m;
	forn(i,m) {
		int l,r; cin >> l >> r;l--;r--;
		ad[l].pb(r);
		ad[r].pb(l);
	}
	dfs(0,0,0);
	if(!ok) {
		cout<<0<<ln;
		return;
	}
	cout<<ln;
	forn(i,m) cout << a1[i] +1<< " " << a2[i] +1<< ln;
}
 

int main() {
    IO;
	// seive();
	cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    // cin >> t;
	int tt = t;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
	}
}