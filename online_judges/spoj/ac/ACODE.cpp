// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "ACODE"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

ll dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    while (1){
        string s;
        cin >> s;
        if (s[0] == '0') break;
        int n = s.size();
        s = ' ' + s;
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; ++i) dp[i] = 0;
        for (int i = 2; i <= n; ++i){
            if (s[i] >= '1' && s[i] <= '9') dp[i] += dp[i - 1];
            int last_2_digits = stoi(s.substr(i - 1, 2));
            if (last_2_digits >= 10 && last_2_digits <= 26) dp[i] += dp[i - 2];
        }
        cout << dp[n] << "\n";
    }
    return 0;
}