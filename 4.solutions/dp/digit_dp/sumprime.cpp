//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a, b;
bool prime[200];
ll dp[20][200];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i < 200; ++i){
        if (!prime[i]){
            for (int j = i * i; j < 200; j += i){
                prime[j] = 1;
            }
        }
    }
}

vector<int> getdg(ll x){
    vector<int> dg;
    while (x > 0){
        dg.push_back(x % 10);
        x /= 10;
    }
    return dg;
}

ll solver(ll pos, bool tight, ll sumdg, const vector<int>& dg){
    if (pos < 0) return !prime[sumdg];
    if (!tight && dp[pos][sumdg] != -1) return dp[pos][sumdg];

    int limit = tight ? (dg[pos]) : 9;
    ll res = 0;
    
    for (int d = 0; d <= limit; ++d){
        bool new_tight = tight && (d == dg[pos]);
        res += solver(pos - 1, new_tight, sumdg + d, dg);
    }
    if (!tight) return dp[pos][sumdg] = res;
    return res;
}

ll cnt(ll x) {
    if (x < 0) return 0;
    vector<int> dg = getdg(x);
    memset(dp, -1, sizeof(dp));
    return solver(dg.size() - 1, 1, 0, dg);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    cin >> a >> b;
    cout << cnt(b) - cnt(a - 1);
    return 0;
}