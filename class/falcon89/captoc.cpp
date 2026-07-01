// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <unordered_set>
#define ll long long
#define task "captoc"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool check(int l, int n, const string& s) {
    if (l == 0) return true;
    unordered_set<ll> hashes;
    ll p = 131;
    ll power = 1;
    for (int i = 0; i < l - 1; ++i) power *= p;

    ll current_hash = 0;
    for (int i = 0; i < l; ++i) current_hash = current_hash * p + s[i];
    hashes.insert(current_hash);

    for (int i = 1; i <= n - l; ++i) {
        current_hash = (current_hash - s[i - 1] * power) * p + s[i + l - 1];
        if (hashes.count(current_hash)) return false;
        hashes.insert(current_hash);
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    string a;
    cin >> a;
    int left = 1, right = n, ans = n;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (check(mid, n, a)) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    cout << ans;
    return 0;
}