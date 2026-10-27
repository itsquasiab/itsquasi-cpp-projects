// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
#define task "door"

using namespace std;

const ll arr = 1e6 + 6, mod = 998244353;

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
    ll s;
    cin >> n >> s;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll max_mask = (1 << n) - 1;
    ll res = 0;
    for (int mask = 0; mask <= max_mask; mask++){
        int j = 1;
        int nmask = mask;
        ll sum = 0;
        while (nmask){
            if (nmask % 2 == 1){
                sum += a[j];
            }z
            nmask /= 2;
            j++;
        }
        if (sum == s) res++;
    }
    cout << res;
    return 0;
}