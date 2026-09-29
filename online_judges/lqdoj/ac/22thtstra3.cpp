// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "22thtstra3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll valid(ll x){
    ll div3 = x / 3;
    ll end3 = (x - 3) / 10 + (x % 10 >= 3 ? 1 : 0);
    ll both = (x - 3) / 30 + (x % 10 >= 3 ? 1 : 0);
    return x - div3 - end3 + both;
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
    ll res = 0;
    ll l = 1, r = n * 2;
    while (l <= r){
        ll mid = l + ((r - l) >> 1);
        if (valid(mid) >= n){
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    cout << res;
    return 0;
}