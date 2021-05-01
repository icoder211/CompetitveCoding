/**
 * Author: icoder211
 */
 
#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define Nos ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
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
 
const int N = 201;
ll md = 1e9+7;
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


ll n,m,b;
vector<vector<ll>> a;
ll ans = 0;
vector<ll> col;

ll dp[101010][200];
ll sums(vector<ll> &col) {
	forn(i,b+2) {
		forn(j,m) {
			dp[i][j] = 0;
		}
	}
	if(col.back() <= b+1) dp[col.back()][m-1] = 1;
	dp[0][m-1] = 1;
	
	for(int j = m-1; j > 0;j--) {
		forn(i, b+2) {
			dp[i][j-1] += dp[i][j]; dp[i][j-1] %= md;
			if(col[j] + i > b+1) continue;
			dp[col[j] + i][j-1] += dp[i][j];
			dp[col[j] + i][j-1] %= md;
		}
	}
	// forn(i,m) cout << col[i] << " ";cout << ln;
	// forn(i,b+1) {
	// 	forn(j,m) {
	// 		cout << dp[i][j] << " ";
	// 	}
	// 	cout << ln;
	// }
	return dp[b][0];
}


ll chk(int itt) {
	col.clear();
	forn(i,m) col.pb(0);
	forn(i,20) {
		if(itt & (1 << i)) {
			// take row i
			assert(i < n);
			forn(j,m) col[j] += a[i][j];
		}
	}
	// cout << "ITT " << itt << ln;
	return sums(col);
}
void go1() {
	ans = 0;
	cin >> n >> m >> b;
	if(n > m) {
		a.assign(m,{});
		forn(i,n) {
			forn(j,m) {
				int in;cin >> in;
				a[j].pb(in);
			}
		}
		swap(n,m);
	}else {
		a.assign(n,{});
		forn(i,n) {
			a[i].clear();
			forn(j,m) {
				int in;cin >> in;
				a[i].pb(in);
			}
		}
	}
	// forn(i,n) {forn(j,m)cout << a[i][j] << " "; cout << ln;}
	assert(n <= 8);
	if(n > 30) return;
	forn(itt, 1 << n) {
		ans += chk(itt);
		ans %= md;
	}
	cout << ans << ln;

}

void go2() {
	ans = 0;
	cin >> n >> m >> b;
	a.assign(n,{});
	forn(i,n) {
		a[i].clear();
		forn(j,m) {
			int in;cin >> in;
			a[i].pb(in);
		}
	}
	if(n*m > 10) return;
	forn(i,1<<n) {
		forn(j, 1<<m) {
			ll sum = 0;
			forn(it,32) {
				if(i & (1 << it)) {
					// take row it
					forn(itt, 32) {
						if(j & (1 << itt)) {
							sum += a[it][itt];
						}
					}
				}
			}
			if(sum == b) ans++;
			ans %= md;
		}
	}
	cout << ans << ln;
}

int main() {
    Nos;
	// seive();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int t; t = 1;
    cin >> t;
	int tt = t;

    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go1();
	}
	// fflush(stdout);
}