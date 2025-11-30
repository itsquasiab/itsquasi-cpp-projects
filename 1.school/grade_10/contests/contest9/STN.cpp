//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n;
ll divs[arr];
ll pf[arr];

void sieve(){
    for (int i = 1; i < arr; ++i){
        for (int j = i; j < arr; j += i){
            divs[j] += i;
        }
    }
    for (int i = 1; i < arr; ++i){
        pf[i] = pf[i - 1] + (i * 2 <= divs[i]);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("stn.inp","r"))
    {
        freopen("stn.inp", "r", stdin);
        freopen("stn.out", "w", stdout);
    }
    sieve();
    cin >> n;
    for (int i = 1; i <= n; ++i){
        int l, r;
        cin >> l >> r;
        cout << pf[r] - pf[l - 1] << "\n";
    }
    return 0;
}