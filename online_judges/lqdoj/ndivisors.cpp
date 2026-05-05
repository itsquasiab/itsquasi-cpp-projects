// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "ndivisors"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];
vector<ll> pr;

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i < arr; ++i){
        if (!prime[i]) pr.push_back(i);
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
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){

    }
    return 0;
}