// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "seqbal"

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
bool a[arr];
unordered_map<ll, int> cnt;
int res = 0;
ll pf = 0;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1; i <= n; ++i){
        if (a[i] == 0) pf--;
        else pf++;
        if (cnt.count(pf)){
            res = max(res, i - cnt[pf]);
        }
        else cnt[pf] = i;
    }
    cout << res;
    return 0;
}