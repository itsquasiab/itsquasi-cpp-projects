// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "summinmax"

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
    int n;
    cin >> n;
    ll mx = -1e18, mn = 1e18;
    long double sum = 0;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        sum += a;
        mx = max(mx, a);
        mn = min(mn, a);
    }
    cout << sum << "\n" << sum * 1.0 / n << "\n" << mn << "\n" << mx;
    return 0;
}