// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll f[arr];
int n;

void fibo(){
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i){
        f[i] = (f[i - 1] + f[i - 2]) % mod;
    }
    cout << f[n];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    fibo();
    return 0;
}