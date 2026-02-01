// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int t;
int n, k;
ll a[arr];

ll check(ll mid){
    ll last = a[1], res = 1;
    for (int i = 2; i <= n; ++i){
        if (last + mid <= a[i]){
            res++;
            last = a[i];
        }
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort (a + 1, a + 1 + n);
        ll l = 1, r = a[n], res = 0;
        while (l <= r){
            ll mid = (l + r) >> 1;
            if (check(mid) >= k){
                res = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        cout << res << "\n";
    }
    return 0;
}