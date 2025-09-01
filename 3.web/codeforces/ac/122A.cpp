//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e4 + 6, mod = 1e9, inf = LLONG_MIN;

vector<ll> a;

bool check(ll n){
    ll t = 0;
    while(n){
        t = n % 10;
        if (t != 4 && t != 7) return 0;
        n /= 10;
    }
    return 1;
}

void sieve(){
    for (int i = 4; i <= arr; ++i){
        if (check(i)) a.push_back(i);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    if (check(n)) cout << "YES";
    else {
        sieve();
        for (auto i : a){
            if (n % i == 0){
                cout << "YES";
                return 0;
            }
        }
        cout << "NO";
    }
    return 0;
}