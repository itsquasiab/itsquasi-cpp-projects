// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "tree"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll h[arr];

void sieve(){
    h[0] = 1;
    for (int i = 1; i <= arr; ++i){
        h[i] = h[i - 1];
        if (i & 1) h[i] *= 2;
        else h[i]++;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    sieve();
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << h[n] << "\n";
    }
    return 0;
}