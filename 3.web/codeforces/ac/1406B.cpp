//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int ts;
    cin >> ts;
    while (ts--){
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        ll ans = inf;
        sort (a + 1, a + 1 + n);
        ans = max(ans, a[n] * a[n-1] * a[n-2] * a[n-3] * a[n-4]);
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[5]);
        ans = max(ans, a[1] * a[2] * a[3] * a[4] * a[n]);
        ans = max(ans, a[1] * a[2] * a[n] * a[n-1] * a[n-2]);
        cout << ans << "\n";
    }
    return 0;
}