// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a, b, c;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    while (cin >> a >> b >> c){
        if (a == 0 && b == 0 && c == 0) break;
        ll ap = b - a;
        ll gp = b / a;
        if (ap == c - b){
            cout << "AP " << c + ap << "\n";
        }
        else {
            cout << "GP " << c * gp << "\n";
        }
    }
    return 0;
}