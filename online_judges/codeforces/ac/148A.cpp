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
    ll k, l, m, n, d;
    cin >> k >> l >> m >> n >> d;
    ll t = 0;
    for (int i = 1; i <= d; ++i){
        if (i % k == 0 || i % l == 0 || i % m == 0 || i % n == 0) t++;
    }
    cout << t;
    return 0;
}