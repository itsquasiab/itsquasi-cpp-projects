// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1475B"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool check(ll n){
    if (n < 2020) return 0;
    int len = (n / 2020) + 1;
    for (int i = 1; i <= len; ++i){
        if (n % 2021 == 0) return 1;
        n -= 2020;
        if (n == 0) return 1;
        if (n < 0) return 0;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--){
        ll n;
        cin >> n;
        cout << (check(n) ? "YES\n" : "NO\n");
    }
    return 0;
}