// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> a;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int q;
        cin >> q;
        if (q == 1){
            ll u;
            cin >> u;
            a.push_back(u);
        }
        else if (q == 2 && !a.empty()) a.pop_back();
        else if (q == 3 && !a.empty()) cout << *max_element(a.begin(), a.end()) << "\n";
    }
    return 0;
}