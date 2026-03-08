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
    ll res = 0, i = 1;
    while(res < n){
        res += i;
        i++;
    }
    if (res == n) cout << "YES";
    else cout << "NO";
    return 0;
}