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

int t,n,q;
vector<set<int>> ad;
vector<int> vis;
vector<int> ans;
set<int> st;
void dfs(ll s) {
	if(vis[s]) return;
	vis[s] = 1;
	for (auto u: ad[s]) {
		if(vis[u]) continue;
		dfs(u); 
	}
	ans.pb(s);
}

// void go(int n_, int q_) {
// 	// cout << "haha\n";
// 	n = n_;
// 	q = q_;
	
// 	if(n>10) return;
// 	forn(i,n) {
// 		st.insert(i);
// 	}
// 	ans.clear();
// 	st.clear();
// 	vis.assign(n, 0);
// 	ad.assign(n,{});
// 	forn(i,n) forsn(j,i+1,n) forsn(k,j+1,n) {
// 		// cout << ln;

// 		// forn(p,n) {
// 		// 	cout << p +1<< " ";
// 		// 	for(auto u: ad[p]) cout << u +1<< " ";
// 		// 	cout << ln;
// 		// }
// 		cout << i+1 << " " << j+1 << " " << k+1 << endl;
// 		ll d;cin >> d;if(d==-1)exit(0);d--;
		
// 		ll a[3] = {i,j,k};
// 		forn(p,3) {
// 			if(d != a[p]) continue;
// 			assert(!ad[a[p]].count(a[(p+1)%3]) or ad[a[(p-1)%3]].count(a[p]) or ad[a[(p-1)%3]].count(a[(p+1)%3]) ||
// 			       !ad[a[p]].count(a[(p-1)%3]) or ad[a[(p+1)%3]].count(a[p]) or ad[a[(p+1)%3]].count(a[(p-1)%3]) );
// 			// cout << a[p]+1 << " " << a[(p+1)%3]+1 << endl;
// 			if( ad[a[p]].count(a[(p+1)%3]) or ad[a[(p-1)%3]].count(a[p]) or ad[a[(p-1)%3]].count(a[(p+1)%3]) ) {
// 				ad[a[p]].insert(a[(p+1)%3]); //assert(!ad[a[(p+1)%3]].count(a[p]));
// 				ad[a[(p-1)%3]].insert(a[p]); //assert(!ad[a[p]].count(a[(p-1)%3]));
// 				ad[a[(p-1)%3]].insert(a[(p+1)%3]); //assert(!ad[a[(p+1)%3]].count(a[(p-1)%3]));

// 				st.erase(a[p]);
// 				st.erase(a[(p+1)%3]);
// 			} else {
// 				ad[a[p]].insert(a[(p-1)%3]); //assert(!ad[a[(p-1)%3]].count(a[p]));
// 				ad[a[(p+1)%3]].insert(a[p]);// assert(!ad[a[p]].count(a[(p+1)%3]));
// 				ad[a[(p+1)%3]].insert(a[(p-1)%3]); //assert(!ad[a[(p-1)%3]].count(a[(p+1)%3]));

// 				st.erase(a[p]);
// 				st.erase(a[(p-1)%3]);
// 			}
// 		}
// 	}
// 	// cout << n;

// 	forn(i,n) {
// 		if(!vis[i]) dfs(i);
// 	}
// 	assert(ans.size()==n);
// 	forn(i,ans.size()) cout << ans[i]+1 << " ";
// 	cout << endl;
// 	int d;cin>>d;
// 	if(d==-1) exit(0);
// }

vector<int> test;
vector<int> a;
int qcount = 0;
int query(int a1, int b, int c) {
	qcount ++;

	int res = a1+b+c;
	int i = 0;
	set<int> st;
	st.insert(a1);st.insert(b);st.insert(c);
	while(i < test.size()) {
		if(st.count(test[i])) {
			res -= test[i];
			break;
		}
		i++;
	}
	i = test.size()-1;
	while(i>=0) {
		if(st.count(test[i])) {
			res -= test[i];
			break;
		}
		i--;
	}
	return res;


	cout << a1 << " " << b << " " << c << endl;
	int d; cin >> d; if(d==-1) exit(0);
	return d;
}
int pos;
void srt(int l, int r) {
	assert(l <= r);
	if(r-l <= 1) return;
    if(l > 0) {
        int d = query(a[l], a[l+1], a[0]);
		if(d == a[l+1]) swap(a[l], a[l+1]);
		assert(d != a[0]);
    } else if(r < n) {
		int d = query(a[l], a[l+1], a[n-1]);
		assert(d != a[n-1]);
		if(d == a[l]) swap(a[l], a[l+1]);
	}
	int w = l, e = l+1;
	forsn(p, l+2, r) {
		int d = query(a[w], a[e], a[p]);
		if(d == a[w]) {
			int temp = a[p];
			for(int it = p; it > w;it--) a[it] = a[it-1];
			a[w] = temp;
			w++;
			e++;
		} else if(d == a[p]) {
			int temp = a[p];
			for(int it = p;it > e;it--) a[it] = a[it-1];
			a[e] = temp;
			e++;
		}
		assert(w<e and e<r and w>=l);
	}
	srt(l, w);
	srt(w+1, e);
	srt(e, r);


}
void go() {
    a.assign(n, 1);
    forn(i,n) a[i] = i+1;
	srt(0, n);
	forn(i, n) cout << a[i] << " ";
	cout << endl;
}

