// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#define ll long long
#define task "xaucon"

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
    int n;
    ll k;
    string a;
    cin >> n >> k >> a;
    int l = 0;
    ll sum = 0, cnt = 0;
    for (int r = 0; r < n; ++r){
        sum += int(a[r]);
        while (sum >= k){
            cnt += (n - r);
            sum -= int(a[l]);
            l++;
        }
    }
    cout << cnt;
    return 0;
}