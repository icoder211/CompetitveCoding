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
 
const ll MAXN = 101010;
vector<ll> pr;
vector<int> g[MAXN];
void seive() {
	vector<ll> vis;
	pr.clear();
	vis.assign(1e5+1, 0);
	ll i = 0;
	for(ll i = 2;i <= 1e5; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		// cout << i << " ";
		for(ll j = i;j <= 1e5;j += i) {
			vis[j] = 1;
			g[j].pb(i);
		}
	}
}
 
 
ll mod = 8e18+7;
// ll mod = 998244353;
ll f(int d) {
	int ans = 0;
	forn(i,32) {
		if(d & (1 << i)) {
			ans ++;
		}
	}
	return 32 - ans;
}
ll fact[300001],infac[300001];
ll fe(ll a,ll b){
    ll temp=a;
    ll ans=1ll;
    while(b){
        if(b&1){
            ans*=(ll)temp;
            ans%=mod;
        }
        b/=2ll;
        temp=temp*(ll)temp;
        temp%=mod;
    }
    ans += mod;
    ans %= mod;
    return ans%mod;
}
ll mi(ll a){
    return(fe(a,mod-2));
}
 
void fac(){
    fact[0]=1;
    infac[0]=1;
    forsn(i,1,200009){
        fact[i]=fact[i-1]*i;
        fact[i]%=mod;
        infac[i]=mi(fact[i]);
        infac[i]%=mod;
    }
}
ll ncr(ll a,ll b){
    if(a<b || a<=0)return 0;
    ll ans=fact[a];
    ans*=infac[b];
    ans%=mod;
    ans*=infac[a-b];
    ans%=mod;
    return ans;
}
 
 
ll n, q, m;
ll k;
ll a[MAXN];
int ord[MAXN];
// int rev[MAXN];
pair<ll,ll> b[MAXN];
ll dp[12][MAXN]={0};
ll seg[4*MAXN];
const ll MAX=100000;

void build(ll v, ll st,ll end, ll a[]){
    //out1(a[v]);
    if (end==st) seg[v]=a[st];
    else{
        ll mid=(end+st)/2;
        build(2*v,st,mid,a);
        build(2*v+1,mid+1,end,a);
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}
void update(ll v,ll st,ll end,ll index,ll var,ll a[]){
    if (end==st) seg[v]+=var;
    else{
        ll mid=(end+st)/2;
        if (st<=index && index<=mid) update(2*v,st,mid,index,var,a);
        else update(2*v+1,mid+1,end,index,var,a);
        seg[v]=min(seg[2*v],seg[2*v+1]);
    }
}
ll query(ll v,ll st,ll end,ll l,ll r,ll a[]){
    if (st>r || end<l) return MAX;
    else if (l<=st && r>=end) return seg[v];
    else{
        ll mid=(st+end)/2;
        ll p1=query(2*v,st,mid,l,r,a);
        ll p2=query(2*v+1,mid+1,end,l,r,a);
        return min(p1,p2);
    }

}
void go() {
	cin >> n >> k;k++;
	forsn(i,1,n+1) {
		cin >> a[i];
		b[i].first = a[i];
		b[i].second = i;
	}
	sort(b,b+n);
	forn(i,n) {
		ord[b[i].second] = i;
		// rev[i] = b[i].second;
	}
	forn(i,n) dp[0][i] = 1;
	forsn(le,1,k) {
		memset(seg, 0, sizeof(seg));
		for(int j = n-1;j >= 0;j--) {
            update(1,1,n,ord[j], dp[le-1][j], a);
			// add(ord[j], dp[le-1][j]);
            dp[le][j] = query(1,1,n,ord[j]+1,n,a);
			// dp[le][j] = que(ord[j]+1, n);
			dp[le][j] %= mod;
		}
	}
	ll ans = 0;
	forn(i,n) {ans += dp[k-1][i]; ans %= mod;}
	cout << ans << ln;
}

int main() {
    IO;
	// fac();
	// seive();
	// cout.flush();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    // cin >> t;
	int tt = t;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
	}
}