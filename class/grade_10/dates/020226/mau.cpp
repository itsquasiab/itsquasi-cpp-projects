// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    ll n, m;
    cin >> n >> m;
    ll a[n + 5];
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    unordered_map<ll, ll> c;
    ll colors = 0;
    ll i = 1;
    ll mn = 1e18;
    for (int j = 1; j <= n; ++j){
        c[a[j]]++;
        if (c[a[j]] == 1) colors++;
        while (i <= n && c[a[i]] > 1){
            c[a[i]]--;
            i++;
        }
        if (colors == m){
            mn = min(mn, j - i + 1);
        }
    }
    cout << (mn == 1e18 ? 0 : mn);
    return 0;
}