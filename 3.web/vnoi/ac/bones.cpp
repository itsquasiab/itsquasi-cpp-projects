// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    ll a, b, c;
    cin >> a >> b >> c;
    cnt.resize(a + b + c + 5, 0);
    for (int i = 1; i <= a; ++i){
        for (int j = 1; j <= b; ++j){
            for (int k = 1; k <= c; ++k){
                ll sum = i + j + k;
                cnt[sum]++;
            }
        }
    }
    ll x = 0, res = 0;
    for (int i = 3; i <= a + b + c; ++i){
        if (cnt[i] > x){
            x = cnt[i];
            res = i;
        }
    }
    cout << res;
    return 0;
}