// void qsort(int l, int r) {
// 	assert(l >= 0 and r <= n);
// 	if(l >= r-1) return;
// 	set<int> s1,s2,s3;
// 	// if(l > 0) {
// 	// 	// cout << "swap left\n";
// 	// 	// cout << l << " " << r << ln;
// 	// 	// cout << a[l] << " " << a[l+1] << " " << a[0] << ln;
// 	// 	int d = query(a[0],a[l],a[l+1]);
// 	// 	assert(d != a[0]);
// 	// 	if(d == a[l+1]) swap(a[l],a[l+1]);
// 	// } else if (r < n) {
// 	// 	// cout << "swap right\n";
// 	// 	// cout << l << " " << r << ln;
// 	// 	// cout << a[l] << " " << a[l+1] << " " << a[n-1] << ln;
// 	// 	int d = query(a[n-1],a[l],a[l+1]);
// 	// 	assert(d != a[n-1]);
// 	// 	if(d == a[l]) swap(a[l],a[l+1]);
// 	// }
// 	int d = query(a[l], a[l+1], a[pos]);
// 	assert(d != a[pos]);
// 	assert(a[pos] == 1);
// 	if(l < pos) {
// 		if(d == a[l]) swap(a[l], a[l+1]);
// 	}else {
// 		if(d == a[l+1]) swap(a[l], a[l+1]);
// 	}
// 	forsn(i,l+2,r) {
// 		int d = query(a[i],a[l],a[l+1]);
// 		if(d == a[i])s2.insert(a[i]);
// 		if(d == a[l]) s1.insert(a[i]);
// 		if(d == a[l+1]) s3.insert(a[i]);
// 	}
// 	vector<int> temp;
// 	for(auto u: s1) temp.pb(u);
// 	temp.pb(a[l]);
// 	for(auto u: s2) temp.pb(u);
// 	temp.pb(a[l+1]);
// 	for(auto u: s3) temp.pb(u);

// 	// cout << a[l] << " " << a[l+1] << ln;
// 	// cout << "s1"<< " ";
// 	// for(auto u: s1) cout << u << " ";
// 	// cout<<ln;
// 	// cout << "s2"<< " ";
// 	// for(auto u: s2) cout << u << " ";
// 	// cout<<ln;
// 	// cout << "s3"<< " ";
// 	// for(auto u: s3) cout << u << " ";
// 	// cout<<ln;
// 	assert(temp.size() == r-l);
// 	forsn(p, l, r) a[p] = temp[p-l];
// 	assert(s3.size()+s2.size()+s1.size()+l+1+1 == r);

// 	if(s1.size()>0) qsort(l,s1.size()+l);
// 	if(s2.size()>0) qsort(s1.size()+l+1,s2.size()+s1.size()+l+1);
// 	if(s3.size()>0) qsort(s2.size()+s1.size()+l+1+1,s3.size()+s2.size()+s1.size()+l+1+1);
// }
// void go1(int n_, int q_) {
// 	n=n_;q=q_;
	
// 	a.clear();
// 	forn(i,n) a.pb(i+1);
// 	set<int> st;
// 	forn(i,n-2) {
// 		int d = query(1,2,i+3);
// 		if(d == 1) st.insert(i+3);
// 	}
// 	vector<int> temp;
// 	forsn(i,1,n) {
// 		if(st.count(i+1)){}
// 		else temp.pb(i+1);
// 	}
// 	pos = temp.size();
// 	temp.pb(1);
// 	forsn(i,1,n) {
// 		if(st.count(i+1)) temp.pb(i+1);
// 	}
// 	forn(i,n) a[i] = temp[i];

// 	qsort(0, pos);
// 	qsort(pos+1, n);

// 	// qsort(0,n);

