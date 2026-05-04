// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "dddcltkgdn"

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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int res = 1, cnt = 1;
    for (int i = 2; i <= n; ++i){
        if (a[i] >= a[i - 1]) cnt++;
        else {
            res = max(res, cnt);
            cnt = 1;
        }
    }
    res = max(res, cnt);
    cout << res;
    return 0;
}
