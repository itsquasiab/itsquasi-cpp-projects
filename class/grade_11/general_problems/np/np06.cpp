// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "np06"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

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
    ll l = 0, r = 1e9;
    ll res = 0;
    while (l <= r){
        ll mid = l + ((r - l) >> 1);
        if (mid * mid <= n){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}