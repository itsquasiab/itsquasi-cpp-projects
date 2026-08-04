// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <queue>
#define ll long long
#define task "1526C1"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
priority_queue<ll, vector<ll>, greater<ll>> min_heap;

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
    ll mx = 0;
    for (int i = 1; i <= n; ++i){
        mx += a[i];
        min_heap.push(a[i]);
        if (mx < 0){
            mx -= min_heap.top();
            min_heap.pop();
        }
    }
    cout << min_heap.size();
    return 0;
}