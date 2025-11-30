#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;
bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        ll tg = sqrt(a);
        if (tg * tg == a && !prime[tg]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
