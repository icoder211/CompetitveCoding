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

ll a[100005];
void go() {
	cin >> n;
	vector<ll> bb;
	forn(i,n) {
		cin >> a[i]; bb.pb(a[i]);
	}
	ll i = 0;
	// vector<ll> ans;
	// ans.assign(n, 1);
	if(n == 2) {
		cout << 2 << ln;
		return;
	}
	ll ress = 0;
	forn(i,n-1) {
		ll j = i+1;
		ll p  = a[j] - a[i];
		while(j < n and a[j] - a[j-1] == p) j++;
		if(j == n) {
			ress = max(ress, n-i + (i>0));
		}
		ress = max(ress, j-i + (i>0));
		ress = max(ress, j-i + 1);
		ll temp = a[j];
		ll j0 = j;
		a[j] = a[j-1] + p;
		while(j < n and a[j] - a[j-1] == p) j++;
		ress = max(ress, j-i);
		a[j0] = temp;

		temp = a[i+1];
		a[i+1] = a[i+2]-a[i]

	}
	forn(i,n) assert(a[i] == bb[i]);
	assert(ress>=3);
	cout << ress << ln;
	return;
	
	vector<ll> b;
	b.pb(0);
	while(b.back() < n-1) {
		int i = b.back();
		int j = i;
		while(j < n-1 and (a[j+1] - a[j]) == (a[i+1] - a[i])) {
			j++;
		}
		b.pb(j);
	}
	// forn(i,b.size()) cout<<b[i] << " ";
	// cout<<ln;
	if(b.size()==2 or n==2) {
		cout << n << ln;
		return;
	}
	ll ans = 2;
	forsn(i,1, b.size()) {
		if(b[i] - b[i-1] == 1) {
			if(i < b.size()-1 and i>1) ans = max(ans, b[i+1]-b[i-2]+1ll);
			else if(i > 1) ans = max(ans, b[i] - b[i-2] + 1);
			else if(i < b.size()-1) ans = max(ans, b[i+1] - b[i] + 1);
		}
		if(i > 1 and b[i] - b[i-1] == 1 and b[i-1] - b[i-2] == 1 /*and a[b[i-1]] - a[b[i]] == a[b[i-1]] - a[b[i-2]]*/ ) {
			ans = max(ans, 3ll);

			if(i < b.size()-1 and i > 2 and (a[b[i]+1] - a[b[i]]) == (a[b[i-2]] - a[b[i-2]-1]) and 2*(a[b[i]+1] - a[b[i]]) == a[b[i]]-a[b[i-2]]) 
				ans = max(ans, b[i+1]-b[i-3]+1ll);
			else if(i > 2 and 2*(a[b[i-2]] - a[b[i-2]-1]) == a[b[i]]-a[b[i-2]]  )
			 	ans = max(ans, b[i] - b[i-3] + 1);
			else if(i < b.size()-1 and 2*(a[b[i]+1] - a[b[i]]) == a[b[i]]-a[b[i-2]] ) 
				ans = max(ans, b[i+1] - b[i-2] + 1);
			
		}
		ans = max(ans, b[i]-b[i-1]+2);
	}
	assert(ans>=3);
	cout<<ans<<ln;
}


void go1() {
	cin >> n;
	// ll ans = -1;
	// forsn(i,1,pr.size()) {
	// 	if(n > 1e9) break;
	// 	ll d =  pr[i]*pr[i-1];
	// 	if(d > n) break;
	// 	ans = d;
	// }

	// if(n <= 1e9) {
	// 	cout << ans << ln;
	// 	return;
	// }
	vector<ll> pr1;
	ll d = floor(sqrt(n));
	vector<ll> vis;
	ll N = 5e6;

	vis.assign(N + 1, 0);
	forn(i, N) {
		if(d-i <= 1) break;
		if(vis[i]) continue;
		ll p = -1;
		// cout<<d-i<<endl;
		forn(j, pr.size()) {
			if((d-i) % pr[j] == 0) {
				p = pr[j];
				break;
			}
		}
		// cout<<p<<endl;
		if(p == -1 or p == d-i) {
			pr1.pb(d-i);
			if(pr1.size()>=2) break;
		}
		for(ll j = i; j < N and p > 0;j += p) {
			vis[j] = 1;
		}
	}
	vis.assign(N+1, 0);
	forsn(i,1, N) {
		if((d+i) * pr1[0] > n) break;
		if(vis[i]) continue;
		ll p = -1;
		forn(j, pr.size()) {
			if((d+i) % pr[j] == 0) {
				p = pr[j];
				break;
			}
		}
		if(p == -1 or p == d+i) {
			pr1.pb(d+i);
			if(pr1.size()>=4) break;
		}
		for(ll j = i; j < N and p > 0;j += p) {
			vis[j] = 1;
		}
	}

	sort(all(pr1));
	reverse(all(pr1));
	// forn(i,pr1.size()) {
	// 	cout<<pr1[i] << " ";
	// }
	// cout<<ln;
	// assert(pr.size()==4);
	forsn(i,1,pr1.size()) {
		if(pr1[i]*pr1[i-1] <= n) {
			cout << pr1[i]*pr1[i-1] << ln;
			return;
		}
	}
}

int main() {
    IO;
	// fac();
	// seive();
	// cout.flush();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    cin >> t;
	int tt = t;
    while(t--) {
		cout << "Case #"<<tt-t<<": ";
		go();
	}
}