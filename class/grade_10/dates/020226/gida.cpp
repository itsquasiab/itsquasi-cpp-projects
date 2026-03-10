// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + n);
    int j = 1, c = 0;
    for (int i = 1; i <= n; ++i){
        if (a[j] < b[i]){
            c++;
            j++;
        }
    }
    cout << c;
    return 0;
}