// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "hp_thpt_23_d"

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
        int n;
        ll k;
        cin >> n >> k;
        ll a[n + 5];
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        sort (a + 1, a + 1 + n);
        bool found = 0;
        for (int i = 1; i < n; ++i){
            int target = k - a[i];
            int j = lower_bound(a + 1, a + 1 + n, target) - a;
            if (((a[i] % 2 == 0 && a[j] & 1) || (a[i] & 1 && a[j] % 2 == 0)) && a[i] + a[j] == k){
                cout << 1;
                found = 1;
                break;
            }
        }
        if (!found) cout << 0;
    }
    return 0;
}