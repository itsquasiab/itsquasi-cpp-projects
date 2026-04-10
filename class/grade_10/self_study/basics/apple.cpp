// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "apple"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int s, t, a, b, m, n;
    cin >> s >> t >> a >> b >> m >> n;
    ll dis_a = (a - s);
    ll dis_b = (b - t);
    ll cnt_a = 0;
    ll cnt_b = 0;
    while (m--){
        ll a1;
        cin >> a1;
        if (a1 <= dis_a) cnt_a++;
    }
    while (n--){
        ll a2;
        cin >> a2;
        if (a2 >= dis_b) cnt_b++;
    }
    cout << cnt_a << "\n" << cnt_b;
    return 0;
}