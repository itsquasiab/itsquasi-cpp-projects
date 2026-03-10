// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <unordered_map>
#define ll long long
#define task "dtksub"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

ll pw[arr], hsa[arr];

string a;
int n, k;

void make_hash(){
    pw[0] = 1;
    hsa[0] = 0;
    for (int i = 1; i <= n; ++i){
        pw[i] = (pw[i - 1] * base) % mod;
        hsa[i] = (hsa[i - 1] * base + (a[i] - '0' + 1)) % mod;
    }
}

ll get_hash(int i, int j){
    return (hsa[j] - hsa[i - 1] * pw[j - i + 1] + mod * mod) % mod;
}

bool check(int l){
    unordered_map<ll, int> cnt;
    for (int i = 1; i <= n - l + 1; ++i){
        ll h = get_hash(i, i + l - 1);
        cnt[h]++;
    }
    for (auto i : cnt){
        if (i.second >= k) return 1;
    }
    return 0;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> k;
    cin >> a;
    a = ' ' + a;
    make_hash();
    int l = 1, r = n, res = 0;
    while (l <= r){
        int mid = (l + r) >> 1;
        if (check(mid)){
            res = mid;
            l = mid + 1;
        }
        else r = mid - 1;
    }
    cout << res;
    return 0;
}