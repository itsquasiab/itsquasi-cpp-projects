//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll distinct(ll n){
    unordered_map<ll, bool> exist;
    while(n){
        if (exist[n % 10]) return 0;
        exist[n % 10] = 1;
        n /= 10;
    }
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    n++;
    while (!distinct(n)){
        n++;
    }
    cout << n;
    return 0;
}