//2025 = 45² = (20+25)² = 5²*9² = (1+2+3+4+5+6+7+8+9)² = 1³+2³+3³+4³+5³+6³+7³+8³+9³
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll prime(ll x){
    if (x == 2 || x == 3) return 1;
    if (x < 3 || x % 2 == 0 || x % 3 == 0) return 0;
    for (int i = 5; i * i <= x; i += 6){
        if (x % i == 0 || x % (i + 2) == 0) return 0;
    }
    return 1;
}

int main()
{
    /*if (fopen(".inp","r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }*/
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll a,b;
    cin >> a >> b;
    for (int i = a; i <= b; ++i){
        if (prime(i)) cout << i << '\n';
    }
    return 0;
}
