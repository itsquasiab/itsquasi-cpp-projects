// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr], b[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + n);
    int i = 1, j = 1, res = 0;
    ll last = LLONG_MIN;
    while (i <= n && j <= n){
        ll l = min(a[i], b[j]);
        ll r = max(a[i], b[j]);
        if (last < l){
            res++;
            last = r;
            i++, j++;
        }
        else {
            if (a[i] < b[j]) i++;
            else j++;
        }
    }
    cout << res;
    return 0;
}