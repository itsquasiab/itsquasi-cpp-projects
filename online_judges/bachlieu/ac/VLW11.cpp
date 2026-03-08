// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    for (int i = 2; i * i <= n; ++i){
        while (n % i == 0){
            n /= i;
            cout << i << " ";
        }
    }
    if (n > 1) cout << n;
    return 0;
}