// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "bdtlt"

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
    ll n;
    cin >> n;
    int cnt = 0;
    ll l = 1, r = 2;
    ll sum = l;
    ll res = 0;
    while (r < n){
        sum += r;
        while (sum > n){
            sum -= l;
            l++;            
        }
        if (sum == n) res++;
        r++;
    }
    cout << res;
    return 0;
}