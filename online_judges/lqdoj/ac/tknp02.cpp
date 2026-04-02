// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "tknp02"

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
    }
    while (k--){
        ll x;
        cin >> x;
        int j = lower_bound(a + 1, a + 1 + n, x) - a;
        while (a[j] > x || j > n) j--;
        if (j < 0) j = 0;
        cout << j << "\n";
    }
    return 0;
}