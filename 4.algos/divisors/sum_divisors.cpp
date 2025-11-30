//Goal: Get into CLC
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

ll sum_div(ll n){
    if (n == 1) return 1;
    ll d = 1;
    for (int i = 2; i * i <= n; ++i)
    {
        int c = 0;
        while (n % i == 0)
            c++, n /= i;
        d *= (fastpow(i,c + 1) - 1) / (i - 1);
    }
    if (n > 1) d *= (n * n - 1) / (n - 1);
    return d;
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll n;
    cin >> n;
    cout << sum_div(n);
    return 0;
}