// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "nkseq"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll a[arr];
ll pf[arr];

deque<int> minval;

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
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i + n] = a[i];
    for (int i = 1; i <= 2 * n; ++i) pf[i] = pf[i - 1] + a[i];
    for (int i = 1; i <= n; ++i){
        while (!minval.empty() && pf[minval.back()] >= pf[i]) minval.pop_back();
        minval.push_back(i);
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        while (!minval.empty() && minval.front() < i) minval.pop_front();
        ll current = pf[minval.front()];
        if (current - pf[i - 1] > 0) res++;
        while (!minval.empty() && pf[minval.back()] >= pf[i + n]) minval.pop_back();
        minval.push_back(i + n);
    }
    cout << res << "\n";
    return 0;
}