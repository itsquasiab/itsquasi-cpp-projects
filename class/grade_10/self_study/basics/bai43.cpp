// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "bai43"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<bool> bin;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    ll n;
    cin >> n;
    while (n){
        bin.push_back(n & 1);
        n /= 2;
    }
    for (int i = bin.size() - 1; i >= 0; --i){
        cout << bin[i];
    }
    return 0;
}