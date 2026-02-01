// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a, dp[94];

void fibo(){
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= 92; ++i){
        dp[i] = dp[i - 1] + dp[i - 2];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    fibo();
    cin >> n;
    while (n--){
        cin >> a;
        if (a == 0){
            cout << "No\n";
            continue;
        }
        int j = lower_bound(dp + 1, dp + 92, a) - dp;
        //cout << dp[j] << " ";
        if (dp[j] == a) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}