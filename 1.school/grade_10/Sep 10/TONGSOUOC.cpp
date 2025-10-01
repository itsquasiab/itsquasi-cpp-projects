//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll divs(ll n){
    if (n <= 0) return 0;
    ll i = 1;
    ll res = 0;
    while (i <= n){
        ll q = n / i;
        ll nxt = n / q + 1;
        ll cnt = nxt - i;
        res += q * cnt;
        i = nxt;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll l, r;
    cin >> l >> r;
    cout << divs(r) - divs(l - 1);
    /*
    ll sr = sqrt(r);
    for (int i = 1; i <= sr; ++i){
        for (int j = (l + i - 1); j <= r; j += i){
            sum += i + l / i;
        }
    }
    */
    return 0;
}