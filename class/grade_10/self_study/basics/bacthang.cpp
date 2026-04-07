// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bacthang"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool check_staircase(ll n){
    if (n <= 11) return 0;
    int t = 0;
    while (n){
        t = n % 10;
        n /= 10;
        if (n % 10 >= t) return 0;
    }
    return 1;
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
    int cnt = 0;
    while (t--){
        ll a;
        cin >> a;
        if (check_staircase(a)) cnt++;
    }
    cout << cnt;
    return 0;
}