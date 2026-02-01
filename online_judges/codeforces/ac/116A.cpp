//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll mx = 0, tram = 0;
    for (int i = 1; i <= n; ++i){
        ll a, b;
        cin >> a >> b;
        tram = tram - a + b;
        mx = max(mx, tram);
    }
    cout << mx;
    return 0;
}