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

const ll N = 1001;

int n;
int dp[N][N]; // dp[palin][rogue];
void go() {
	cin >> n;
	int r = 0, p = 0;
	string s;cin >> s;
	forn(i,n) {
		if(s[i] == '0') {
			if(s[i] != s[n-i-1]) {
				r ++;
			}else {
				p ++;
			}
		}
	}
	if(p == 1 or p == 2) {
		cout << "ALICE\n";return;
	}
	if(p == 0) {
		if(r & 1) {
			cout << "BOB\n";return;
		}
		cout << "ALICE\n";return;
	}
	if(r == 0) {
		if(p)
	}
	if(p & 1) {
		if(r&1) 
		{
			cout << "BOB\n";return;
		}else cout << "ALICE\n";
		return;
	}
	if(r&1) 
		{
			cout << "ALICE\n";return;
		}else cout << "BOB\n";
		return;
	if(r == 0) {
		if(p == 1) {
			cout << "BOB\n";return;
		}
		if(p&1) {cout << "ALICE\n";return;}
		else {cout << "BOB\n";return;}
	}
	cout << "ALICE\n";
}

int main() {
    Nos;
	// seive();
	// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	// freopen("in.txt","r",stdin);//freopen("output.txt","w",stdout);

	int t; t = 1;
    cin >> t;
	int tt = t;


	forn(i,N) {
		dp[i][0] = ((i&1)>0);
	}
	dp[0][0] = 1;
	dp[1][0] = 0;
	forsn(j, 1, n) {

	}

    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
		// fflush(stdout);
	}
}