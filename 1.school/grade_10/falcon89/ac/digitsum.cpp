//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string num;
ll dp[20][200][2];

ll solver(int pos, int sum, bool tight){
    if (pos == num.size()) return sum;
    if (dp[pos][sum][tight] != -1) return dp[pos][sum][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;
    
    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        res = (res + solver(pos + 1, sum + d, new_tight)) % mod;
    }

    return dp[pos][sum][tight] = res % mod;
}

ll cnt(ll x){
    num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b;
    cin >> a >> b;
    cout << (cnt(b) - cnt(a - 1) + mod) % mod;
    return 0;
}