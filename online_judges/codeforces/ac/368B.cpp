// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "368B"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr], dp[arr];
unordered_map<ll, bool> existed;

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[n + 1] = 0;
    for (int i = n; i >= 1; --i){
        dp[i] = dp[i + 1];
        if (!existed.count(a[i])){
            dp[i]++;
            existed[a[i]] = 1;
        }
    }
    while (m--){
        ll l;
        cin >> l;
        cout << dp[l] << "\n";
    }
    return 0;
}