// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "816B"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll pf[arr], cnt[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k, q;
    cin >> n >> k >> q;
    while (n--){
        int a, b;
        cin >> a >> b;
        pf[a]++;
        pf[b + 1]--;
    }
    for (int i = 1; i < arr; ++i){
        pf[i] += pf[i - 1];
        cnt[i] += cnt[i - 1];
        if (pf[i] >= k) cnt[i]++;
    }
    while (q--){
        int a, b;
        cin >> a >> b;
        cout << cnt[b] - cnt[a - 1] << "\n";
    }
    return 0;
}