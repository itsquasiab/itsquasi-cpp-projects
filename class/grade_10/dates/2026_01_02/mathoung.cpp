// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
#define task "mathuong"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

ll dp[12][1 << 10][2][2]; //dp[pos][seen][tight][started]
string num;

ll solver(int pos, int seen, bool tight, bool started){
    if (pos == num.size()) return started ? 1 : 0;
    if (!tight && dp[pos][seen][0][started] != -1) return dp[pos][seen][0][started];
    ll res = 0;
    int limit = tight ? (num[pos] - '0') : 9;
    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == num[pos] - '0');
        if (!started){
            if (d == 0){
                res += solver(pos + 1, seen, new_tight, 0);
            } else {
                if (!(seen & (1 << d))){
                    res += solver(pos + 1, seen | (1 << d), new_tight, 1);
                }
            }
        } else {
            if (seen & (1 << d)) continue;
            res += solver(pos + 1, seen | (1 << d), new_tight, 1);
        }
    }
    if (!tight)
        dp[pos][seen][tight][started] = res;

    return res;
}

ll cnt(ll x){
    num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1, 0);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll l, r;
    cin >> l >> r;
    cout << cnt(r) - cnt(l - 1);
    return 0;
}