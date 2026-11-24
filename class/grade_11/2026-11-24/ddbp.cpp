// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "ddbp"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];

deque<int> mn, mx;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll d;
    cin >> n >> d;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    int l = 1, r = 1;
    ll res = 0;
    while (r <= n){
        while (!mn.empty() && a[mn.back()] >= a[r]) mn.pop_back();
        mn.push_back(r);
        while (!mx.empty() && a[mx.back()] <= a[r]) mx.pop_back();
        mx.push_back(r);
        while (a[mx.front()] - a[mn.front()] > d){
            if (!mn.empty() && mn.front() == l) mn.pop_front();
            if (!mx.empty() && mx.front() == l) mx.pop_front();
            l++;
        }
        res += (r - l + 1);
        r++;
    }
    cout << res;
    return 0;
}