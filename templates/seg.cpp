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

int n;
ll t[400011];
void build() {
	for(int i = n-1;i > 0;i--) t[i] = min(t[i<<1], t[i<<1|1]);
}
ll query_min(int l, int r) {
	// [l, r)
	ll res = 1e9 + 1;
	l += n;r += n;
	while(l < r) {
		if(l&1) res =min(res, t[l++]);
		if(r&1) res =min(res, t[--r]);
		l /= 2;r /= 2;
	}
	return res;
}