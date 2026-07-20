// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "team24"

using namespace std;

const ll arr = 406, mod = 1e9 + 7;

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
    ll res = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 2; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            ll mx = max(a[i], a[j]);
            for (int k = j; k <= i; ++k){
                if (a[k] >= mx){
                    break;
                }
                res++;
            }
        }
    }
    cout << res;
    return 0;
}