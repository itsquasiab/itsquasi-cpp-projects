// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "1857C"

using namespace std;

const ll arr = 5e5 + 6, mod = 1e9 + 7;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    while (t--){
        int n;
        cin >> n;
        ll b[n + 5];
        ll n1 = n * (n - 1) / 2;
        for (int i = 1; i <= n1; ++i) cin >> a[i];
        sort (a + 1, a + 1 + n1);
        int i = 1;
        int j = 1;
        int step = n - 1;
        while (i <= n1){
            b[j] = a[i];
            //cout << a[i] << " ";
            i += step;
            j++;
            step--;
        }
        b[n] = b[n - 1];
        for (int i = 1; i <= n; ++i){
            cout << b[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}