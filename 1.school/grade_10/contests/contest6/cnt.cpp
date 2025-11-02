//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("cnt.inp","r"))
    {
        freopen("cnt.inp", "r", stdin);
        freopen("cnt.out", "w", stdout);
    }
    ll n, s;
    cin >> n >> s;
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        //pref[i] = pref[i - 1] + a[i];
    }
    ll res = 0;
    for (int i = 1; i <= n; ++i){
        ll sum = 0;
        for (int j = i; j <= n; ++j){
            sum += a[j];
            if (abs(sum) > s){
                res++;
            }
        }
    }
    /*for (int i = 1; i <= n; ++i){
        ll 
    }*/
    cout << res;
    return 0;
}