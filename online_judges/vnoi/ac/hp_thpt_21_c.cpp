// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <algorithm>
#define ll long long
#define task "hp_thpt_21_c"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

pair<ll, ll> a[arr];

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
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a + 1, a + 1 + n);
    int i = 1, j = n;
    while (i < j){
        if (a[i].first + a[j].first == 2 * k){
            cout << a[i].second << " " << a[j].second;
            exit(0);
        }
        else if (a[i].first + a[j].first > 2 * k) j--;
        else i++;
    }
    cout << 0;
    return 0;
}