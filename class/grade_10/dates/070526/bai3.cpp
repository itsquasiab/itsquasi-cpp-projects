// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bai3"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
}

// in case the number is too large:
bool check_prime(ll n){
    if (n == 2 || n == 3) return 1;
    if (n < 2 || n % 2 == 0 || n % 3 == 0) return 0;
    for (int i = 5; i * i <= n; i += 6){
        if (n % i == 0 || n % (i + 2) == 0) return 0;
    }
    return 1;
}

bool check_super_prime(ll n){
    ll tmp = 0, t = 0;
    while (n){
        tmp = n % 10;
        if (prime[tmp]) return 0;
        t += tmp;
        n /= 10;
    }
    if (prime[t]) return 0;
    return 1;
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
    ll a, b;
    cin >> a >> b;
    for (ll i = a; i <= b; ++i){
        if (check_super_prime(i)){
            // testcase 1
            if (i <= 1000000){
                if (!prime[i]) cout << i << " ";
            }
            // testcase 2
            else if (i > 1000000){
                if (check_prime(i)) cout << i << " ";
            }
        }
    }
    return 0;
}