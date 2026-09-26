// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "tknp03"

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
        int l = 1, r = n;
        ll res = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (a[mid] >= x){
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if (res == 0) res = n + 1;
        cout << res << "\n";
    }
    return 0;
}