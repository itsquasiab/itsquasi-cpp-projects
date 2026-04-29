// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "maxarr01"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll pf[arr];

void sieve(){
    a[0] = 0;
    a[1] = 1;
    pf[0] = 0;
    pf[1] = 1;
    for (int i = 2; i <= 100000; ++i){
        if (i % 2 == 0) a[i] = a[i / 2];
        else a[i] = a[i / 2] + a[(i + 1) / 2];
        pf[i] = max(pf[i - 1], a[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        cout << pf[n] << "\n";
    }
    return 0;
}