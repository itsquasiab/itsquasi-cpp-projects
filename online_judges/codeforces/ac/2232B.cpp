// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "2232B"

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
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        ll a[n + 1];
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        ll h = a[0], res = a[0];
        cout << h << " ";
        for (int i = 1; i < n; ++i){
            h += a[i];
            res = min(res, h / (i + 1));
            cout << res << " ";
        }
        cout << "\n";
    }
    return 0;
}