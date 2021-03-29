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
// ll a[1000][1000];
vector<int> ans;
void go() {
	cin >> n >> m;
	ans.assign(m+1, -1);
	ans[0] = 0;
	forn(itt,n) {
		// cout << "ha ";
		ld tk, xi, yi;
		cin >> tk >> xi >> yi;
		if(tk == 1) {
			ll x = xi;
			x = floor((x + 99999)/100000);
			assert(x > 0);
			vector<int> vis;
			vis.assign(m+1, 0);
			int i = 0;
			for(; i <= m; i++) {
		        // cout << i << " ";

				if(vis[i]) continue;
				if(ans[i] < 0) continue;
				int p = i;
				for (int j = p; j <= m && ((j-p) / x) <= yi; j += x) {
					vis[j] = 1;
					if(ans[j] < 0) ans[j] = itt+1;
					else {
						p = j;
					}
				}
			}
		}else {
		// cout << "hahaha ";

			xi = (xi / (long double)100000);
			vector<int> vis;
			vis.assign(m+1, 0);
			int i = 1;
			for (; i <= m; i++) {
				// cout << i << " " ;
				if(vis[i]) continue; vis[i] = 1;
				if(ans[i] < 0) continue;
				int p = i;
				int times = 0;
				for(int j = p;j <= m && j > 0 && times <= yi; j = ceil((long double)j * xi)) {
					// cout << j << " ";
					if(ans[j] < 0) {
						ans[j] = itt+1;
						vis[i] = 1;
					}
					times ++;
				}
			}
		}
	}
	forsn(i,1,m+1) cout << ans[i] << " ";
	cout << ln;
}


int main() {
    IO;
	int t;t=1;
    // cin >> t;
    while(t--) 
		go();
}