// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "malenseq"

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
        }
        ll res = 1, tmp = 1;
        for (int i = 2; i <= n; ++i){
            if (a[i - 1] < a[i]) tmp++;
            else {
                res = max(res, tmp);
                tmp = 1;
            }
        }
        res = max(res, tmp);
        cout << res << "\n";
    }
    return 0;
}
