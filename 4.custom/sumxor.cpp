//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

ll sumxor(int n){
    ll sum = 0;
    for (int i = 0; i < n; ++i){
        int zc = 0, oc = 0;
        for (int j = 1; j <= n; ++j){
            if (a[j] & 1) oc++;
            else zc++;
            a[j] /= 2;
        }
        sum += oc * zc * (1 << i);
    }
    return sum;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    cout << sumxor(n);
    return 0;
}