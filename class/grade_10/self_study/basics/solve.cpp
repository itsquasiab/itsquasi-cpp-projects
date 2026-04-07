// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "solve"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll sumdg(ll x){
    ll t = 0;
    while (x){
        t += x % 10;
        x /= 10;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    ll l = 1, r = 1000000000;
    while (l <= r){
        ll mid = (l + r) >> 1;
        ll exp = mid * mid + sumdg(mid) * mid;
        if (exp == n){
            cout << mid;
            return 0;
        }
        else if (exp < n){
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << -1;
    return 0;
}