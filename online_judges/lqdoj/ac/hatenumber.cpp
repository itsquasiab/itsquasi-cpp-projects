// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "hatenumber"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

ll a[arr];

void pre(){
    int j = 1;
    for (int i = 1; i <= 1666; ++i){
        if (i % 3 == 0 || i % 10 == 3) continue;
        a[j] = i;
        j++;
        if (j > 1000) break;
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
    pre();
    int q;
    cin >> q;
    while (q--){
        int x;
        cin >> x;
        cout << a[x] << "\n";
    }
    return 0;
}