// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "mtwalk"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

ll a[arr][arr];
pair<ll, ll> dp[arr][arr];

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
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= n; ++i){
        
    }
    return 0;
}