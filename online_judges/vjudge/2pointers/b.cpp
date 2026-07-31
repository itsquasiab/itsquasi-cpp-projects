// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <utility>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 5006, mod = 1e9 + 7;

pair<ll, int> a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    ll x;
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    int pos1, pos2, pos3;
    bool found = 0;
    sort (a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        int l = i + 1, r = n;
        ll target = x - a[i].first;
        while (l < r){
            if (a[l].first + a[r].first == target){
                cout << a[i].second << " " << a[l].second << " " << a[r].second;
                return 0;
            }
            else if (a[l].first + a[r].first < target){
                l++;
            }
            else r--;
        }
    }
    cout << "IMPOSSIBLE";
    return 0;
}