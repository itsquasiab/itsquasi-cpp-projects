// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a[arr];
bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (ll i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (ll j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    sieve();
    ll n;
    ll res = 0;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    ll pf = 0;
    for (int i = 1; i <= n; ++i){
        if (prime[a[i]] && a[i] > 0){
            pf++;
        }
        else {
            if (pf != 0) res += pf * (pf + 1) / 2;
            pf = 0;
        }
    }
    res += pf * (pf + 1) / 2;
    cout << res;
    return 0;
}