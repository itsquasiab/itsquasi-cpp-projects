// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

int a[arr][arr];
ll pf[arr][arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            char charles_3;
            cin >> charles_3;
            if (charles_3 == '*') a[i][j] = 1;
        }
    }
    //cout << "\n";
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= n; ++j){
            pf[i][j] = pf[i][j - 1] + pf[i - 1][j] - pf[i - 1][j - 1] + a[i][j];
            //cerr << pf[i][j] << " ";
        }
        //cerr << "\n";
    }
    while (q--){
        int x1, x2, y1, y2;
        cin >> y1 >> x1 >> y2 >> x2;
        y1--;
        x1--;
        cout << pf[y2][x2] - pf[y1][x2] - pf[y2][x1] + pf[y1][x1] << "\n";
    }
    return 0;
}