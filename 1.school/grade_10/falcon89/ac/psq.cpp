//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int arr = 1e6 + 6;
bool prime[arr];

void sieve() {
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int n, m;
    cin >> n >> m;
    vector<vector<ll>> a(n+1, vector<ll>(m+1));
    vector<vector<ll>> dp(n+1, vector<ll>(m+1, 0));

    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= m; ++j)
            cin >> a[i][j];

    ll mx = 0;
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= m; ++j) {
            if (!prime[a[i][j]]) {
                dp[i][j] = min({dp[i-1][j], dp[i][j-1], dp[i-1][j-1]}) + 1;
                mx = max(mx, dp[i][j]);
            }
        }
    }
    cout << mx * mx;
    return 0;
}