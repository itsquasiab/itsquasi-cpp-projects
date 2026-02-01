//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a, b;

ll t(int x){
    ll s = 1;
    ll k = 0;
    while (s * x <= b){
        ++k;
        s *= x;
    }
    while (b / s * s < a){
        s /= x;
        --k;
    }
    return k;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> a >> b;
    cout << min(t(2), t(5));
    return 0;
}