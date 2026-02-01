//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll f[arr];
vector<ll> fib;

void sieve(){
    f[0] = 0;
    f[1] = 1;
    f[2] = 1;
    fib.push_back(0);
    fib.push_back(1);
    for (int i = 3; f[i - 1] + f[i - 2] <= 1e10; ++i){
        f[i] = f[i - 1] + f[i - 2];
        fib.push_back(f[i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    /*for (int i = 0; i < fib.size(); ++i){
        cout << fib[i] << " ";
    }*/
    int n;
    cin >> n;
    while(n--){
        ll a;
        cin >> a;
        int t = lower_bound(fib.begin(), fib.end(), a) - fib.begin();
        if (fib[t] == a) cout << "IsFibo\n";
        else cout << "IsNotFibo\n";
    }
    return 0;
}