// 	forn(i,n) cout << test[i] << " ";
// 	cout << ln;
// 	forn(i,n) cout << a[i] << " ";
// 	cout << ln;
// 	bool ok = true;
// 	forn(i,n) {
// 		ok &= (test[i] == a[i]);
// 	}
// 	bool okk = true;
// 	forn(i,n) {
// 		okk &= (test[i] == a[n-1-i]);
// 	}
// 	cout << (okk || ok )<< ln;
// 	assert(okk || ok);
// }

// void go2() {
// 	int x,y,n;
// 	string s;
// 	cin >> x >> y >> s;
// 	n = s.size();
// 	int i = 0;
// 	while(i < n and s[i] == '?') i++;
// 	if(i == n) {
// 		int ans = 0;
// 		if(x>0 and y>0) {
// 			ans = 0;
// 		} else {
// 			if(x+y <= 0) {
// 				ans += ((x+y)* (n/2 - 1)) + min(min(0,y),x);
// 			}else {
// 				ans = 0;
// 			}
// 		}
// 		cout << ans << ln;
// 		return;
// 	}
// 	int ans = 0;
// 	if(i>0) {
// 		if(x>0 and y>0) {
// 			ans = 0;
// 		} else {
// 			if(s[i] == 'J') {
// 				int p = (i+1)/2 * x + i/2 * y;
// 				int q = (i)/2 * x + i/2 * y;
// 				int add = min(0, p);
// 				add = min(add, q);
// 				add = min(add, x);
// 				ans += add;
// 			}else {
// 				swap(x,y);
// 				int p = (i+1)/2 * x + i/2 * y;
// 				int q = (i)/2 * x + i/2 * y;
// 				int add = min(0, p);
// 				add = min(add, q);
// 				add = min(add, x);
// 				ans += add;
// 				swap(x,y);
// 			}
// 		}
// 	}
// 	// cout << ans << " " ;
// 	while(i < n) {
// 		int j = i+1;
// 		while(j < n and s[j] == '?') j++;
		
// 		if(j == n) {
// 			// <almostcopypastedpart>
// 			if(x>0 and y>0) {
// 				ans += 0;
// 			} else {
// 				int temp = i;
// 				i = n-1-i;
// 				if(s[temp] == 'C') {
// 					int p = (i+1)/2 * x + i/2 * y;
// 					int q = (i)/2 * x + i/2 * y;
// 					int add = min(0, p);
// 					add = min(add, q);
// 					add = min(add, x);
// 					ans += add;
// 				}else {
// 					swap(x,y);
// 					int p = (i+1)/2 * x + i/2 * y;
// 					int q = (i)/2 * x + i/2 * y;
// 					int add = min(0, p);
// 					add = min(add, q);
// 					add = min(add, x);
// 					ans += add;
// 					swap(x,y);
// 				}
// 			}
// 			break;
// 			// </almostcopypastedpart>
// 		}
// 		if(j == i+1) {
// 			if(s[i] != s[j]) {
// 				if(s[i] == 'C') ans += x;
// 				else ans += y;
// 			}
// 			i = j;
// 			continue;
// 		}
// 		if(s[j] == s[i]) {
// 			if(s[i] == 'J'){
// 				swap(x,y);
// 			}
// 			//code
// 			int add = 0;
// 			int m = j-i-1;
// 			add = min(add, (x+y)*(m+1)/2) ;
// 			ans += add;
// 			if(s[i] == 'J'){
// 				swap(x,y);
// 			}
// 		}else {
// 			if(s[i] == 'J'){
// 				swap(x,y);
// 			}
// 			//code
// 			int add = x;
// 			int m = (j-i-1);
// 			add = min(add, (x+y)* (m+1)/2 - y);
// 			ans += add;
// 			if(s[i] == 'J') {
// 				swap(x,y);
// 			}
// 		}
// 		// cout << i << " " << j << " " << ans << ln;
// 		i = j;

// 	}
// 	cout << ans << ln;
// }


int main() {
    IO;
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int t,n,q; t=1;
	qcount = 0;
	// cin >> t;
	t=30000;n=50;q=170*t;
	// cin>> t>> n>> q;
	int tt = t;
	test.assign(n, 0);
	forn(i,n) test[i] = i+1;
	while(t--) {
		shuffle(all(test), rng);
		// test = {2,1,5,4,3};
		// cout << "Case #" << tt-t << ": ";
		go1(n,q);
	}
	cout << "qcount " << qcount << ln;
	// assert(qcount <= q);
	if(qcount <= q) cout << "YES\n";
	else cout << "NO\n";

}