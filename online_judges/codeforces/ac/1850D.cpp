// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "1850D"

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
        sort(a + 1, a + 1 + n);
        vector<ll> container;
        container.push_back(a[1]);
        int mx = 0;
        for (int i = 2; i <= n; ++i){
            if (a[i] - a[i - 1] <= k){
                container.push_back(a[i]);
            }
            else {
                mx = max(mx, int(container.size()));
                container.clear();
                container.push_back(a[i]);
            }
        }
        mx = max(mx, int(container.size()));
        cout << n - mx << "\n";
    }
    return 0;
}