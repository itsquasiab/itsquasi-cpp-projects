// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a;

ll trailing_zeroes(ll n){
    ll t = 0;
    while(n){
        t += n / 5;
        n /= 5;
    }
    return t;
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
        cin >> a;
        cout << trailing_zeroes(a) << "\n";
    }
    return 0;
}