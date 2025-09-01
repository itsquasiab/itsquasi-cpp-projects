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
    ll k;
    cin >> k;
    if (k % 2 == 0 || k % 5 == 0){
        cout << -1;
        return 0;
    }
    ll r = 1 % k, t = 1;
    while (r != 0){
        r = (r * 10 + 1) % k;
        t++;
    }
    cout << t;
    return 0;
}