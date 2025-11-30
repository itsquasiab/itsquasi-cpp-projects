//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];
vector<ll> p;

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
        if (!prime[i]) p.push_back(i);
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int n;
    cin >> n;
    cout << p[n - 1];
    return 0;
}