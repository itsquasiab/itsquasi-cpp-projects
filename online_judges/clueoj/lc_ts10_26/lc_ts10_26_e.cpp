// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "lc_ts10_26_e"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool a[arr];

bool checkpalin(ll n){
    if (n < 10) return 1;
    ll t = 0, n2 = n;
    while (n > 0){
        t = t * 10 + (n % 10);
        n /= 10;
    }
    return t == n2;
}

unordered_map<ll, int> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        ll s;
        cin >> s;
        if (checkpalin(s)) a[i] = 1;
    }
    cnt[0] = 1;
    ll sum = 0, res = 0;
    for (int r = 1; r <= n; ++r){
        sum += a[r];
        res += cnt[sum - k];
        cnt[sum]++;
    }
    cout << res;
    return 0;
}