// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "897A"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    string a;
    cin >> n >> m >> a;
    for (int i = 1; i <= m; ++i){
        int l, r;
        char c1, c2;
        cin >> l >> r >> c1 >> c2;
        for (int j = l - 1; j < r; ++j){
            if (a[j] == c1) a[j] = c2;
        }
    }
    cout << a;
    return 0;
}