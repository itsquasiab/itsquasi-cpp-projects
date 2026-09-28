// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "1819bosotg"

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    ll res = 0;
    for (int i = 1; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            ll target = a[i] + a[j];
            int l = j + 1, r = n;
            ll k = j;
            while (l <= r){
                int mid = (l + r) >> 1;
                if (a[mid] < target){
                    k = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            //cout << i << " " << j << " " << k << "\n";
            res += k - j;
        }
    }
    cout << res;
    return 0;
}