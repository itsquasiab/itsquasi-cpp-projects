//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll findlargestdigit(ll n){
    ll t = 0;
    while (n){
        t = max(t, n % 10);
        n /= 10;
    }
    return t;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    int t = 0;
    while (n){
        n -= findlargestdigit(n);
        t++;
    }
    cout << t;
    return 0;
}