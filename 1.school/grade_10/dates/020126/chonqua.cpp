// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
#define ll long long
#define task "chonqua"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

ll a[arr], b[arr];
ll res = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort(a + 1, a + 1 + n);
    ll sum = k;
    for (int i = 1; i <= n; ++i){
        if (a[i] <= sum){
            res++;
            sum -= a[i];
        }
        else break;
    }
    cout << res;
    return 0;
}