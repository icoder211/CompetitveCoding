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

vector<string> a;
vector<ld> cnt;
vector<int> accum;
void go() {
    accum.assign(100,0);
    cnt.assign(100, 0);
    a.assign(100, "");
    forn(i,100) {
        string s; cin >> s;
        a[i] = s;
    }
    forn(i,100) {
        ld cnt1;
        forn(j,10000) {
            cnt1 += a[i][j]-'0';
        }
        cnt[i] = cnt1;
        ld d = log((long double)10000/cnt1 - (long double)1);
        d += 3;
        d *= 100/(long double)6;
        ll s = floor(d);
        accum[s]++;
    }
    ll sus = max_element(all(accum)) - accum.begin();
    forn(i,100) {
        ll cnt1 = cnt[i];
        ld d = log((long double)10000/cnt1 - (long double)1);
        d += 3;
        d *= 100/(long double)6;
        ll s = floor(d);
        if(s == sus) {
            cout << i + 1 << ln;
            return;
        }
    }
    int mx = max_element(all(cnt))-cnt.begin();
    cout << mx +1 <<ln;

}

int main() {
    IO;
    int t;cin >> t;
    int p;cin >> p;
    int tt = t;
    while(t--) {
        cout << "Case #" << tt-t << ": ";
        go();
    }
}