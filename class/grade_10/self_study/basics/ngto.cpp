// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#define ll long long
#define task "ngto"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<pair<ll, ll>> res;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
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
    sieve();
    int n;
    cin >> n;
    for (int i = 1; i << 1 <= n; ++i){
        if (i != n - i && !prime[i] && !prime[n - i]) res.push_back({i, n - i});
    }
    cout << res.size() << "\n";
    for (auto c : res){
        cout << c.first << " " << c.second << "\n";
    }
    return 0;
}