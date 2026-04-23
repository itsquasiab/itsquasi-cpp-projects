// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "fibo"

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
    int n;
    cin >> n;
    ll f0 = 1;
    ll f1 = 1;
    ll f = 0;
    for (int i = 2; i <= n + 2; ++i){
        f = (f1 + f0) % mod;
        f0 = f1;
        f1 = f;
        //cout << f0 << " " << f1 << " " << f << "\n";
    }
    cout << f - 1;
    return 0;
}