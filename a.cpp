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

// string s;
// ll x, y;
// void go() {
//   cin >> s;
//   cin >> x >> y;
//   ll n = s.size();
//   ll i = s.size()-1;
//   ll onep=0, zerop=0, one=0, zero = 0;
//   forn(j,n) {
//     if(s[j] == '1') one++;
//     else if(s[j] == '0') zero++;
//   }
//   while(i >= 0) {
//     // cout<<i<<ln;
//     if(s[i] == '1') {
//       onep++;
//       one--;
//       i--;
//       continue;
//     }else if(s[i] == '0') {
//       zerop++;
//       zero--;
//       i--;
//       continue;
//     }
//     // ll j = i;
//     // while(s[j] == '?') j--;
//     if(x * (onep - zero) <= y * (zerop - one)) {
//       while(i >= 0 and s[i] == '?') {
//         zerop++;
//         s[i] = '0';
//         i--;
//       }
//     }else {
//       while(i >= 0 and s[i] == '?') {
//         onep++;
//         s[i] = '1';
//         i--;
//       }
//     }
    
//   }
//   ll ans = 0;
//   forn(i,n) {
//     if(s[i] == '1') onep--;
//     else {
//       ans += x * onep;
//     }
//   }
//   forn(i,n) {
//     if(s[i] == '0') zerop--;
//     else {
//       ans += y * zerop;
//     }
//   }
//   cout << ans << ln;
// }

int n;
vector<pair<int, int> > ans;
void pt() {
  cout << ans.size() << ln;
  for(auto u: ans) {
    cout << u.first << " " << u.second << ln;
  }
}
int a[200005];
void go(){
  cin >> n;
  ans.clear();
  forn(i,n+1) a[i]=i;
  int p = n;
  if(n == 3) {
    ans.pb({3,2});
    ans.pb({3,2});
    pt();
    return;
  }
  if(n == 4) {
    ans.pb({3,2});
    ans.pb({3,2});
    ans.pb({4,2});
    ans.pb({4,2});
    pt();
    return;

  }
  if(n == 5) {
    ans.pb({3,2});
    ans.pb({3,2});
    ans.pb({4,2});
    ans.pb({4,2});
    ans.pb({5,2});
    ans.pb({5,2});
    ans.pb({5,2});
    pt();
    return;

  }
  int i = n-1;
  while(p > 2 and i > 0) {
    // cout << p << ln;
    if(i <= sqrt(p) + 2)  break;
    while(i > sqrt(p)+2) {
      ans.pb({i, p});
      a[i] = (a[i] + a[p] - 1) / a[p];
      i--;
    }
    ans.pb({p, i});
    ans.pb({p, i});
    a[p] = (a[p] + a[i] -1) / a[i];
    a[p] = (a[p] + a[i] -1) / a[i];
    if(a[p] > 1) {
      ans.pb({p, i});
      a[p] = (a[p] + a[i] -1) / a[i];

    }
    p = i;
    i--;
  }
  forsn(i,3,n+1) {
    while(a[i] > 1){
      ans.pb({i, 2});
      a[i] = (a[i] + 1 ) / 2;
    }
  }
  pt();
  
}
    
  
 
int main() {
  IO;
  int t;cin >> t;
  while(t--) 
  go();
}