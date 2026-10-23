// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "LATGACH4"

using namespace std;

const ll arr = 1e6 + 6, mod = 111539786;

ll f[arr];

void fib(){
    f[0] = f[1] = 1;
    for (int i = 2; i < arr; ++i){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
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
    fib();
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << f[n] << "\n";
    }
    return 0;
}