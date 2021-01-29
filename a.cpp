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

int n, h;
int a[200000];
int t[400000];
vector<int> d;

void build(int i) {
	i /= 2;
	for(;i > 0;i /= 2) t[i] = t[i<<1] + t[i<<1|1];
}
void apply(int p, int tk) {
	if(tk == -1) t[p] = 0;
	else t[p] = 1;
	if(p < n) d[p] = tk;
}
void push(int p) {
	for(int s = h;s > 0;s--) {
		int i = p >> s;
		if(d[i] != 0) {
			apply(i<<1, d[i]);
			apply(i<<1|1, d[i]);
			d[i] = 0;
		}
	}
}
void mod(int l, int r, int tk) {
	l += n;int l0 = l;
	r += n;int r0 = r;
	while(l < r) {
		if(l&1) apply(l++, tk);
		if(r&1) apply(--r, tk);
		l /= 2;
		r /= 2;
	}
	build(l0);
	build(r0-1);
}
int query(int l, int r) {
	int res = 0;
	l += n;
	r += n;
	push(l);
	push(r-1);
	while(l < r) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
		l /= 2;r /= 2;
	}
	return res;
}
int q;
void go() {
	cin >> n >> q;
	h = 32 - __builtin_clz(n);
	d.assign(2*n, 0);
	string s, f;
	cin >> s >> f;
	forn(i, n) {
		a[i] = ((int)f[i] - 48);
		t[i+n] = a[i];
	}
	for(int i = n-1;i > 0;i--) {
		t[i] = t[i<<1] + t[i<<1|1];
	}
	vector<pair<int, int>> qu;
	forn(i,q) {
		int w,e;cin >> w >> e;
		qu.pb({w,e});
	}
	reverse(all(qu));
	forn(i, q) {
		int l = qu[i].first;l--;
		int r = qu[i].second;
		int d = (r-l)/2;
		if((r-l) % 2 == 0) d--;
		cout << query(l, r) << " ";
		if(query(l, r) > d) {
			mod(l, r, 1);
		} else {
			mod(l, r, -1);
			cout << "L\n";
		}
	}
	forsn(i,1,2*n) push(i);
	forn(i,n) {
		if(t[n+i] != s[i]-48) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	return;
}

int main() {
    IO;
    fflush(stdout);
	int t;cin >> t;
	while(t--) 
	go();
	
	
}