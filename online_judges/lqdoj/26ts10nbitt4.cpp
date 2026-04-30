// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "26ts10nbitt4"

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
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] = abs(a[i]);
        }
        int res = 1;
        for (int i = 1; i < n; ++i){
            ll d = 0;
            for (int j = i; j <= n; ++j){
                d = __gcd(d, a[j]);
                if (d == 1) break;
                res = max(res, j - i + 1);
                cout << d << " ";
            }
        }
        cout << res << "\n";
    }
    return 0;
}
