//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll divs[arr];

void precom(){
    for (int i = 1; i <= arr; ++i){
        for (int j = i; j <= arr; j += i){
            divs[j]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    precom();
    ll l, r;
    cin >> l >> r;
    if (l > r){
        cout << 0;
        return 0;
    }
    ll sum = 0;
    for (int i = l; i <= r; ++i){
        sum += divs[i];
    }
    cout << sum;
    return 0;
}