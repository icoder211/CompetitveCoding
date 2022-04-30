bool check_composite_for_prime_function(ll n, ll a, ll d, int s){
    ll x = exp(a, d, n);
    if (x == 1 || x == n-1) return false;
    for(int r = 1;r < s;++r){
        x = x * x%n;
        x %= n;
        if(x == n-1) return false;
    }
    return true;
}
bool prime(ll n){
    if(n < 4) return n == 2 || n == 3;
    if (!(n&1)) return false;
    int s = 0;
    ll d = n-1;
    while(!(d&1)){
        d >>= 1;
        s++;
    }
    for(int a : {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37}){
        if(n == a) return true;
        if(check_composite_for_prime_function(n, a, d, s)) return false;
    }
    return true;
}