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

int n, m;
int a[26][26];
void go() {
	cin >> n >> m;
	cout << ln;
	forn(i,n) {
		string s;
		cin >> s;
		forn(j,m) {
			a[i][j] = s[j];
			if(a[i][j] == '?') a[i][j] = -1;
		}
	}
	bool row = true;
	forn(i,n) {
		int j = 0;
		while(j < m and a[i][j] == -1) {
			j++;
		}
		if(j == m) {
			row = false;
			break;
		}
	}
	// cout << "row " << row<<endl;
	if(row) {
		forn(i,n) {
			int j = 0;
			while(j < m and a[i][j] == -1) {
				j++;
			}
			while(j < m) {
				int k = j-1;
				while(k >= 0 and a[i][k] == -1) {
					a[i][k] = a[i][j]; k--;
				}
				k = j+1;
				while(k < m and a[i][k] == -1) {
					a[i][k] = a[i][j]; k++;
				}
				j = k;
			}
		}
	}else {
		forn(j,m) {
			int i = 0;
			while(i < n and a[i][j] == -1) {
				i++;
			}
			while(i < n) {
				int k = i-1;
				while(k >= 0 and a[k][j] == -1) {
					a[k][j] = a[i][j]; k--;
				}
				k = i+1;
				while(k < n and a[k][j] == -1) {
					a[k][j] = a[i][j]; k++;
				}
				i = k;
			}
		}
	}
	forn(i,n) {
		forn(j,n) {
			cout << (char)a[i][j];
		}
		cout << ln;
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