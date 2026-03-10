// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <algorithm>
#include <utility>
#define ll long long
#define task "paliny"

using namespace std;

const ll arr = 1e6 + 6, md1 = 1e9 + 7, md2 = 1e9 + 9, bs1 = 131, bs2 = 311;
string r, a;

ll hsa1[arr], hsr1[arr], pw1[arr];
ll hsa2[arr], hsr2[arr], pw2[arr];
int n;

void make_hash(){
    pw1[0] = pw2[0] = 1;
    for (int i = 1; i <= n; ++i){
        hsa1[i] = (hsa1[i - 1] * bs1 + (a[i] - 'a' + 1)) % md1;
        hsr1[i] = (hsr1[i - 1] * bs1 + (r[i] - 'a' + 1)) % md1;
        pw1[i] = (pw1[i - 1] * bs1) % md1;
        hsa2[i] = (hsa2[i - 1] * bs2 + (a[i] - 'a' + 1)) % md2;
        hsr2[i] = (hsr2[i - 1] * bs2 + (r[i] - 'a' + 1)) % md2;
        pw2[i] = (pw2[i - 1] * bs2) % md2;
    }
}

pair<ll, ll> get1(int i, int j){
    ll h1 = (hsa1[j] - hsa1[i - 1] * pw1[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hsa2[j] - hsa2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
    return {h1, h2};
}

pair<ll, ll> get2(int i, int j){
    ll h1 = (hsr1[j] - hsr1[i - 1] * pw1[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hsr2[j] - hsr2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
    return {h1, h2};
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> a;
    r = a;
    reverse(r.begin(), r.end());
    a = ' ' + a;
    r = ' ' + r;
    make_hash();
    int res = 1;
    for (int i = 1; i <= n; ++i){
        int l = 0, r = min(i - 1, n - i), k = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (get1(i - mid, i + mid) == get2(n - (i + mid) + 1, n - (i - mid) + 1)){
                k = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        res = max(res, 2 * k + 1);
    }
    for (int i = 1; i < n; ++i){
        int l = 1, r = min(i, n - i), k = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (get1(i - mid + 1, i + mid) == get2(n - (i + mid) + 1, n - (i - mid + 1) + 1)){
                k = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        res = max(res, 2 * k);
    }
    cout << res;
    return 0;
}