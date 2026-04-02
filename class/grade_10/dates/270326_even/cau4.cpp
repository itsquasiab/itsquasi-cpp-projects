// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "cau4"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], k[arr], pf[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= m; ++i) cin >> k[i];
    // prefix sum
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        //cout << a[i] << " ";
        pf[i] = pf[i - 1] + a[i];
    }
    //cout << "\n";
    // binary search
    for (int i = 1; i <= m; ++i){
        // Use lower_bound to find the first element >= k[i]
        int idx = lower_bound(a + 1, a + 1 + n, k[i]) - a;

        // Elements smaller than k[i] (indices 1 to idx-1)
        ll count_low = idx - 1;
        ll sum_low = pf[idx - 1];
        ll res_low = (count_low * k[i]) - sum_low;

        // Elements greater than or equal to k[i] (indices idx to n)
        ll count_high = n - idx + 1;
        ll sum_high = pf[n] - pf[idx - 1];
        ll res_high = sum_high - (count_high * k[i]);

        cout << res_low + res_high << " ";
    }
    return 0;
/*
for (int j = 1; j <= n; ++j){
    if (a[j] > k[i]) t += a[j] - k[i];
    else if (a[j] < k[i]) t += k[i] - a[j];
}
*/
/*
ll t = 0;
int lowpoint = lower_bound(a + 1, a + 1 + n, k[i]) - a;
int highpoint = upper_bound(a + 1, a + 1 + n, k[i]) - a;
if (lowpoint == k[i]) lowpoint--;
ll sumlow = pf[lowpoint] - pf[0];
ll sumhigh = pf[n] - pf[highpoint - 1];
ll low2 = k[i] * lowpoint;
ll high2 = k[i] * (n - highpoint + 1);
cout << (low2 - sumlow) + (sumhigh - high2) << " ";
*/
}