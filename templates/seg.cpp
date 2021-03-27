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

void build() {
	for(int i= n-1;i > 0;i--) t[i] = max(t[i<<1], t[i<<1|1]);
}
ll query(int l, int r) {
	if(l >= r) return -1;
	l += n;
	r += n;
	ll res = -1e9-1;
	while(l < r) {
		if(l&1) res= max(res, t[l++]);
		if(r&1) res= max(res, t[--r]);
		l/=2;r/=2;
	}
	return res;
}
void modify(int l, ll val) {
	l += n;
	t[l] = val;l/=2;
	while(l > 0) {
		t[l] =max(t[l<<1], t[l<<1|1]);
		l/= 2;
	}
}

const int N = 300005;
int n;
int h;
ll t[2*N];
ll d[N]={0};
int cap[2*N];

void CAP() {
	for(int i = n;i < 2*n;i ++) {
		cap[i] = 1;
	}
	for(int i = n-1;i > 0;i--) {
		cap[i] = cap[i<<1] + cap[i<<1|1];
	}
}

// assignment modifications, sum queries
void calc(int p) {
	if(d[p] == 0) t[p] = t[p<<1] + t[p<<1|1];
	else t[p] = d[p] * cap[p];
}
void build(int l, int r) {
	l += n;r += n-1;
	while(l > 1) {
		l >>= 1;r >>= 1;
		for(int i = r;i >= l;i --) {
			calc(i);
		}
	}
}

void apply(int p, int val) {
	t[p] = val * cap[p];
	if(p < n) d[p] = val;
}
void push(int l, int r) {
	int s = h;
	l += n;
	r += n-1;
	while(s > 0) {
		for(int i = l >> s;i <= r >> s;i ++) {
			if(d[i] > 0) {
				apply(i<<1, d[i]);
				apply(i<<1|1, d[i]);
				d[i] = 0;
			}
		}
		s--;
	}
}
void modify(int l, int r, int val) {
	if(val == 0) return;
	push(l, l+1);
	push(r-1, r);
	int l0 = l;
	int r0 = r;
	l += n;
	r += n-1;
	while(l < r) {
		if(l&1) apply(l++, val);
		if(r&1) apply(--r, val);
		l /= 2;
		r /= 2;
	}
	build(l0, l0+1);
	build(r0-1, r0);
}
ll query(int l, int r) {
	push(l,l+1);
	push(r-1,r);
	ll res = 0;
	l += n;
	r += n-1;
	while(l < r) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
		l /= 2;
		r /= 2;
	}
	return res;
}