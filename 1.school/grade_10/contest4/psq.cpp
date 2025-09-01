//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR1 = 1e6 + 6, ARR = 5e3 + 4, MOD = 1e9 + 9;

bool prime[ARR1];
ll a[ARR][ARR], dp[ARR][ARR];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < ARR1; ++i){
        if (!prime[i]){
            for (int j = i * i; j < ARR1; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
            if (!prime[a[i][j]]) dp[i][j] = 1;
        }
    }
    ll mx = 0;
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1] - dp[i - 1][j - 1] + dp[i][j];
        }
    }
    for (int i = 1; i <= m; ++i){
        for (int j = 1; j <= n; ++j){
            cout << dp[i][j] << " ";
        }
        cout << "\n";
    }
    cout << mx;
    /*for (int i = 1; i <= m; ++i){
        cout << "| ";
        for (int j = 1; j <= n; ++j){
            cout << i << " " << j << " | ";
        }
        cout << "\n";
    }*/
    return 0;
}