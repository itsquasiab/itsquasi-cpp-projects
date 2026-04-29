// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
#define task "lixi"

using namespace std;

const ll arr = 104, mod = 1e9 + 7;

vector<pair<ll, ll>> profit, none;

bool sorter(pair<ll, ll> a, pair<ll, ll> b){
    return a.first > b.first;
}

ll dp[arr][arr];

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
        ll a, b;
        cin >> a >> b;
        if (b > 0){
            profit.push_back({a, b});
        }
        else none.push_back({a, b});
    }
    sort(profit.begin(), profit.end(), sorter);
    sort(none.begin(), none.end(), sorter);
    ll a1 = 0, b1 = 1;
    for (auto i : profit){
        a1 += i.first;
        b1 += i.second - 1;
    }
    // from this point it will be like choosing the most value while b[i] = 0
    //cout << a1 << " ";
    for (auto i : none){
        a1 += i.first;
        //cout << i.first << " ";
        b1--;
        if (b1 <= 0) break;
    }
    cout << a1;
    return 0;
}