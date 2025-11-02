//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= 1e6; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= 1e6; j += i) prime[j] = 1;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("psq.inp","r"))
    {
        freopen("psq.inp", "r", stdin);
        freopen("psq.out", "w", stdout);
    }
    sieve();
    int m, n;
    cin >> m >> n;
    ll a[m + 5][n + 5];
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    ll dp[m + 5][n + 5];
    ll mx = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (!prime[a[i][j]]){
                //if (i == 1 && j == 1) dp[i][j] = 1;
                dp[i][j] = min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]}) + 1;
                mx = max(mx, dp[i][j]);
            }
            else dp[i][j] = 0;
        }
    }
    cout << mx * mx;
    
    /*int l = min(m, n);
    int res = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            if (prime[a[i][j]]) continue;
            int most_right = min(i, m);
            int most_down = min(j, n);
            int limit = min(most_right, most_down);
            for (int lm = 1; lm <= min(limit, l); ++lm){
                bool ok = 1;
                for (int down = j; down <= j + lm - 1; ++down){
                    for (int right = i; right <= i + lm - 1; ++right){
                        if (prime[a[i][j]]){
                            ok = 0;
                            break;
                        }
                    }
                }
                if (ok) res = max(res, lm * lm);
            }
        }
    }
    cout << res;*/
    return 0;
}