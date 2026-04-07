// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "subset"

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
        for (int i = 1; i <= n; ++i) cin >> a[i];
        bool ok = 0;
        ll divs;
        for (int i = 1; i <= n; ++i){
            divs = a[i];
            if (divs <= 1){
                ok = 1;
                break;
            }
            for (int j = i + 1; j <= n; ++j){
                divs = __gcd(divs, a[j]);
                if (divs <= 1){
                    ok = 1;
                    break;
                }
            }
        }
        cout << (ok ? "YES\n" : "NO\n");
    }
    return 0;
}