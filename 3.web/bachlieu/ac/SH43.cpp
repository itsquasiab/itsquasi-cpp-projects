//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    ll tau = 1, omega = 0;
    for (ll i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            tau *= (e + 1);
            ++omega;
        }
    }
    if (n > 1) {
        tau *= 2;
        ++omega;
    }
    cout << tau - omega;
    return 0;
}