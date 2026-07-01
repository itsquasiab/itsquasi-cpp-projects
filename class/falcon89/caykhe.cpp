// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "caykhe"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

struct gems{
    ll w, v, i;
} a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll m;
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].w >> a[i].v >> a[i].i;
    }
    
    return 0;
}