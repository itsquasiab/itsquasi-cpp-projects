// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    ll s = 0;
    while (cin >> n){
        s += n;
    }
    cout << s;
    return 0;
}