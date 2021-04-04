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
ll md = 1e9 + 7;
ll a[101][101];
int e1 = 0, e2 = 0;
int o1 = 0, o2 = 0;
void go(){
	cin >> n;
	forn(i,n) forn(j,n) a[i][j] = -1;
	if(n&1) {
		o1 = 1;
		o2 = 1;
		e1 = 1;
		e2 = 2;
	}else {
		o1 = 1;
		o2 = 1;
		e1 = 1;
		e2 = 2;
	}
	forn(i, n*n) {
		int d;cin >> d;
		if(d == 1) {
			if(e1 > n) {
				cout << 3 << " " << o1 << " " << o2 << endl;
				o2 += 2;
				if(o2 > n) {
					o2 -= n;
					o1 ++;
					if(n%2 == 0) o2 = 3-o2;
				}
				continue;
			}
			cout << 2 << " " << e1 << " " << e2 << endl;
			e2 += 2;
			if(e2 > n) {
				e2 -= n;
				e1 ++;
				if(n%2 == 0) e2 = 3 - e2;
			}

		} else {
			if(o1 > n) {
				cout << 5-d << " " << e1 << " " << e2 << endl;
				e2 += 2;
				if(e2 > n) {
					e2 -= n;
					e1 ++;
					if(n%2 == 0) e2 = 3-e2;
				}
				continue;
			}
			cout << 1 << " " << o1 << " " << o2 << endl;
			o2 += 2;
			if(o2 > n) {
				o2 -= n;
				o1 ++;
				if(n%2 == 0) o2 = 3-o2;
			}
		}
	}
}


int main() {
    IO;
	cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;t=1;
    // cin >> t;
    while(t--) 
		go();
}