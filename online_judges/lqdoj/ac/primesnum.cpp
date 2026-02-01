// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 10'000'007, mod = 1'000'000'007;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
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
    ll a, b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i){
        if (!prime[i]) cout << i << "\n";
    }
    return 0;
}