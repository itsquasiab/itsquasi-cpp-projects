// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "zeroseq"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<ll, int> fs;

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
    int res = 0;
    ll sum = 0;
    fs[0] = 0;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        sum += a;
        if (fs.count(sum)) res = max(res, i - fs[sum]);
        else fs[sum] = i;
    }
    if (res) cout << res;
    else cout << "-1 -1";
    return 0;
}