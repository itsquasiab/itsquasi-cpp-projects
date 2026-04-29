// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "seqbal"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll pf[arr];
unordered_map<ll, int> pos;

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
        ll a;
        cin >> a;
        if (a == 1) pf[i] = 1;
        else if (a == 0) pf[i] = -1;
    }
    for (int i = 1; i <= n; ++i){
        pf[i] += pf[i - 1];
    }
    pos[0] = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        if (pos.count(pf[i])){
            res = max(res, i - pos[pf[i]]);
        }
        else {
            pos[pf[i]] = i;
        }
    }
    cout << res;
    return 0;
}