//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n, k, l, c, d, p, nl, np;
    cin >> n >> k >> l >> c >> d >> p >> nl >> np;
    ll limes = c * d;
    ll drink = k * l / nl;
    ll salt = p / np;
    cout << min({limes, drink, salt}) / n;
    return 0;
}