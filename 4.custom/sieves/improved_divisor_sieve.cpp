//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

bool prime[arr];

void sieve(){
    prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j <= arr; j += i) if (!prime[j]) prime[j] = i;
        }
    }
    for (int i = 1; i <= arr; ++i){
        if (!prime[i]) prime[i] = i;
    }
}

void pt(int n){
    while (n > 1){
        int p = prime[n];
        cout << p << " ";
        n /= p;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    pt(n);
    return 0;
}