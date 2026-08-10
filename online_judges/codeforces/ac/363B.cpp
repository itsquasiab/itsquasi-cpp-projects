// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "363B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        a[i] += a[i - 1];
    }
    int res;
    ll mx = 1e18;
    for (int i = k; i <= n; ++i){
        if (a[i] - a[i - k] < mx){
            mx = a[i] - a[i - k];
            res = i - k + 1;
        }
    }
    cout << res;
    return 0;
}