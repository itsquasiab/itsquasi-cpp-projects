// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "cau3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], pf[arr];

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
    for (int i = 1; i <= n; ++i) pf[i] = pf[i - 1] + a[i];
    ll res = 0;
    ll discarded = 0;
    for (int i = 1; i < n; ++i){
        ll first_sum = pf[i];
        ll last_sum = pf[n] - pf[i];
        if (first_sum == last_sum){
            res = max(res, first_sum);
        }
    }
    for (int i = 1; i < n - 1; ++i){
        for (int j = i + 1; j < n; ++j){
            ll first_sum = pf[i];
            ll middle_sum = pf[j] - pf[i];
            ll last_sum = pf[n] - pf[j];
            if (middle_sum == last_sum && res < middle_sum){
                res = middle_sum;
                discarded = first_sum;
            }
        }
    }
    cout << res + discarded << "\n";
    return 0;
}