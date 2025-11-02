//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int n;
ll x;
ll a[arr], dp[arr];

void reset(){
    memset(dp, 0, sizeof(dp));
}

void coin_combination_1(){
    dp[0] = 1;
    for (int i = 1; i <= x; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (i >= a[j]) {
                dp[i] = (dp[i] + dp[i - a[j]]) % mod;
            }
        }
    }
    cout << dp[x] << "\n";
}

void coin_combination_2(){
    dp[0] = 1;
    for (int j = 1; j <= n; ++j) {
        for (int i = a[j]; i <= x; ++i) {
            dp[i] = (dp[i] + dp[i - a[j]]) % mod;
        }
    }
    cout << dp[x] << "\n";
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    coin_combination_1();
    reset();
    coin_combination_2();
    return 0;
}