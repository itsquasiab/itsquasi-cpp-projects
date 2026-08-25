// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1637"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int mxdg(int n){
    int t = 0;
    while (n){
        t = max(t, n % 10);
        n /= 10;
    }
    return t;
}

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
    int res = 0;
    while (n){
        n -= mxdg(n);
        res++;
    }
    cout << res;
    return 0;
}