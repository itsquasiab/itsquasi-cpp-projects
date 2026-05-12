// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cb06"

using namespace std;

const ll arr = 106, mod = 1e9 + 7;

char a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll t = 0;
    for (int i = 2; i <= n; ++i){
        if (a[i] == a[i - 1]) t++;
    }
    cout << t;
    return 0;
}