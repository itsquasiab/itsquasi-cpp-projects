//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a, b;
string num;
ll dp[20][2][2];

ll solver(ll pos, bool has4, bool tight){
    if (has4) return 0;
    if (pos == num.size()) return 1;
    if (dp[pos][has4][tight] != -1) return dp[pos][has4][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    ll res = 0;
    
    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        bool new_has4 = has4 || d == 4;
        
        res += solver(pos + 1, new_has4, new_tight);
    }
    return dp[pos][has4][tight] = res;
}

ll cnt(ll x){
    num = to_string(x);
    memset(dp, -1, sizeof dp);
    return solver(0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1);
    return 0;
}