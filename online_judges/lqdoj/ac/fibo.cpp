// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll dp[54];
void fibo(){
    dp[1] = dp[2] = 1;
    for (int i = 3; i <= 50; ++i){
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
        ll a;
        cin >> a;
        cout << dp[a] << "\n";
    }
    return 0;
}