#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define NoS ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(ll i = 0;i < n;i++)
#define forsn(i, s, n) for(ll i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
 
typedef long double ld;
typedef long long ll;
 
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};
 
const ll N = 101010; 
ll mod = 1e9+7;
 
 
ll n, k;
ll a[N], t[2*N], dp[12][N] ={0};
int ord[N];
pair<ll,ll> b[N];
 
void add(int pos, ll val) {
	pos += n;
	while(pos > 0) {t[pos] += val; t[pos] %= mod; pos/=2;}
}
 
ll que(int l, int r) {
	l += n; r += n; ll res = 0;
	for(;l < r;l/=2, r/=2) {
		if(l&1) res += t[l++];
		if(r&1) res += t[--r];
		res %= mod;
	}
	return res;
}

int main() {
    NoS;
	freopen("in.txt","r",stdin);//freopen("output.txt","w",stdout);
	cin >> n >> k;
	forn(i,n) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b,b+n);
	int ind = 0;
	forn(i,n) {
		if(i>0 && b[i].first > b[i-1].first) ind++;
		ord[b[i].second] = ind;
	}
	forn(i,n) dp[0][i] = 1;
	forsn(le,1,k) {
		forn(i,2*n) t[i] = 0;
		for(int j = n-1;j >= 0;j--) {
			add(ord[j], dp[le-1][j]);
			dp[le][j] = que(ord[j]+1, n);
			dp[le][j] %= mod;
		}
	}
	ll ans = 0;
	forn(i,n) {ans += dp[k-1][i]; ans %= mod;}
	cout << ans << ln;
}