// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "pickleball"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

struct pick
{
    ll a, b, c;
} a[arr];

ll dp[arr];

bool sorter(pick a, pick b){
    return a.b < b.b;
}

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i].a >> a[i].b >> a[i].c;
    }
    sort(a + 1, a + 1 + n, sorter);
    dp[1] = a[1].c;
    ll mx = 0;
    for (int i = 2; i <= n; ++i){
        dp[i] = dp[i - 1];
        for (int j = 1; j < i; ++j){
            if (a[j].b <= a[i].a)
            dp[i] = max(dp[i - 1], dp[j] + a[i].c);
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}