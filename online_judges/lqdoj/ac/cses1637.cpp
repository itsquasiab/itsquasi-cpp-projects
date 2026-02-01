//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

ll fndg(ll n){
    ll t = 0;
    while (n){
        t = max(t, n % 10);
        n /= 10;
    }
    return t;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    ll t = 0;
    while (n){
        t++;
        n -= fndg(n);
    }
    cout << t;
    return 0;
}