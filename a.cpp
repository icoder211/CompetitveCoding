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

 
 
ll n, m;
// vector<ll> vis;
// vector<ll> pr;
ll a[500][500];
ll b[500][500];
set<ll> r[500];
set<ll> c[500];
ll ri[500];
ll ci[500];
void go() {
	cin >> n;
	
	forn(i,n) {
		ri[i] = 0;
		ci[i] = 0;
		r[i] = {};
		c[i] = {};
		forn(j,n) {
			cin >> a[i][j];
			if(a[i][j] == -1) {
				r[i].insert(j);
				c[j].insert(i);
			}
		}
	}
	ll ans = 0;
	forn(i, n) {
		forn(j, n) {
			cin >> b[i][j];
		}
	}
	int dummy;
	forn(i,2*n) cin >> dummy;

	ll res = 0;
	while(true) {
		bool isbreak = true;
		forn(i,n) {
			if(r[i].size() == 1) {
				c[*r[i].begin()].erase(i);
				r[i].clear();
			}
			if(c[i].size() == 1) {
				r[*c[i].begin()] .erase(i);
				c[i].clear();
			}
		}
		forn(i,n) {
			if(r[i].size() > 1 or c[i].size() > 1) {
				isbreak = false;
				break;
			}
		}
		if(isbreak) break;
		ll mnr = 1e16;
		int ir = -1, ic = -1;
		forn(i,n) {
			if( mnr > b[i][*r[i].begin()] ) {
				ir = i;
				ic = *r[i].begin();
				mnr = b[i][*r[i].begin()];
			}
			if(mnr > b[*c[i].begin()][i] ) {
				ir = *c[i].begin();
				ic = i;
				mnr = b[*c[i].begin()][i];
			}
		}
		r[ir].erase(ic);
		c[ic].erase(ir);
		res += mnr;
	}
	cout << res << ln;

}

set<ll> rr[500];
set<ll> cc[500];
vector<ll> v;
ll chk(ll i) {
	ll res = 0ll;
	ll j = 0;
	forn(i,n) {
		rr[i].clear();
		cc[i].clear();
	}
	while(j < v.size()) {
		if((i >> j) & 1) {
			res += b[v[j]/n][v[j]%n];
			// cout <<1;
		}else {
			rr[v[j]/n].insert(v[j]%n);
			cc[v[j]%n].insert(v[j]/n);
			// cout << 0;
		}
		j ++;
	}
	bool ok = true;
	while (true) {
		bool isb = true;
		ok = true;
		forn(i,n) {
			if(rr[i].size() == 1) {
				if( cc[*rr[i].begin()].count(i) == 0) {
					assert(2>3);
				}
				cc[*rr[i].begin()].erase(i);
				rr[i].clear();
				isb = false;
				break;
			}
			if(cc[i].size() == 1) {
				if(rr[*cc[i].begin()].count(i) == 0) {
					assert(2>3);
				}
				rr[*cc[i].begin()].erase(i);
				cc[i].clear();
				isb = false;
				break;
			}
			if(rr[i].size() > 1 or cc[i].size() > 1) ok = false;
		}
		if(isb) {
			break;
		}
	}
	forn(i,n) {
		rr[i].clear();
		cc[i].clear();
	}
	
	if(ok) return res;
	else return 1e16;
}
void go1() {
	cin >> n;
	v.clear();
	forn(i,n) {
		ri[i] = 0;
		ci[i] = 0;
		r[i] = {};
		c[i] = {};
		forn(j,n) {
			cin >> a[i][j];
			if(a[i][j] == -1) {
				// r[i].pb(j);
				// c[j].pb(i);
				v.pb(i*n+j);
			}
		}
	}
	forn(i,n) forn(j,n) cin >> b[i][j];
	ll dum;
	forn(i,2*n) cin >> dum;
	ll p = 1ll << (ll)v.size();
	ll mn = 1e16;
	forn(i, p) {	
		mn = min(mn, chk(i));
	}
	assert(mn < 1e16);
	cout << mn << ln;

}

int main() {
    IO;
	// vis.assign(1e7+1, 0);
	// int i =0 ;
	// for(int i = 2;i * i <= 1e7; i++ ) {
	// 	if(vis[i]) continue;
	// 	pr.pb(i);
	// 	// cout << i << " ";
	// 	for(int j = i*i;j <= 1e7;j += i) {
	// 		vis[j] = 1;
	// 	}
	// }
	
	int t;cin >> t;
	int tt = t;
	while(t--) 
	{
		cout << "Case #" << tt-t << ": ";
		go();
	}
 
	// cout << ans << ln;
	
	
}