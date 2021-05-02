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

const int N = 201010;
int n, l, r;
vector<int> cl;
void go() {
	cin >> n >> l >> r;
	cl.assign(n,0);
	forn(it, l) {
		int c;cin >> c;c--;
		cl[c] --;
	}
	forn(it, r) {
		int c;cin >> c;c--;
		cl[c] ++;
	}
	int ans = 0;
	vector<int> L, R;
	int q=0,w=0;
	forn(i,n) {
		if(cl[i] < 0) {
			L.pb(abs(cl[i]));
			q += cl[i];
		}
		else if(cl[i] > 0) {
			w += cl[i];
			R.pb(cl[i]);
		}
	}
	q = -q;
	if(q==w) {
		cout << ans+q << ln;
		return;
	}
	if(q > w) {
		swap(L,R);
		swap(q,w);
	}
	if(q==0 and w==0) {
		cout << 0 << ln;
		return;
	}
	forn(i,R.size()) {
		if(q == 0) break;
		if(R[i]&1) {
			R[i]--;
			ans++;
			q--;
		}
	}
	sort(all(R));

	// vector<int> o,e;
	// for(auto u: R) {
	// 	if(u&1) {
	// 		o.pb(u);
	// 	}else e.pb(u);
	// }
	// sort(all(o));
	// sort(all(e));
	// R.clear();
	// for(auto u: o) R.pb(u);
	// for(auto u: e) R.pb(u);
	
	// cout << q << " " << w << endl;
	// for(auto u: L) cout << u << " ";
	// cout << endl;
	// for(auto u: R) cout << u << " ";
	// cout << endl;

	int sum = 0;
	int i = 0;
	while(sum + R[i] <= q) {
		sum += R[i];
		i++;
		if(i == R.size()) break;
	}
	assert(i < R.size());
	ans += sum;
	q -= sum;
	ans += q;
	R[i] -= q;
	while(i < R.size()) {
		ans += (R[i]+1) / 2;
		i++;
	}
	cout << ans << ln;
	
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
		go();
	}
	// fflush(stdout);
}