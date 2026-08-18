// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "1343C"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll sign(ll a){
    if (a > 0) return 1;
    else return -1;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int tc;
    cin >> tc;
    while (tc--){
        int n;
        cin >> n;
        ll a[n + 5];
        for (int i = 0; i < n; ++i){
            cin >> a[i];
        }
        ll sum = 0;
        for (int i = 0; i < n; ++i){
            ll cur = a[i];
            int j = i;
            while (j < n && sign(a[i]) == sign(a[j])){
                cur = max(cur, a[j]);
                ++j;
            }
            sum += cur;
            i = j - 1;
        }
        cout << sum << "\n";
    }
    return 0;
}