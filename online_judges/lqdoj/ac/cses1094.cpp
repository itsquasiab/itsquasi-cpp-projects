//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll res = 0;
    for (int i = 2; i <= n; ++i){
        if (a[i] < a[i - 1]){
            res += a[i - 1] - a[i];
            a[i] = a[i - 1];
        }
    }
    cout << res;
    return 0;
}