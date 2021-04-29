/**
 * Author: icoder211
 */
 
#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define IO ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i = 0;i < n;i++)
#define forsn(i, s, n) for(int i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
#define mp(i,j) {i,j}
 
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
 
const ll N = 5050;
// vector<ll> pr;
// vector<ll> lp;
// // vector<int> g[N];
// void seive() {
// 	int N = 2e5+1;
// 	vector<ll> vis;
// 	lp.assign(N, -1);
// 	pr.clear();
// 	vis.assign(N, 0);
// 	ll i = 0;
// 	for(ll i = 2;i <= N; i++ ) {
// 		if(vis[i]) continue;
// 		pr.pb(i);
// 		for(ll j = i;j <= N;j += i) {
// 			vis[j] = 1;
// 			if(lp[j] == -1) lp[j] = i;
// 			// g[j].pb(i);
// 		}
// 	}
// }
 
 
ll mod = 1e9+7;
// ll mod = 998244353;
ll n;
ll u[N], s[N], ans[N];
vector<ll> a[N];
pair<ll, vector<ll> > b[N];
// bool cmp(const vector<ll> &a1, const vector<ll> &a2) {
// 	return a1.size() >= a2.size();
// }
ll mxind=-1;
void go() {
	cin >> n;
	forn(i,n) {
		cin >> u[i];u[i]--;
	}
	ll anss = 0;
	forn(i,n) a[i].clear();
	forn(i,n) {
		cin >> s[i];
		a[u[i]].pb(s[i]);
		// b[u[i]].second.pb(s[i]);
		anss += s[i];
	}
	forn(i,n) {
		// b[i].first = b[i].second.size();
		sort(all(a[i])); reverse(all(a[i]));
		// sort(all(b[i].second)); reverse(all(b[i].second));
	}
	// sort(b,b+n);
	// forn(i,n) a[i] = b[i].second;
	auto cmp = [](vector<ll> a, vector<ll> b) { return a.size() > b.size(); };
	sort(a,a+n,cmp);
	vector<ll> sum;
	vector<vector<ll>> sums;
	forn(i,n) {
		sum.pb(0);
		sums.pb({});
		// for(auto u: a[i]) sum[i] += u;
		if(a[i].size()==0)continue;
		sums[i].assign(a[i].size(), 0);
		sums[i][a[i].size()-1] = a[i].back();
		for(int j = a[i].size()-2;j >= 0;j--) {
			sums[i][j] = sums[i][j+1] + a[i][j];
		}
		if(a[i].size() > 0) sum[i] = sums[i][0];
	}
	ll ind = n-1;
	forsn(i,1,n+1) {
		while(ind >= 0 and i > a[ind].size()) {
			anss -= sum[ind];
			ind--;
		}
		ans[i] = anss;
	}
	forsn(i, 1, n+1) {
		forn(j, n) {
			if(i >= a[j].size()) {break;}
			ll p = ((ll)a[j].size()) % i;
			if(p==0) continue;
			ans[i] -= sums[j][a[j].size() - p];
		}
	}
	forsn(i,1,n+1) cout << ans[i] << " ";
	cout << ln;
}




int main() {
    IO;
	// seive();
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t; t = 1;
    cin >> t;
	int tt = t;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
	}
}