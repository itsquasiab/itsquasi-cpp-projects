// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "339B"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= m; ++i){
        cin >> a[i];
    }
    ll unit = a[1] - 1;
    //cout << unit << "\n";
    for (int i = 2; i <= m; ++i){
        if (a[i - 1] < a[i]) unit += a[i] - a[i - 1];
        else if (a[i] < a[i - 1]){
            //cout << n - a[i - 1] << " " << a[i] - 1 << "\n";
            unit += n - a[i - 1] + a[i];
        }
        //cout << unit << "\n";
    }
    cout << unit;
    return 0;
}