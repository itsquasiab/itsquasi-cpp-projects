// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "breaking"

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
    ll mx = a[1], mn = a[1], rcmx = 0, rcmn = 0;
    for (int i = 2; i <= n; ++i){
        if (a[i] > mx){
            mx = a[i];
            rcmx++;
        }
        else if (a[i] < mn){
            mn = a[i];
            rcmn++;
        }
    }
    cout << rcmx << " " << rcmn;
    return 0;
}