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
 
const ll N = 202020;
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
 
 
// ll mod = 1e9+7;
// // ll mod = 998244353;
// ll n;
// ll u[N], s[N], ans[N];
// vector<ll> a[N];
// // pair<ll, vector<ll> > b[N];
// // bool cmp(const vector<ll> &a1, const vector<ll> &a2) {
// // 	return a1.size() >= a2.size();
// // }
// ll mxind=-1;
// void go() {
// 	cin >> n;
// 	forn(i,n) {
// 		cin >> u[i];u[i]--;
// 	}
// 	// ll anss = 0;
// 	forn(i,n+1) ans[i] = 0;
// 	vector<ll> sum;
// 	sum.assign(n,0);
// 	forn(i,n) a[i].clear();
// 	forn(i,n) {
// 		cin >> s[i];
// 		a[u[i]].pb(s[i]);
// 		sum[u[i]] += s[i];
// 		// b[u[i]].second.pb(s[i]);
// 		// anss += s[i];
// 	}
// 	forn(i,n) {
// 		// b[i].first = b[i].second.size();
// 		sort(all(a[i])); reverse(all(a[i]));
// 		// sort(all(b[i].second)); reverse(all(b[i].second));
// 	}
// 	// sort(b,b+n);
// 	// forn(i,n) a[i] = b[i].second;
// 	forn(i,n) {
// 		forsn(it, 1, a[i].size()+1) {
// 			ans[it] += sum[i];
// 			forn(itt, a[i].size()%it) ans[it] -= a[i][a[i].size()-itt-1];
// 		}
// 	}
// 	// ll ind = n-1;
// 	// forsn(i,1,n+1) {
// 	// 	while(ind >= 0 and i > a[ind].size()) {
// 	// 		anss -= sum[ind];
// 	// 		ind--;
// 	// 	}
// 	// 	ans[i] = anss;
// 	// }
// 	// forsn(i, 1, n+1) {
// 	// 	forn(j, n) {
// 	// 		if(i >= a[j].size()) {break;}
// 	// 		ll p = ((ll)a[j].size()) % i;
// 	// 		if(p==0) continue;
// 	// 		ans[i] -= sums[j][a[j].size() - p];
// 	// 	}
// 	// }
// 	forsn(i,1,n+1) cout << ans[i] << " ";
// 	cout << ln;
// }

int n,m;
vector<int> dp[101][10101];
int ok[101][10101];
vector<int> ans;
vector<int> f(int n, int m) {
	if(m == n*n) {
		ans.pb(n);
		dp[n][m].clear();
		dp[n][m].pb(n);
		return dp[n][m];
	}
	if(m < 0) return {};
	if(ok[n][m] >= 0) return dp[n][m];
	int it = 1;
	// dp[n][m] = {};
	int itt=-1;
	while(it < n) {
		if(it*it >= m) break;
		vector<int> p = f(n- it, m- it*it);
		if(p.size()==0) continue;
		if( itt == -1 or dp[n][m].size() > p.size() ) {
			dp[n][m] = p;
			itt = it;
		}
		it++;
	}
	if(itt > -1) {
		dp[n][m].pb(itt);
		ok[n][m] = 1;
	} else ok[n][m] = 0;
	return dp[n][m];
}
void go1() {
	ans.clear();
	cin >> n >> m;
	if(m > n*n) {cout<<-1<<ln;return;}
	vector<int> p = f(n,m);
	if(ok[n][m]) {
		ans = dp[n][m];
		cout << ans.size() << ln;
		forn(i,ans.size()) cout << ans[i] << " ";
		cout << ln;
	}else cout << -1 << ln;


}


int main() {
    IO;
	// seive();
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t; t = 1;
    cin >> t;
	int tt = t;
	forn(i,101) forn(j,10001) ok[i][j] = -1;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go1();
	}
	// forn(i,10) {forn(j,10) cout << dp[i][j] << " ";cout << ln;}
}