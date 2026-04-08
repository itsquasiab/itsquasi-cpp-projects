// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "bai37"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

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
    ll divisible_by_3 = 0;
    ll bigger_than_10 = 0;
    ll from_10_to_500 = 0;
    ll biggest_number = -1e18;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        if (a % 3 == 0) divisible_by_3++;
        if (a > 10) bigger_than_10++;
        if (a >= 10 && a <= 500) from_10_to_500++;
        biggest_number = max(biggest_number, a);
        cnt[a]++;
    }
    cout << divisible_by_3 << "\n" << bigger_than_10 << "\n" << from_10_to_500 << "\n" << cnt[biggest_number];
    return 0;
}