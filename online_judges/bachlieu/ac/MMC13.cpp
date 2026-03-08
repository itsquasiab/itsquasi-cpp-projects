// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll res = 1e18;
    sort(a + 1, a + 1 + n);
    for (int i = 2; i <= n; ++i){
        res = min(res, abs(a[i - 1] - a[i]));
    }
    cout << res;
    return 0;
}