// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "cau2"

using namespace std;

const ll arr = 2006, mod = 1e9 + 7;

ll a[arr], b[arr];

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
    ll sum = 1e9;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i){
        // tai vi tri nay se duoc giu nguyen, cac vi tri khac se phai bien doi
        ll temp = 0;
        for (int j = 1; j <= n; ++j){
            if (i == j) continue;
            temp += abs(a[j] - (j - i + a[i]));
        }
        sum = min(sum, temp);
    }
    cout << sum;
    return 0;
}