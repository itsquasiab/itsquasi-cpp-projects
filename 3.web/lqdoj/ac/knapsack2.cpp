// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <climits>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll k;
pair<ll, ll> a[arr];
ll sumvalue = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
        sumvalue += a[i].second;
    }
    vector<ll> dp(sumvalue + 1, INT_MAX);
    dp[0] = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = sumvalue; j >= a[i].second; --j){
            dp[j] = min(dp[j], dp[j - a[i].second] + a[i].first);
        }
    }
    ll mx = 0;
    for (int i = 0; i <= sumvalue; ++i){
        if (dp[i] <= k)
            mx = i;
    }
    cout << mx;
    return 0;
}