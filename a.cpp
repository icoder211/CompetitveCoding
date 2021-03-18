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
 
ll exp(ll n, ll m, ll md) {
	ll res = 1;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*n) % md;
		m /= 2;
	}
	return res;
}
 
// ll n, m;
// // ll a[200005];
// // vector<int> cnt;
// void go() {
// 	cin >> n >> m;
// 	if(n&1) {
// 		cout << n/2 << " " << n/2 << " " << 1 << ln;
// 		return;
// 	}
// 	if(n%3 == 0) {
// 		cout << n/3 << " " << n/3 << " " << n/3 << ln;
// 		return;
// 	}
// 	if(n%4 > 0) cout << n/2-1 << " " << n/2-1 << " " << 2 << ln;
// 	else cout << n/4 << " " << n/4 << " " << n/2 << ln;
 
	
// }
 
// void go1() {
// 	cin >> n >> m;
// 	if(m >= n/2 + 1) {
// 		forn(i,m-1) cout << 1 << " ";
// 		cout << n - m + 1 << ln;
// 		return;
// 	}
// 	if( m <= 30 && n % (1ll << (ll)(m-1)) == 0) {
// 		cout << n / (1ll << (m-1)) << " ";
// 		while(m > 1) {
// 			cout << n / (1ll << (m-1)) << " ";
// 			m --;
// 		}
// 		cout << ln;
// 		return;
// 	}
	
// 	forn(i, m-1) {
// 		if((n-i) % (m-i) == 0) {
// 			forn(j, m-i) {
// 				cout << ((n-i) / (m-i)) << " ";
// 			}
// 			forn(j, i) cout << 1 << " ";
// 			cout << ln;
// 			return;
// 		}
// 	}
// 	assert(2 > 3);
// }
 
 
ll n;
vector<ll> vis;
vector<ll> pr;
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
ll c,d,x;
void go2() {
	cin >>c>>d>>x;
	ll p,q;
	
	ll g = gcd(c,d,p,q);
	
	assert(g > 0);
	if(x%g) {
		cout << 0 << ln;
		return;
	}
	q *= -1;
	assert(p*c - q*d == g);
	p *= (x/g);
	q *= (x/g);
	// cout << p << " " << q << " ";

	ll up = 1e9;
	p -= up*(d/g);
	q -= up*(c/g);
	if(p <= 0) {
		ll up = abs(p)/(d/g);
		p += up * (d/g);
		q += up * (c/g);
		if(p <= 0) {
			p += (d/g);
			q += c/g;
		}
	}
	if(q <= 0) {
		ll up = abs(q)/(c/g);
		p += up * (d/g);
		q += up * (c/g);
		if(q <= 0) {
			p += (d/g);
			q += c/g;
		}
	}
	while(p < q) {
		if(c >= d) {
			cout << "0" << ln;
			return;
		}
		p += d/g;
		q += c/g;
	}
	// cout << p << " " << q << ln;
	ll ans = 0;
	while(p >= q) {
		ll l = max(p,q);
		ll g0 = min(p,q);
		if(l > 1e3) break;
		if(l%g0) {
			p += d/g;
			q += c/g;
			continue;
		}
		// cout << l << " " << g0 << " ";
		int d0 = 0;
		ll res =1;
		if(g0 == 1) {
			while(d0 < pr.size() and pr[d0] * pr[d0] <= l) {
				if(l % pr[d0] == 0) {
					while(l % pr[d0] == 0) {
						l /= pr[d0];
					}
					res *= 2ll;
				}
				d0 ++;
			}
			if(l > 1) {
				res *= 2ll;
			}
			
		}
		while(g0 > 1 and d0 < pr.size() and pr[d0]*pr[d0] <= l) {
			while(g0%pr[d0] == 0) {
				l/=pr[d0];
				g0/=pr[d0];
			}
			if(l%pr[d0] == 0) res*=2ll;
			d0 ++;
		}
		if(g0 > 1) {
			l /= g0;
			if(l % g0 == 0) res *= 2ll;
		}
		
		// cout << res << ln;
		ans += res;
		p += d/g;
		q += c/g;
	}

	cout << ans << ln;



}
 
int main() {
    IO;
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
	
	int t;cin >> t;
	while(t--) 
	{
		go2();
	}
 
	// cout << ans << ln;
	
	
}