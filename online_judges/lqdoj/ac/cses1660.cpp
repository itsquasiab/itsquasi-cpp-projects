// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
ll x, a[arr];
unordered_map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n >> x;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cnt[0] = 1;
    ll s = 0;
    int res = 0;
    for (int i = 1; i <= n; ++i){
        s = s + a[i];
        res += cnt[s - x];
        cnt[s]++;
    }
    cout << res;
    return 0;
}