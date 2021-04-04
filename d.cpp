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
ll fpow(ll a, ll b)
{ // function for binary exponentiation
    //b%=(M-1);
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a; //%M;
        }
        a = a * a; //%M;
        b >>= 1;
    }
    return res;
}
ll gcd(ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll inv(ll n)
{
    if (n == ll(1))
    {
        return 1;
    }
    return (M - (M / n) * inv(M % n) % M);
}


int main() {
        




}