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
vector<ll> pr;
void seive() {
	vector<ll> vis;
	pr.clear();
	vis.assign(1e7+1, 0);
	ll i =0 ;
	for(ll i = 2;i <= 1e7; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		// cout << i << " ";
		for(ll j = i*1ll*i;j <= 1e7;j += i) {
			vis[j] = 1;
		}
	}
}


// ll mod = 1e9+7;
ll mod = 998244353;
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


ll n;
// ll a[200000]
// ll p;
// map<ll, set<ll> > m;
// void go(){
// 	m.clear();
// 	cin >> n >> p;
// 	ll mx = -1;
// 	forn(i,n) {
// 		cin >> a[i];
// 		// mx = max(mx, a[i]);
// 		m[a[i]].insert(i);
// 	}
// 	ll comps = 0
// 	ll ans = 0;
// 	ll iters = 0;
// 	while(!m.empty()) {
// 		if(m.begin()->second.empty()) {
// 			m.erase(m.begin());
// 			continue;
// 		}
// 		ll pos = *(m.begin()->second.begin());		
// 		// cout << pos << ln;
// 		// if(a[pos] > p) break;
// 		m[a[pos]].erase(pos);
// 		if(m[a[pos]].empty()) m.erase(a[pos]);
// 		int i = pos+1;
// 		while(i < n and __gcd(a[i], a[pos]) == a[pos] and m[a[i]].count(i)) {
// 			m[a[i]].erase(i);
// 			if(m[a[i]].empty()) m.erase(a[i]);
// 			ans += min(p, a[pos]);
// 			i++;
// 		}
// 		i = pos-1;
// 		while(i >= 0 and __gcd(a[i], a[pos]) == a[pos] and m[a[i]].count(i)) {
// 			m[a[i]].erase(i);
// 			if(m[a[i]].empty()) m.erase(a[i]);
// 			ans += min(p, a[pos]);
// 			i--;
// 		}
// 		comps ++;
// 	}
// 	ans += (comps-1)* p;
// 	cout << ans << ln;
// 	return;
// 	// forn(i,n) {
// 	// 	if(a[i] >= p) {
// 	// 		break;
// 	// 	}
// 	// 	if(m[a[i]] == 0) continue;
// 	// 	m[a[i]]--;
// 	// 	comps ++;
// 	// 	ll d = 1;
// 	// 	while(d* a[i] <= mx) {
// 	// 		ll dd = d* a[i];
// 	// 		if(m[dd] > 0) {
// 	// 			ans += (m[dd]* a[i]);
// 	// 			m[dd]=0;
// 	// 		}
// 	// 		d++;
// 	// 	}
// 	// }
// 	// for(auto u: m) {
// 	// 	comps += u.second;
// 	// }
// 	// ans += p* (comps-1);
// 	// cout << ans << ln;
// }


int a[100];
pair<int, int> dp[100][200000];

set<int> rem;
bool f(int i, int tar) {
	if(i>=n) return false;
	if(rem.count(i)) return f(i+1,tar);
	if(tar < 0) return false;
	if(dp[i][tar].first >= 0) return dp[i][tar].first;
	if(i == n-1) {
		dp[i][tar].first = (a[i] == tar);
		dp[i][tar].second = dp[i][tar].first;
		return dp[i][tar].first;
	}
	dp[i][tar].first = f(i+1, tar-a[i]);
	if(dp[i][tar].first==0) {
		dp[i][tar].first =  f(i+1, tar);
		dp[i][tar].second = 0;
		
	} else {
		dp[i][tar].second = 1;
	}

	return dp[i][tar].first;
}

void go() {
	rem.clear();
	cin >> n;
	ll s = 0;
	ll p = -1;
	forn(i,n) {
		cin >> a[i];
		if(a[i]&1) p = i;
		s += a[i];
	}
	
	if(s&1) {cout<<0<<ln;return;}
	forn(i, n) {
		dp[i][0].first = 1;
		dp[i][0].second = 0;
		forsn(j,1, s+1) dp[i][j].first = -1;
	}
	// f(0,s/2);
	// forn(i,n) {
	// 	forn(j,s+1) cout<< dp[i][j].first << " ";
	// 	cout<<ln;
	// }
	if(!f(0,s/2)) {cout<<0<<ln;return;}
	if(p>-1) {
		cout<<1<<ln;
		cout<<p+1;
		return;
	}
	vector<int> ans;
	for(int it = 2;it < s/2;it += 2) {
		if(f(0, it) and !f(0, (s-it)/2)) {
			// recover it
			ll ss = 0;
			forn(i, n) {
				dp[i][0].first = 1;
				dp[i][0].second = 0;
				forsn(j,1, s+1) {dp[i][j].first = -1; dp[i][j].second==-1;}
			}
			bool ok = f(0,it);
			assert(ok);
			
			forn(i, n) {
				if(dp[i][it].first == 1 ) {
					assert(dp[i][it].second >= 0);
					if(dp[i][it].second == 0) continue;
					ans.pb(i);
					rem.insert(i);
					ss += a[i];
				}
			}
			assert(ss==it);
			forn(i, n) {
				dp[i][0].first = 1;
				dp[i][0].second = 0;
				forsn(j,1, s+1) {dp[i][j].first = -1; dp[i][j].second==-1;}
			}
			if(!f(0, (s-it)/2)) break;
			rem.clear();
			ans.clear();
		}
	}
	cout<<ans.size()<<ln;
	forn(i,ans.size()) cout<<ans[i]+1 << " ";

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