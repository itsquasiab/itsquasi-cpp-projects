// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1872D"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll gcd(ll a, ll b){
    return (b ? gcd(b, a % b) : a);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        ll n, x, y;
        cin >> n >> x >> y;
        ll lcmxy = x * y / gcd(x, y);
        ll permx = n / x - n / lcmxy;
        ll permy = n / y - n / lcmxy;
        ll res = 0;
        res += (n + (n - permx + 1)) * permx / 2;
        res -= permy * (permy + 1) / 2; 
        cout << res << "\n";
    }
    return 0;
}