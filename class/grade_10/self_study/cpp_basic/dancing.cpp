// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "dancing"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr], b[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cin >> m;
    for (int i = 1; i <= m; ++i) cin >> b[i];
    sort(a + 1, a + 1 + n);
    sort(b + 1, b + 1 + m);
    int i = 1, j = 1;
    int cnt = 0;
    while (i <= n && j <= m){
        if (abs(a[i] - b[j]) <= 1){
            cnt++;
            i++;
            j++;
        }
        else if (a[i] < b[j]) i++;
        else j++;
    }
    cout << cnt;
    return 0;
}