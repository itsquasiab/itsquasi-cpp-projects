//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll t;
ll dp[arr];

void precom(){
    dp[1] = 1;
    for (ll i = 2; i < arr; ++i){
        ll last_day_present = i * (i + 1) / 2;
        dp[i] = last_day_present + dp[i - 1];
    }
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    precom();
    cin >> t;
    while (t--){
        ll n;
        cin >> n;
        cout << dp[n] << "\n";
    }
    return 0;
}