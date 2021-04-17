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
vector<int> pr;
void seive() {
	vector<int> vis;
	pr.clear();
	vis.assign(1e7+1, 0);
	int i =0 ;
	for(int i = 2;i * i <= 1e7; i++ ) {
		if(vis[i]) continue;
		pr.pb(i);
		// cout << i << " ";
		for(int j = i*i;j <= 1e7;j += i) {
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
// ll a[200000];
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

// 	ll comps = 0;
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


void go() {
	cin >> n;
	string a[3];
	forn(i,3)cin >>a[i];
	string res[3];
	n*=2;
	forn(j,3) {
		string s = a[j];
		string t = a[(j+1)%3];
		ll ss =0 , tt=0;
		string anss;
		int cur, prev;
		prev=n;
		for(ll i = n-1;i >= 0;i--) {
			ss += s[i]=='1';
			tt += t[i] == '1';
			int mx = 0;
			string ans;

			if(ss == tt) {
				// cout<<i<<ln;
				cur = i;

				if(ss > prev-cur-ss) {
					mx += ss;
					vector<int> q,w;int one=0, onee=0;
					forsn(it, cur, prev) {
						if(s[it]=='0') one++;
						else {q.pb(one);one=0;}
						if(t[it]=='0') onee++;
						else {w.pb(onee);onee=0;}
						
					}
					assert(q.size()==w.size());
					assert(q.size()==ss);
					forn(it, ss) {
						forn(itt, max(w[it], q[it])) ans.pb('0');
						ans.pb('1');
					}
					forn(itt,max(one,onee)) ans.pb('0');
				}
				else {
					mx += prev-cur-ss;

					vector<int> q,w;int one=0, onee=0;
					forsn(it, cur, prev) {
						if(s[it]=='1') one++;
						else {q.pb(one);one=0;}
						if(t[it]=='1') onee++;
						else {w.pb(onee);onee=0;}
						
					}
					assert(q.size()==w.size());
					assert(q.size()==prev-cur-ss);
					forn(it, prev-cur-ss) {
						forn(itt, max(w[it], q[it])) ans.pb('1');
						ans.pb('0');
					}
					forn(itt,max(one,onee)) ans.pb('1');
				}
				prev = cur;
				ss=0;
				tt=0;
			}else if(i == 0) {
				cur=0;
				if(min(ss,tt)>min(prev-ss, prev-tt)) {
					//go 1
					mx += min(ss,tt);
					vector<int> q,w;int one=0, onee=0;
					forsn(it, 0, prev) {
						if(s[it]=='0') one++;
						else {q.pb(one);one=0;}
						if(t[it]=='0') onee++;
						else {w.pb(onee);onee=0;}
					}
					// s.resize(min(ss,tt));
					// w.resize(min(ss,tt));

					forn(it, min(ss,tt)) {
						forn(itt, max(w[it], q[it])) ans.pb('0');
						ans.pb('1');
					}
					forsn(it, min(ss,tt), ss) {
						forn(itt, q[it]) ans.pb('0');
						ans.pb('1');
					}
					forsn(it, min(ss,tt), tt) {
						forn(itt, w[it]) ans.pb('0');
						ans.pb('1');
					}
					forn(itt, max(one,onee)) ans.pb('0');
				}else {
					//go 0
					mx += min(prev-ss, prev-tt);
					vector<int> q,w;int one=0, onee=0;
					forsn(it, 0, prev) {
						if(s[it]=='1') one++;
						else {q.pb(one);one=0;}
						if(t[it]=='1') onee++;
						else {w.pb(onee);onee=0;}
					}
					// s.resizemin(prev-ss, prev-tt));
					// w.resize(min(prev-ss, prev-tt));

					forn(it,min(prev-ss, prev-tt)) {
						forn(itt, max(w[it], q[it])) ans.pb('1');
						ans.pb('0');
					}
					forsn(it, min(prev-ss, prev-tt), prev-ss) {
						forn(itt, q[it]) ans.pb('1');
						ans.pb('0');
					}
					forsn(it, min(prev-ss, prev-tt), prev-tt) {
						forn(itt, w[it]) ans.pb('1');
						ans.pb('0');
					}
					forn(itt, max(one,onee)) ans.pb('1');

				}
			}
			// if(!ans.empty()) cout<<ans<<endl;
			reverse(all(ans));
			forn(i,ans.size()) anss.pb(ans[i]);
		}
		reverse(all(anss));
		// cout<<anss<<endl;
		res[j]  = anss;
		if(anss.size() <= (3*n)/2) {
			cout<<anss << ln;
			return;
		}
	}
	assert(2>3);
	

}

int main() {
    IO;
	// fac();
	// cout.flush();
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t; t = 1;
    cin >> t;
	int tt = t;
    while(t--) {
		// cout << "Case #"<<tt-t<<": ";
		go();
	}
}