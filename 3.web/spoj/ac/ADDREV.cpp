// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a, b;

ll reverse(ll n){
    ll res = 0;
    while (n){
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    while (n--){
        cin >> a >> b;
        cout << reverse(reverse(a) + reverse(b)) << "\n";
    }
    return 0;
}