// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "2413"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll dp[arr][3];

void pre(){
    dp[1][1] = dp[1][2] = 1;
    for (int i = 2; i < arr; ++i){
        dp[i][1] = (dp[i - 1][1] * 4 + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][1] + dp[i - 1][2] * 2) % mod;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    pre();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << (dp[n][1] + dp[n][2]) % mod << "\n";
    }
    return 0;
}