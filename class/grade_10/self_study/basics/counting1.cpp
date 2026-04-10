// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "counting1"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

unordered_map<ll, int> cnt;
ll a[arr];

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
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < 100; ++i){
        cout << cnt[i] << " ";
    }
    return 0;
}