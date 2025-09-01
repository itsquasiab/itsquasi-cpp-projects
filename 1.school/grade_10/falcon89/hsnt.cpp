//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, inf = LLONG_MIN;

ll pre[arr];

void precom(){
    pre[1] = 1;
    for (int i = 2; i < arr; ++i){
        pre[i] = (pre[i - 1] * i) % mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    precom();
    int n;
    cin >> n;
    while(n--){
        ll a, b;
        cin >> a >> b;
        cout << (pre[a] / (pre[b] * pre[a - b]) % mod) % mod << "\n";
    }
    return 0;
}