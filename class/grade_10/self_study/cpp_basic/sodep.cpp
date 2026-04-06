// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "sodep"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll dv[arr];
bool pr[arr];

void divs(ll n){
    for (int i = 1; i <= n; ++i){
        for (int j = i; j <= n; j += i){
            dv[j]++;
        }
    }
}

void primes(){
    pr[0] = pr[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!pr[i]){
            for (int j = i * i; j < arr; j += i){
                pr[j] = 1;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    primes();
    int n;
    cin >> n;
    divs(n);
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        if (!pr[dv[i]]) cnt++;
    }
    cout << cnt;
    return 0;
}