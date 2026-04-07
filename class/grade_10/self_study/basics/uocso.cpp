// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "uocso"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll divs[arr];

void sieve(){
    for (int i = 1; i < arr; ++i){
        for (int j = i; j < arr; j += i){
            divs[j]++;
        }
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
    sieve();
    int n;
    cin >> n;
    while (n--){
        ll a;
        cin >> a;
        cout << divs[a] << "\n";
    }
    return 0;
}