// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "matma"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string a;
    cin >> a;
    ll res = 0, tmp = 0;
    for (char c : a){
        if (isdigit(c)) tmp = tmp * 10 + (c - '0');
        else{
            res = max(res, tmp);
            tmp = 0;
        }
    }
    res = max(res, tmp);
    cout << res;
    return 0;
}