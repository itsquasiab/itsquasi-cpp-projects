// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "dethuongpair,cpp"

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
    int save = 1;
    ll res = 0;
    int l = 1, r = 1;
    for (int i = 2; i <= n; ++i){
        if (res < a[i] - a[save]){
            res = a[i] - a[save];
            l = save;
            r = i;
        }
        if (a[save] > a[i]){
            save = i;
        }
    }
    cout << l << " " << r << "\n" << res;
    return 0;
}