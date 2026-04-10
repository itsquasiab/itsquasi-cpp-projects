// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai52"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll f[60];

void fib(){
    f[0] = 1;
    f[1] = 1;
    for (int i = 2; i <= 50; ++i){
        f[i] = f[i - 1] + f[i - 2];
    }
    for (int i = 0; i <= 50; ++i){
        cout << f[i] << " ";
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
    return 0;
}