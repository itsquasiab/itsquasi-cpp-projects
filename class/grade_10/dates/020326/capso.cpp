// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "capso"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n;
ll m;
ll a[arr], c = 0;
unordered_map<ll, int> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    /*sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        ll target = m - a[i];
        int j = (upper_bound(a + i + 1, a + 1 + n, target) - a) - (lower_bound(a + i + 1, a + 1 + n, target) - a);
        c += j;
    }*/
    /*for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (a[i] + a[j] == m) c++;
        }
    }*/
    //cnt[0] = 1;
    for (int i = 1; i <= n; ++i){
        c += cnt[m - a[i]];
        cnt[a[i]]++;
    }
    cout << c;
    return 0;
}