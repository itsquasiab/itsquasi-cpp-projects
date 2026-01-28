// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> k;
    if (n >= k && n % k == 2){
        cout << "YES\n";
        for (int i = 1; i <= k; ++i){
            cout << 1 << " ";
        }
        if (k < n)
        cout << n - k;
    }
    else if (n >= 2 * k && n % 2 == 0){
        cout << "YES\n";
        for (int i = 1; i <= k; ++i){
            cout << 2 << " ";
        }
        if (k < n) cout << n - 2 * k;
    }
    else cout << "NO\n";
    return 0;
}