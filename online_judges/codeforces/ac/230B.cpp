//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;

bool prime[ARR];

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 1; i * i < ARR; ++i){
        if (!prime[i]){
            for (int j = i * i; j < ARR; j += i){
                prime[j] = 1;
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        ll n1 = sqrt(n);
        if (n1 * n1 == n && !prime[n1]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}