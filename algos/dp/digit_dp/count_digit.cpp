//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll dp[20][420][2]; //dp[pos][tight];
string num;

ll solver(int pos, ll cnt, bool tight){
    if (pos == num.size()) return cnt;
    if (dp[pos][cnt][tight] != -1) return dp[pos][cnt][tight];
    ll res = 0;
    int limit = tight ? (num[pos] - '0') : 9;
    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == limit);
        res += solver(pos + 1, cnt + 1, new_tight);
    }
    return dp[pos][cnt][tight] = res;
}

ll cnt(ll x){
    num = to_string(x);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        ll k;
        cin >> k;
        cout << cnt(k) << "\n";
    }
    return 0;
}