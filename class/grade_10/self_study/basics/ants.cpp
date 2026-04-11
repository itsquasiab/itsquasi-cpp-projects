// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "ants"

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
    ll k;
    int n;
    cin >> n >> k;
    ll mx = -1e18;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        if (a < 0) mx = max(mx, abs(a));
        else if (a > 0) mx = max(mx, k - abs(a));
    }
    cout << mx;
    return 0;
}