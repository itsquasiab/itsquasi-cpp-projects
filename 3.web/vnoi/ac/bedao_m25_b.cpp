//2025 = 45² = (20+25)² = 5²*9² = (1+2+3+4+5+6+7+8+9)² = 1³+2³+3³+4³+5³+6³+7³+8³+9³
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll n,a,b,c;

ll l(ll x, ll y){
    if (x == -1 || y == -1) return -1;
    ll g = __gcd(x,y);
    if (x / g > n / y) return -1;
    return (x / g) * y;
}

ll solve(ll n, ll k){
    if (k == -1) return 0;
    if (n % k != 0) return 0;

    ll n1 = n / k, res = 0;
    for (ll i = 1; i * i <= n1; ++i){
        res += 2 * (n1 % i == 0) - (i * i == n1);
    }
    return res;
}

int main()
{
    /*if (fopen(".inp","r"))
    {
        freopen(".inp", "r", stdin);
        freopen(".out", "w", stdout);
    }*/
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> a >> b >> c;
    ll l1 = l(a,b), l2 = l(b,c), l3 = l(c,a), l4 = l(l(a,b),c);
    ll res = solve(n,l1) + solve(n,l2) + solve(n,l3) - 2 * solve(n,l4);
    cout << res;
    return 0;
}
