// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
#define task "divseq"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll a;

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
    while (t--){
        unordered_map<ll, int> cnt;
        ll d;
        int n;
        cin >> d >> n;
        cnt[0] = 1;
        ll sum = 0, res = 0;
        for (int i = 1; i <= n; ++i){
            cin >> a;
            sum = (sum + a) % d;
            res += cnt[sum];
            cnt[sum]++;
        }
        cout << res;
    }
    return 0;
}