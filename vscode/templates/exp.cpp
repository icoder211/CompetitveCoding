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

ll NCR(ll n, ll r, ll md) {
	if(n < r or n <= 0 or r < 0) return 0;
	if(r == 0) return 1;
	ll res = 1;
	r = min(r, n-r);
	forsn(i, 1, r+1) {
		res = (res * (n - i + 1))%md;
		res = (res * exp(i, md-2, md)) % md;
	}
	return res;
}