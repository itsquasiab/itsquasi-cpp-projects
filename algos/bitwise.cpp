//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a, b;
    cin >> a >> b;
    ll res1 = a & b;
    ll res2 = a | b;
    ll res3 = a ^ b;
    cout << "AND: " << res1 << "\nOR: " << res2 << "\nXOR: " << res3 << "\n";
    return 0;
}