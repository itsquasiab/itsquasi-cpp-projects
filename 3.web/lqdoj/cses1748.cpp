//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MIN;

ll a[arr], dp[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        dp[i] = 1;
        for (int j = 1; j < i; ++j){
            if (a[j] < a[i]){
                dp[i] += dp[j];
            }
        }
        sum = (sum + dp[i]) % mod;
    }
    cout << sum;
    return 0;
}