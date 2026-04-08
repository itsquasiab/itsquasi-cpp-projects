// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "bai40"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool primes[arr];

void sieve(){
    primes[0] = primes[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!primes[i])
        for (int j = i * i; j < arr; j += i){
            primes[j] = 1;
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
    int n;
    cin >> n;
    vector<int> p;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        if (!primes[a]) p.push_back(i);
    }
    cout << p.size() << "\n";
    for (int i : p){
        cout << i << "\n";
    }
    return 0;
}