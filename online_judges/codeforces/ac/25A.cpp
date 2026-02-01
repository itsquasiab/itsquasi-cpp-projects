//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    ll a[n + 1];
    ll odd = 0, even = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] & 1) odd++;
        else even++;
    }
    ll t = 1, pos;
    if (even > odd) t = 2;
    if (even < odd) t = 1;
    for (int i = 1; i <= n; ++i){
        if ((t % 2 == 1 && a[i] % 2 == 0) || (t % 2 == 0 && a[i] % 2 == 1)){
            pos = i;
            break;
        }
    }
    cout << pos;
    return 0;
}