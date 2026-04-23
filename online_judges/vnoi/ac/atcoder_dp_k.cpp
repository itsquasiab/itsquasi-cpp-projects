// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "atcoder_dp_k"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool dp[arr];
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    dp[0] = 0;
    for (int i = 1; i <= k; ++i){
        for (int j = 1; j <= n; ++j){
            if (a[j] <= i){
                dp[i] = (dp[i - a[j]] == 0 ? 1 : 0);
                if (dp[i] == 1) break;
            }
        }
        //cout << dp[i] << " ";
    }
    if (dp[k]) cout << "First";
    else cout << "Second";
    return 0;
}