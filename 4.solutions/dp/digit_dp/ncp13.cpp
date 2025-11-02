//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

string num;
ll dp[20][2][2][2];

string current_num;

ll no13(int pos, bool tight, bool has13, int prev1){
    if (has13) return 0;
    if (pos == num.size()) return 1;
    if (dp[pos][tight][has13][prev1] != -1) return dp[pos][tight][has13][prev1];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;

    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        bool new_has13 = has13 || (d == 3 && prev1);
        bool new_prev1 = (d == 1);
        res += no13(pos + 1, new_tight, new_has13, new_prev1);
    }

    return dp[pos][tight][has13][prev1] = res;
}

ll cnt(ll x){
    if (x < 0) return 0;
    num = to_string(x);
    memset(dp, -1, sizeof dp);
    return no13(0, 1, 0, 0);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll l, r;
    while (cin >> l >> r){
        cout << cnt(r) - cnt(l - 1) << "\n";
    }
    return 0;
}