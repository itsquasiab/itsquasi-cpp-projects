//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const ll mod = 1e9 + 7;
string num;
ll dp[20][200][2][2];
ll a, b, k;

ll countDP(int pos, int sum, bool tight, bool iszero) {
    if (sum > k) return 0;
    if (pos == num.size()) return (sum == k);
    if (dp[pos][sum][tight][iszero] != -1) return dp[pos][sum][tight][iszero];

    int limit = tight ? num[pos] - '0' : 9;
    ll res = 0;
    for (int d = 0; d <= limit; ++d) {
        bool new_tight = tight && (d == limit);
        bool new_zero = iszero && (d == 0);
        res += countDP(pos + 1, sum + d * (!new_zero), new_tight, new_zero);
    }
    return dp[pos][sum][tight][iszero] = res;
}

ll cnt(ll x) {
    if (x < 0) return 0;
    num = to_string(x);
    memset(dp, -1, sizeof dp);
    return countDP(0, 0, 1, 1);
}

string build(int pos, int sum, bool tight, bool iszero) {
    if (pos == num.size()) return "";
    int limit = tight ? num[pos] - '0' : 9;

    for (int d = 0; d <= limit; ++d) {
        bool new_tight = tight && (d == limit);
        bool new_zero = iszero && (d == 0);
        ll next = countDP(pos + 1, sum + d * (!new_zero), new_tight, new_zero);
        if (next > 0 && sum + d * (!new_zero) <= k) {
            if (iszero && d == 0)
                return build(pos + 1, sum, new_tight, new_zero);
            else
                return string(1, char('0' + d)) + build(pos + 1, sum + d, new_tight, 0);
        }
    }
    return "";
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);

    cin >> a >> b >> k;
    ll ans = cnt(b) - cnt(a - 1);
    cout << ans << "\n";

    if (ans > 0) {
        num = to_string(b);
        memset(dp, -1, sizeof dp);
        countDP(0, 0, 1, 1); // fill dp
        string smallest = build(0, 0, 1, 1);
        cout << smallest << "\n";
    }
    return 0;
}