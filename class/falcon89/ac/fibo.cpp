// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cses1722"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

void mul(ll a[2][2], ll b[2][2]){
    ll res[2][2];
    res[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[0][1]) % mod;
    res[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % mod;
    res[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % mod;
    res[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % mod;
    for (int i = 0; i < 2; ++i){
        for (int j = 0; j < 2; ++j){
            a[i][j] = res[i][j];
        }
    }
}

void pwned(ll a[2][2], ll n){
    if (n <= 1) return;
    ll base[2][2] = {{1, 1}, {1, 0}};
    pwned(a, n / 2);
    mul(a, a);
    if (n & 1) mul(a, base);
}

ll fib(ll n){
    if (n == 0) return 0;
    ll a[2][2] = {{1, 1}, {1, 0}};
    pwned(a, n - 1);
    return a[0][0];
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    cout << fib(n);
    return 0;
}
