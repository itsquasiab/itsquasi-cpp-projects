// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "twins"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];
ll sumprime[arr];
ll countprime[arr];

int rv(int x){
    int t = 0;
    while (x){
        t = t * 10 + (x % 10);
        x /= 10;
    }
    return t;
}

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        for (int j = i * i; j < arr; j += i) prime[j] = 1;
    }
    for (int i = 2; i < arr; ++i){
        sumprime[i] = sumprime[i - 1];
        countprime[i] = countprime[i - 1];
        if (!prime[i]){
            sumprime[i] += i;
            int j = rv(i);
            if (i != j && !prime[j]) countprime[i]++;
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
    sieve();
    int t;
    cin >> t;
    while (t--){
        ll a, b;
        cin >> a >> b;
        cout << sumprime[b] - sumprime[a - 1] << " " << countprime[b] - countprime[a - 1] << "\n";
    }
    return 0;
}