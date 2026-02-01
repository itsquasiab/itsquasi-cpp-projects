// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> k;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        if (a[i] == 1){
            res++;
            continue;
        }
        ll i1 = a[i];
        bool not_ok = 0;
        for (int j = 2; j <= k; ++j){
            i1 *= a[i];
            int pos = lower_bound(a + 1, a + 1 + n, i1) - a;
            if (a[pos] != i1){
                not_ok = 1;
                break;
            }
        }
        if (!not_ok) res++;
    }
    cout << res;
    return 0;
}