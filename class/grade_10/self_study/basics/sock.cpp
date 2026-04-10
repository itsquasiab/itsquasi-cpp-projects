// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "sock"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
unordered_map<ll, int> cnt;

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
    while (n--){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    ll sum = 0;
    for (auto i : cnt){
        sum += i.second / 2;
    }
    cout << sum;
    return 0;
}