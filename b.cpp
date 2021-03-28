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

int t, n, q;
vector<int> a;
int query(int w,int e, int r) {
    cout << w << " " << e << " " << r << endl;
	int d;cin>>d;
	// assert(d != -1);
	if(d == -1) exit(0);
	return d;
}
void srt(int l, int r) {
	// assert(l <= r);
	if(r-l <= 1) return;
    if(l > 0) {
        int d = query(a[l], a[l+1], a[0]);
		if(d == a[l+1]) swap(a[l], a[l+1]);
		assert(d != a[0]);
    } else if(r < n) {
		int d = query(a[l], a[l+1], a[n-1]);
		assert(d != a[n-1]);
		if(d == a[l]) swap(a[l], a[l+1]);
	}
	int w = l, e = l+1;
	forsn(p, l+2, r) {
		int d = query(a[w], a[e], a[p]);
		if(d == a[w]) {
			int temp = a[p];
			for(int it = p; it > w;it--) a[it] = a[it-1];
			a[w] = temp;
			w++;
			e++;
		} else if(d == a[p]) {
			int temp = a[p];
			for(int it = p;it > e;it--) a[it] = a[it-1];
			a[e] = temp;
			e++;
		}
		// assert(w<e and e<r and w>=l);
	}
	srt(l, w);
	srt(w+1, e);
	srt(e, r);
}
void go() {
    a.assign(n, 1);
    forn(i,n) a[i] = i+1;
	srt(0, n);
	forn(i, n) cout << a[i] << " ";
	cout << endl;
	int d;cin >> d;
	if(d == -1) exit(0);
}


int main() {
    IO;
    cin >> t >> n >> q;
    while(t--) go();
}