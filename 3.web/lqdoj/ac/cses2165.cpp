// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

void hanoi(ll n, ll from, ll mid, ll to){
    if(n == 1){
        cout << from << " " << to << '\n';
        return;
    }
    hanoi(n-1, from, to, mid);
    cout << from << " " << to << '\n';
    hanoi(n-1, mid, from, to);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    } */
    ll n;
    cin >> n;
    cout << ((1 << n) - 1) << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}