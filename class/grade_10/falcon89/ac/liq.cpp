//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll a[ARR], dp[ARR];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll mx = 1;
    for (int i = 1; i <= n; ++i){
        dp[i] = 1;
        for (int j = 1; j < i; ++j){
            if (a[j] <= a[i]) dp[i] = max(dp[i], dp[j] + 1);
        }
        mx = max(mx, dp[i]);
    }
    cout << mx;
    return 0;
}