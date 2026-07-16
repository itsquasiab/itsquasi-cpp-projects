// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bienso"

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
    a = " " + a;
    for (int i = 1; i <= m; ++i){
        int type;
        cin >> type;
        if (type == 1){
            int k;
            char c;
            cin >> k >> c;
            a[k] = c;
        }
        else {
            int l, r;
            cin >> l >> r;
            bool palin = 1;
            while (l < r){
                if (a[l] != a[r]){
                    palin = 0;
                    break;
                }
                l++;
                r--;
            }
            if (palin) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}