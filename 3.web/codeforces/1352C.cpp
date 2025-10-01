//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll ts;
    cin >> ts;
    while (ts--){
    ll n, k;
    cin >> n >> k;
    cout << k + (k - 1) / (n - 1) << "\n";
    }
    return 0;
}