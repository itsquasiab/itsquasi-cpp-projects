// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <cmath>
#include <utility>
#include <vector>
#define ll long long
#define task "slime"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<pair<ll, int>> range; //range<pos, diff>

//vector<pair<ll, int>> range; // range<pos, index>: to create a range, 2 points need to have the same index
//vector<pair<ll, int>> diff; // diff<pos, diff>

/*bool sorter(slime a, slime b){
    return a.pos < b.pos;
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    ll x, a, b, c, t;
    cin >> n >> k >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a >> b >> c >> t;
        long double day_size_valid = ceil(x * 1.0 / a) + t; // the day when size is equal or larger than x
        long double day_reached_max = ceil(c * 1.0 / a) + t; // the day when slime reached the maximum size
        long double max_size_reached = ceil(c * 1.0 / a) * a; // the maximum size the slime reached
        long double day_last_size_valid = floor((max_size_reached - x) * 1.0 / b) + day_reached_max; // the last day when the slime's size is still valid after reduction
        //cout << day_size_valid << " " << day_reached_max << " " << max_size_reached << " " << day_last_size_valid << "\n";
        range.push_back({day_size_valid, 1});
        range.push_back({day_last_size_valid, -1});
    }
    sort(range.begin(), range.end());
    ll current_layers = 0;
    ll res = 0;
    ll prev_pos = 0;
    for (int i = 0; i < range.size(); ++i){
        //cout << range[i].first << " " << range[i].second << "\n";
        if (current_layers >= k){
            res += (range[i].first - prev_pos);
        }
        prev_pos = range[i].first;
        current_layers += range[i].second;
    }
    cout << res + 1;
    return 0;
}