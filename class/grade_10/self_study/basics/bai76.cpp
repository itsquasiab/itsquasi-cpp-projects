// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai76"

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
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    int i = 1, j = 1, res = 0;
    while (i <= n && j <= m){
        if (a[i] == b[j]){
            res++;
            i++;
            j++;
        }
        else i++;
    }
    cout << (res == m ? "YES\n" : "NO\n");
    return 0;
}