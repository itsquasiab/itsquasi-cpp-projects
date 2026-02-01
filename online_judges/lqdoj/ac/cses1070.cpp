// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    if (n == 1){
        cout << 1;
        return 0;
    }
    if (n == 4){
        cout << "2 4 1 3";
        return 0;
    }
    if (n < 4){
        cout << "NO SOLUTION";
        return 0;
    }
    vector<ll> odds, evens;
    for (int i = n; i >= 1; --i){
        if (i & 1) odds.push_back(i);
        else evens.push_back(i);
    }
    for (auto i : evens) cout << i << " ";
    for (auto i : odds) cout << i << " ";
    return 0;
}