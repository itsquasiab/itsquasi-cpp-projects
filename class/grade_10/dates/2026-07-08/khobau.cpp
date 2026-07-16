// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "khobau"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

ll k[arr];

vector<ll> nodes[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s; cin >> s;
    cout << "Hello " << s << "\n";
    return 0;
}