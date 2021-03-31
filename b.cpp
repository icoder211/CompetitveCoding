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
map<ll, ll> cnt;
map<ll, ll> ccnt;
ll a[200000];
void go1() {
	cnt.clear();
	ccnt.clear();
	cin >> n;
	forn(i,n) {
		cin >> a[i];
		cnt[a[i]] ++;
	}
	for(auto u: cnt) {
		if(u.first > 2) ccnt[2] ++;
		ccnt[u.first] ++;
	}
	if(ccnt[2] >= 2 or ccnt[4] > 0) {
		cout << "YES\n";
	}
}

int main() {
    IO;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t;t=1;
    // cin >> t;
    while(t--) 
		go();
}