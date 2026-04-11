// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "sumx"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

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
    sort (a + 1, a + 1 + n);
    ll x;
    cin >> x;
    ll res = 0;
    int i = 1, j = n;
    while (i < j){
        if (a[i] + a[j] == x){
            res++;
            i++;
            j--;
        }
        else if (a[i] + a[j] < x){
            i++;
        }
        else j--;
    }
    cout << res;
    return 0;
}