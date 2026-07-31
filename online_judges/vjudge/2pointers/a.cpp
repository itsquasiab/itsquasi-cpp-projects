// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "a"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

ll a[arr], pf[arr];

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
        pf[i] = pf[i - 1] + a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ll sum = pf[j] - pf[i - 1];
            if (sum & 1) continue;
            ll half = sum / 2;
            int l = i, r = j;
            while (l <= r){
                int mid = (l + r) >> 1;
                ll pf1 = pf[mid] - pf[i - 1];
                ll pf2 = pf[j] - pf[mid];
                //cerr << pf1 << " " << pf2 << " | ";
                if (pf1 == pf2){
                    res = max(res, j - i + 1);
                    break;
                }
                else if (pf1 < pf2){
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            //cerr << "\n";
        }
    }
    cout << res;
    return 0;
}