//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) cin >> a[i];
        int res = 0;
        for (int i = 1; i <= n; ++i){
            int j = lower_bound(dp + 1, dp + 1 + res, a[i]) - dp;
            dp[j] = a[i];
            res = max(res, j);
        }
        cout << res << "\n";
    }
    return 0;
}