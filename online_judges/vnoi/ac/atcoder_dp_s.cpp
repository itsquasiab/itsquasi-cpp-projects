//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string k, num;
ll d1;
ll dp[10005][105][2];

ll solver(int pos, ll sum, bool tight){
    if (pos == num.size()) return sum % d1 == 0;
    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;

    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        ll new_sum = (sum + d) % d1;
        res = (res + (solver(pos + 1, new_sum, new_tight))) % mod;
    }
    return dp[pos][sum][tight] = res % mod;
}

ll cnt(string k){
    num = k;
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> k >> d1;
    cout << (cnt(k) - 1 + mod) % mod;
    return 0;
}