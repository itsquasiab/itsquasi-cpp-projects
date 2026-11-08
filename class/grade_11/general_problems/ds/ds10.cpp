// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "ds10"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

ll cnt(int k, int n){
    deque<int> mx, mn;
    int l = 1;
    ll total = 0;
    for (int r = 1; r <= n; ++r){
        while (mx.size() && a[mx.back()] <= a[r]) mx.pop_back();
        mx.push_back(r);
        while (mn.size() && a[mn.back()] >= a[r]) mn.pop_back();
        mn.push_back(r);
        while (a[mx.front()] - a[mn.front()] > k){
            if (mx.front() == l) mx.pop_front();
            if (mn.front() == l) mn.pop_front();
            l++;
        }
        total += (r - l + 1);
    }
    return total;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll k;
    cin >> n >> k;
    ll res = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    if (k == 0) cout << cnt(0, n);
    else cout << cnt(k, n) - cnt(k - 1, n);
    return 0;
}