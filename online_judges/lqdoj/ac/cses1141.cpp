// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_map>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1'000'006, mod = 1'000'000'007;

int n;
ll a[arr];
int mx = 0;
unordered_map<ll, int> cnt;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    for (int i = 1, j = 1; j <= n; ++j){
        cnt[a[j]]++;
        while (cnt[a[j]] > 1){
            cnt[a[i]]--;
            i++;
        }
        mx = max(mx, j - i + 1);
    }
    cout << mx;
    return 0;
}