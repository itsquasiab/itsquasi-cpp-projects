//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n, res = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n >= 5){
        res += n / 5;
        n /= 5;
    }
    cout << res;
    return 0;
}