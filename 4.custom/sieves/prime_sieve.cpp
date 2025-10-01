//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2e7 + 6, mod = 1e9, inf = LLONG_MIN;

bool prime[arr];

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= arr; j += i) prime[j] = 1;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    int t;
    cin >> t;
    if (!prime[t]) cout << t << " is prime.\n";
    else cout << t << " is not prime.\n";
    return 0;
}