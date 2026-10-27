// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <climits>
#define ll long long
#define task "CEQU"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll extended_euclid(ll a, ll b, ll x, ll y){
    if (b == 0){
        x = 1;
        y = 0;
        return a;
    }
    ll q = a / b;
    ll r = a - b * q;
    ll x1 = 0, y1 = 0;
    ll d = extended_euclid(b, r, x1, y1);
    x = y1;
    y = x1 - q * y1;
    return d;
}

pair<ll, ll> diophantine_solution(ll a, ll b, ll c){
    ll x = 0, y = 0;
    ll d = extended_euclid(a, b, x, y);
    if (c % d != 0) return {LLONG_MAX, LLONG_MAX};
    x *= c / d;
    y *= c / d;
    if (a < 0) x = -x;
    if (b < 0) y = -y;
    return {x, y};
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i){
        ll a, b, c;
        cin >> a >> b >> c;
        cout << "Case " << i << ": ";
        auto x = diophantine_solution(a, b, c);
        if (x.first == LLONG_MAX && x.second == LLONG_MAX) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}