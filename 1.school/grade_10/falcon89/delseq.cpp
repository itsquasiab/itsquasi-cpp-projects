// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 7006, mod = 1e9 + 7;

int n;
ll a[arr];
unordered_map<long long, int> dp[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    if (n == 1){
        cout << 1;
        return 0;
    }
    for (int i = 1; i <= n; ++i){
        dp[i].reserve(i);
    }
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j < i; ++j){
            ll d = a[i] - a[j];
            if (dp[j].find(d) != dp[j].end()){
                dp[i][d] = max(dp[i][d], dp[j][d] + 1);
            }
            else dp[i][d] = 2;
        }
    }
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (auto j : dp[i]){
            res = max(res, j.second);
        }
    }
    cout << res;
    return 0;
}