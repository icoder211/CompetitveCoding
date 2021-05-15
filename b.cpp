/**
 * Author: icoder211
 */
 
#include<bits/stdc++.h>
using namespace std;
#define ln "\n"
#define pb push_back
#define Nos ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define forn(i, n) for(int i = 0;i < n;i++)
#define forsn(i, s, n) for(int i  = s;i < n;i++)
#define all(v) v.begin(), v.end()
#define mp(i,j) {i,j}
 
typedef long double ld;
typedef long long ll;
 
int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, -1, 0, 1};



ll exp(ll n, ll m, ll md) {
	ll res = 1;
	n %= md;
	while(m > 0) {
		if(m&1) res = (res * 1ll * n) % md;
		n = (n*1ll*n) % md;
		if(n<0) {
			// cout << n << " " << m << " " << md << endl;
			assert(n>=0);
		}
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

const int N = 20202;
int n;
int a[N];
int t[2*N];
void sub(int l) {
	int r = 2*n;
	for(r = 2*n, l += n; l < r;l/=2,r/=2) {
		if(l&1) t[l++]--;
		if(r&1) t[--r]--;		
	}
}
int que(int l) {
	int res = 0;
	for(l += n;l > 0;l /= 2) res += t[l];
	return res;
}
int ind(int i) {
	int l = 0;
	int r = n;
	while(l < r) {
		int m = (l+r)/2;
		if(que(m) >= i) r = m;
		else l = m+1;
	}
	return r;
}
int sz = 0;
int out(int t,int i,int j,int x) {
	cout << "? " << t << " " << i << " " << j << " " << x << endl;
	int d;cin >> d;if(d==-1) exit(0);
	return d;
}
void go() {
	cin >> n;
	sz = n;
	forn(i,n) t[i+n] = i;
	forn(i,n) a[i] = -1;
	
}

vector<vector<int>> ad, ans;
int leaf[N], par[N], lev[N];
int root = -1;
int dfs(int s, int p, int level) {
	int lf = -1;
	for(int i = ad[s].size()-1 ;i >= 0; i--) {
		int u = ad[s][i];
		if(u == p) continue;
		lf = dfs(u, s, level+1);
	}
	if(lf == -1) lf = s;
	lev[s] = level;
	par[s] = p;
	leaf[s] = lf;
	return leaf[s];
}
void solve(int s, int p) {
	// int lf = -1;
	for(int i = ad[s].size()-1;i >= 0;i--) {
		int u = ad[s][i];
		if(u == p) continue;
		solve(u, s);
	}
	// leaf[s] = lf;

	vector<int> vec;
	forn(i, ad[s].size()) {if(ad[s][i] != p) {vec.pb(ad[s][i]);}}

	for(int i = 0;(vec.size() > 1 + (s==root)) and (i < vec.size()-1-(s==root)); i++) {
		// cout << vec[i] << " ";
		if(vec[i] == p) continue;
		ans.pb({s, vec[i], leaf[ vec[i+1] ], vec[i]});
	}
}

void go1() {
	root = -1;
	cin >> n;
	ans.clear();
	ad.assign(n,{});
	forn(i,n-1) {
		int l,r;cin>>l>>r;l--;r--;
		ad[l].pb(r);
		ad[r].pb(l);
	}
	int res=0;
	forn(i,n) {
		if(ad[i].size() > 2) root = i;
		res += max(0, (int)ad[i].size()-2);
	}
	if(root==-1) {
		cout << 0 << ln;
		return;
	}
	dfs(root,root,0);
	// forn(i,n) cout << leaf[i] << " ";cout << ln;
	solve(root, root);
	cout <<ans.size() << ln;
	assert(ans.size() == res);
	for(auto u: ans) {
		for(auto uu: u) cout << uu+1 << " ";
		cout << ln;
	}
}

void go() {
	
}

int main() {
    Nos;
	// seive();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	// freopen("in.txt","r",stdin);//freopen("output.txt","w",stdout);

	int t; t = 1;
    cin >> t;
	int tt = t;


    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go1();
		fflush(stdout);
	}
}