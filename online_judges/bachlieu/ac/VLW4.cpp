// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool special(ll n){
    ll t = 0, of = n;
    while (n > 0){
        t += n % 10;
        n /= 10;
    }
    if (of % t == 0) return 1;
    return 0; 
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        cout << (special(a) ? 1 : 0) << "\n";
    }
    return 0;
}