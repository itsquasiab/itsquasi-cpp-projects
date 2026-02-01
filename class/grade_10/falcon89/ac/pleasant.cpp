//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

string num;
ll dp[150][10][2];

ll solver(int pos, int last, bool tight){
    if (pos == num.size()) return 1;
    if (dp[pos][last][tight] != -1) return dp[pos][last][tight];

    int limit = tight ? (num[pos] - '0') : 9;
    int res = 0;

    for (int d = 0; d <= limit; ++d){
        if (last > d) continue;
        bool new_tight = tight && (d == limit);
        res = (res + solver(pos + 1, d, new_tight)) % mod;
    }
    return dp[pos][last][tight] = res % mod;
}

ll cnt(string x){
    num = x;
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}

string decrease(string a){
    for (int i = a.size() - 1; i >= 0; --i){
        if (a[i] == '0'){
            a[i] = '9';
        }
        else {
            a[i] -= 1;
            break;
        }
    }
    return a;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    string a, b;
    cin >> a >> b;
    a = decrease(a);
    cout << (cnt(b) - cnt(a) + mod) % mod;
    return 0;
}