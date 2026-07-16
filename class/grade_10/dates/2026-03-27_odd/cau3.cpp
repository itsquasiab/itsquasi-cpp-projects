// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "cau3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<ll, bool> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int m, n;
    cin >> m >> n;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        cnt[a] = 1;
    }
    cout << m - n << "\n";
    for (int i = 1; i <= m; ++i){
        if (!cnt[i]) cout << i << " ";
    }
    return 0;
}