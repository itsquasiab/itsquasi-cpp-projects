// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <map>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        cnt[a]++;
    }
    for (auto i : cnt){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}