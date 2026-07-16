// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "cau4"

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
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
            a[i] = a[i] * a[i];
        }
        sort(a + 1, a + 1 + n);
        bool found = 0;
        for (int i = 1; i <= n; ++i){
            for (int j = 1; j < i; ++j){
                ll target = a[i] - a[j];
                int k = lower_bound(a + 1, a + 1 + j, target) - a;
                if (a[k] == target){
                    found = 1;
                    break;
                }
            }
            if (found) break;
        }
        cout << (found ? "YES\n" : "NO\n");
    }
    return 0;
}