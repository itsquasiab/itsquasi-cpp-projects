// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <cstdio>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    ll neg = 0, pos = 0;
    while (n--){
        int a;
        cin >> a;
        if (a < 0) neg++;
        else if (a > 0) pos++;
    }
    cout << neg * pos;
    return 0;
}