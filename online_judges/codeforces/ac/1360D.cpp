// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1360D"

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
    int t;
    cin >> t;
    while (t--){
        ll n, k;
        cin >> n >> k;
        ll res = n;
        if (n <= k){
            cout << 1 << "\n";
            continue;
        }
        for (int i = 2; i * i <= n; ++i){
            if (n % i == 0){
                if (i <= k) res = min(res, n / i);
                if (n / i != i && n / i <= k) res = min(res, n / (n / i));
            }
        }
        cout << res << "\n";
    }
    return 0;
}