// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "damlay"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll dp[arr];
string b;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, l, r;
    cin >> n >> l >> r;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> b;
    b = ' ' + b;
    //cout << -1;
    dp[0] = 0;
    dp[1] = a[1];
    for (int i = 2; i <= n; ++i) dp[i] = 1e18;
    queue<int> min_queue;
    for (int i = 2; i <= n; ++i){
        if (b[i] == '1') continue;
        //implement a min mono queue here:
        //dp[i] = min(dp[i], dp[min_queue.front()] + a[i]);
        for (int j = max(i - r, 0); j <= i - l; ++j){
            if (b[j] == '1') continue;
            dp[i] = min(dp[i], dp[j] + a[i]);
        }
        //cout << dp[i] << " ";
    }
    if (dp[n] == 1e18) cout << -1;
    else cout << dp[n];
    return 0;
}