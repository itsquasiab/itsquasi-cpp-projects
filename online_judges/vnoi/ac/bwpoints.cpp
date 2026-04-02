// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#define ll long long
#define task "bwpoints"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<pair<ll, bool>> pf;

bool cmp(pair<ll, bool> a, pair<ll, bool> b){
    return a.first < b.first;
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
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        pf.push_back({a, 0});
    }
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        pf.push_back({a, 1});
    }
    sort(pf.begin(), pf.end(), cmp);
    int cnt = 0;
    for (int i = 1; i < pf.size(); ++i){
        if (pf[i].second != pf[i - 1].second){
            cnt++;
            i++;
        }
    }
    cout << cnt;
    return 0;
}