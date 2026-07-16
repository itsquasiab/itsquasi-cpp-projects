// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "AIBOHP"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, bs = 31;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    while (n--){
        string s;
        cin >> s;
        int n = s.size();
        vector<vector<int>> dp(3, vector<int>(n, 0));
        for (int len = 2; len <= n; ++len){
            for (int i = 0; i <= n - len; ++i){
                int j = i + len - 1;
                if (s[i] == s[j]) dp[len % 3][i] = (len == 2) ? 0 : dp[(len - 2) % 3][i + 1];
                else dp[len % 3][i] = 1 + min(dp[(len - 1) % 3][i + 1], dp[(len - 1) % 3][i]);
            }
        }
        cout << dp[n % 3][0] << "\n";
    }
    return 0;
}