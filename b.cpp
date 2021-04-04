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
string s[1025];
vector<int> ans;
void go() {
	cin >> d >> n;
	forn(i,n) {
		cin >> s[i];
	}
	sort(s, s+n);
	set<int> over;
	while(over.size() < n) {
		int i = 0;
		while(i < n and over.count(i)) i ++;
		over.insert(i);
		if(!ans.empty()) ans.pb(-1);
		set<int> cur;
		forn(it, d) {
			if(s[i][it] == '1') {
				ans.pb(it);
				cur.insert(it);
			}
		}
		while(i < n) {
			int j = i+1;
			while(j < n) {
				if(over.count(j)) {
					j++;
					continue;
				}
				bool isb = true;
				forn(it, d) {
					if(s[i][it] == '1' and s[j][it] == '0') {
						isb = false;
						break;
					}
				}
				if(isb) break;
				j ++;
			}
			if(j == n) break;
			over.insert(j);
			forn(it, d) {
				if(s[j][it] == '1') {
					if(cur.count(it)) continue;
					cur.insert(it);
					ans.pb(it);
				}
			}
			i = j;
		}
	}
	cout << ans.size() << ln;
	for(auto u: ans) {
		if(u == -1) cout << "R ";
		else cout << u << " ";
	}
	cout << ln;
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