// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "451B"

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i], b[i] = a[i];
    sort(b + 1, b + 1 + n);
    int l = -1, r = -1;
    for (int i = 1; i <= n; ++i){
        if (a[i] != b[i]){
            l = i;
            break;
        }
    }
    for (int i = n; i >= 1; --i){
        if (a[i] != b[i]){
            r = i;
            break;
        }
    }
    if (l == r){
        cout << "yes\n1 1";
        return 0;
    }
    reverse (a + l, a + 1 + r);
    for (int i = l; i <= r; ++i){
        //cout << a[i] << " " << b[i] << "\n";
        if (a[i] != b[i]){
            cout << "no";
            return 0;
        }
    }
    cout << "yes\n" << l << " " << r << "\n";
    return 0;
}