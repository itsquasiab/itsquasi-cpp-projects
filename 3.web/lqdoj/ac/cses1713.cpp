//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll n;
ll divs[arr];

void sieve(){
    for (int i = 1; i < arr; ++i){
        for (int j = i; j < arr; j += i) divs[j]++;
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    sieve();
    int t;
    cin >> t;
    while (t--){
        cin >> n;
        cout << divs[n] << "\n";
    }
    return 0;
}