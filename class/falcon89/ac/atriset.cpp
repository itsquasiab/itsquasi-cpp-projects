//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 2e6;

int n;
ll a[arr];

unordered_map<ll, ll> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    sort (a + 1, a + 1 + n);
    int s = 0;
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            if (cnt[2 * a[i] - a[j] + mod] != 0){
                sum = max(sum, a[i] + a[j] + 2 * a[i] - a[j]);
            }
            s += cnt[2 * a[i] - a[j] + mod];
        }
        cnt[a[i] + mod]++;
    }
    cout << s << "\n" << sum;
    return 0;
}