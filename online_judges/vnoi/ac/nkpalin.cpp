// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "nkpalin"

using namespace std;

const ll arr = 2006, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    int dp[n + 5][n + 5];
    for (int i = 1; i <= n; ++i){
        dp[i][i] = 1;
    }
    for (int i = n; i >= 1; --i){
        for (int j = i + 1; j <= n; ++j){
            if (s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1] + 2;
            else dp[i][j] = max(dp[i][j - 1], dp[i + 1][j]);
        }
    }
    //not my code
    string left = "", right = "";
    int i = 1, j = n;
    while (i <= j){
        if (s[i] == s[j]){
            if (i == j) left += s[i];
            else left += s[i], right = s[j] + right;
            ++i, --j;
        }
        else if (dp[i+1][j] >= dp[i][j-1]) ++i;
        else --j;
    }
    cout << left + right;
    return 0;
}
