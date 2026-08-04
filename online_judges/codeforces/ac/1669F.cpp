// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1476A"

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
        ll a[n + 5], pf[n + 5];
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        int j = n;
        ll sum_alice = 0, sum_bob = 0;
        int res = 0;
        for (int i = 1; i <= min(n, j); ++i){
            sum_alice += a[i];
            while (sum_alice > sum_bob && j > i){
                sum_bob += a[j];
                j--;
            }
            if (sum_alice == sum_bob){
                res = max(res, i + (n - j));
            }
        }
        cout << res << '\n';
    }
    return 0;
}