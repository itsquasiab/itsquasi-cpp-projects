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
    ll k, r;
    cin >> k >> r;
    for (int i = 1; ; ++i){
        ll d = ((i * k) % 10);
        if (d == 0 || d == r){
            cout << i;
            break;
        }
    }
    return 0;
}