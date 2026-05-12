// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <vector>
#define ll long long
#define task "malenseq"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[6] = {100, 20, 10, 5, 1};

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
        ll n;
        cin >> n;
        int j = 0;
        ll res = 0;
        while (n > 0){
            res += n / a[j];
            n = n % a[j];
            j++;
        }
        cout << res << "\n";
    }
    return 0;
}