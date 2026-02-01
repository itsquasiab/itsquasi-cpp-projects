//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

bool nearlucky(ll n){
    ll cnt = 0;
    while(n){
        ll t = n % 10;
        if (t == 4 || t == 7) cnt++;
        n /= 10;
    }
    return cnt == 4 || cnt == 7;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    cout << (nearlucky(n) ? "YES" : "NO");
    return 0;
}