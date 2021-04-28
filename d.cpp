#include <iostream>
#include <sstream>
#include <vector>
#include <set>
#include <math.h>
#include <bitset>
#include <iomanip>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
using namespace std;
typedef long long int ll;
typedef long double ld;
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//#define oset tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
#define fast                          \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL)
#define fo(i, n) for (ll i = 0; i < n; i++)
#define PI 3.141592654
#define all(v) (v).begin(), (v).end()
#define allr(v) (v).rbegin(), (v).rend()
#define pb push_back
#define mp make_pair
#define vb vector<bool>
#define vvb vector<vb>
#define vi vector<int>
#define vvi vector<vi>
#define vl vector<ll>
#define vvl vector<vl>
#define pii pair<int, int>
#define vpi vector<pii>
#define unordered_set(T) unordered_set<T, custom_hash>
#define unordered_map(T1, T2) unordered_map<T1, T2, custom_hash>
#define f first
#define se second // large prime for modulo
const ll M = 1e9 + 7;
const ll MAXN=100000;
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
    if (end==st) seg[v]=var;
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


int main() {
        




}