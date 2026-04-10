// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "incseg"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
        cin >> a[i];
    }
    int tg = 1, res = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] < a[i - 1]){
            res = max(res, tg);
            tg = 1;
        }
        else tg++;
    }
    res = max(res, tg);
    cout << res;
    return 0;
}