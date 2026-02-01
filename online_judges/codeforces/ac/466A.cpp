//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, m, a, b;
    cin >> n >> m >> a >> b;
    long double mcost = b * 1.0 / m;
    //cout << mcost << " ";
    ll cost = 0;
    if (mcost < a){
        cost += (n / m) * b;
        n = n % m;
        if (b > n * a) cost += n * a;
        else cost += b;
        //cout << b << " " << n * a << "\n";
        cout << cost;
    }
    else{
        cout << n * a;
    }
    return 0;
}