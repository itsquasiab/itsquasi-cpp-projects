// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
vector<pair<ll, int>> events;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll a, b;
        cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }
    sort (events.begin(), events.end());
    ll res = 0, sum = 0;
    for (auto i : events){
        sum += i.second;
        res = max(res, sum);
    }
    cout << res;
    return 0;
}