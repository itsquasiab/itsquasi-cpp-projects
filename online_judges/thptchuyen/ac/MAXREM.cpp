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

int n;
ll a[arr], res = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    sort (a + 1, a + 1 + n);
    ll second_max = -1;
    for (int i = 1; i < n; ++i){
        if (a[i] != a[n]) second_max = a[i];
        else break;
    }
    if (second_max == -1) cout << 0;
    else cout << second_max % a[n];
    return 0;
}