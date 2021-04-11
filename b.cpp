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

ll n, m;
ll pi[101];
ll cn[101];
ll ans = 0;
void dp(int i, vector<int> cni, ll p, ll s) {
	if(i >= n) return;
	// cout << i << " " << p << " " << s << ln;
	// forn(i, cni.size()) {
	// 	cout << cni[i] << " ";

	// }cout << ln;
	if(p > s) {
		return;
	}
	if(p == s) {
		ans = max(ans, s);
	}

	if(i == n-1) {
		if(p == s) {
			ans = max(ans, s);
		}
		while(cni[i] < cn[i]) {
			cni[i]++;
			p *= pi[i];
			s -= pi[i];
			if(p == s) {
				ans = max(ans, s);
			}
			if(p > s) {
				return;
			}
		}
		return;
	}
	dp(i+1, cni, p, s);
	while(cni[i] < cn[i]) {
		cni[i]++;
		p *= pi[i];
		s -= pi[i];
		// ll s0 = s;
		// bool isc = false;
		// forn(it, cni[i]) {
		// 	if(s0 % pi[i] > 0) {
		// 		isc = true;
		// 		break;
		// 	}
		// 	s0 /= pi[i];
		// }

		// if(isc)continue;
		// if(cni[i] == cn[i]) {
		// 	if(s % pi[i] > 0) return; 
		// }
		dp(i+1, cni, p, s);
	}


}

void go() {
	cin >> n;
	vector<int> cni;
	cni.assign(n, 0);
	ans = 0;
	ll su = 0;
	ll p = 1, s = 0;
	ll s0 = 0;
	forn(i,n) {
		cin >> pi[i] >> cn[i];
		su += cn[i];
		s += cn[i]* pi[i];
	}
	s0 = s;
	reverse(pi, pi + n);
	reverse(cn, cn + n);
	
	dp(0, cni, 1, s);
	cout << ans << ln;
}


vector<ll> s;
vector<ll> p;
vector<ll> t, to;
vector<ll> num, den;
void chk(ll it) {
	vector<ll> sc;
	sc.assign(n, 0);
	forn(i,m) {
		forn(j, n) {
			if((it & (1 << i)) ^ (s[j]=='0')) {
				sc[j]++;
			}
		}
	}
	forn(i,n) {
		if(sc[i] != p[i]) return;
	}
	forn(i, m) {
		if(it & (1 << i)) t[i] ++;
		to[i] ++;
	}
}

void go1() {
	cin >> n >> m;
	assert(m <= 10);
	s.assign(n, {});
	p.assign(n, 0);
	num.assign(n,0);
	den.assign(n,0);
	t.assign(m, 0);
	to.assign(m, 0);
	forn(i,n) {
		cin >> s[i] >> p[i];
	}
	forn(it, (1 << m)) {
		chk(it);
	}

	forn(i,m) {
		if(2*t[i] < to[i]) {
			num[i] = to[i]-t[i];
		}
		else num[i] = t[i];
		den[i] = to[i];
		assert(den[i] == (1 << m));
		// ll g = __gcd(num[i], den[i]);
		// num[i] /= g;
		// den[i] /= g;
	}
	ll ans = 0;
	forn(it, (1 << m)) {
		forn(i, m) {
			if(it & (1 << i)) {

			}
		}
	}

}

int main() {
    IO;
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    cin >> t;
	int tt = t;
    while(t--) {
		cout << "Case #"<<tt-t<<": ";
		go();
	}
}