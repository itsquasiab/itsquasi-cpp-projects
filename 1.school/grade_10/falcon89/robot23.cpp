//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll a, b, c;
    cin >> a >> b >> c;
    ll space = b - a;
    if (c & 1){
        if (a & 1){
            // faulty
            cout << 1 + space / 2 + (b & 1 ? 0 : 1);
        }
        else {
            cout << 1 + space / 2;
        }
    }
    else {
        if (a & 1){
            cout << space / 2 + (b & 1 ? 0 : 1);
        }
        else {
            cout << 1 + space / 2;
        }
    }
    return 0;
}