// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#define ll long long
#define task "b"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> fac;
vector<pair<ll, int>> sub;

void create_factorial(){
    ll x = 1;
    fac.push_back(x);
    for (ll i = 2; i * x <= 1000000000000; ++i){
        x *= i;
        fac.push_back(x);
    }
}

void create_subset(){
    int m = fac.size();
    for (int mask = 0; mask < (1 << m); ++mask){
        ll sum = 0;
        int cnt = 0;
        for (int i = 0; i < m; ++i){
            if (mask & (1 << i)){
                sum += fac[i];
                ++cnt;
            }
        }
        sub.push_back({sum, cnt});
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    create_factorial();
    create_subset();
    int n;
    cin >> n;
    while (n--){
        ll x;
        cin >> x;
        int k = 60;
        for (auto [sum, cnt] : sub){
            if (sum > x) continue;
            k = min(k, cnt + __builtin_popcountll(x - sum));
        }
        cout << k << "\n";
    }
    return 0;
}