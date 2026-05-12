// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai4"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll sumdg(ll n){
    ll tmp = 0, t = 0;
    while (n){
        tmp = n % 10;
        t += tmp;
        n /= 10;
    }
    return t;
}

int special[arr];

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
    special[0] = 0;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        special[i] = special[i - 1];
        if (a % sumdg(a) == 0) special[i]++;
    }
    while (q--){
        int l, r;
        cin >> l >> r;
        cout << special[r] - special[l - 1] << "\n";
    }
    return 0;
}