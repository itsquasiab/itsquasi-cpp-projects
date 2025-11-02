//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

string num;
ll dp[20][201][2]; // dp[pos][sum][tight]

//string current;

// Ham de quy dem so luong so co tong chu so = TARGET_SUM
ll findsum(int pos, int sum, bool tight){
    // Neu het chu so, kiem tra tong co dung khong
    if (pos == num.size()) return sum;
    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;

    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        res += findsum(pos + 1, sum + d, new_tight);
    }

    return dp[pos][sum][tight] = res;
}

// Ham count(x): dem so luong so tu 1 den x co tong chu so = TARGET_SUM
ll cnt(ll x){
    if (x < 0) return 0;
    num = to_string(x);
    memset(dp, -1, sizeof dp);
    return findsum(0, 0, 1);
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll l, r;
    cin >> l >> r;
    cout << cnt(r) - cnt(l - 1) << "\n";
    return 0;
}