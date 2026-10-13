// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long
#define task "1628"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll t[arr], x;
int n;
vector<int> a, b;

void tryxie(int i, ll sum){
    if (sum > x) return;
    if (i > n / 2) a.push_back(sum);
    else tryxie(i + 1, sum), tryxie(i + 1, sum + t[i]); 
}
void tyra(int i, ll sum){
    if (sum > x) return;
    if (i > n) b.push_back(sum);
    else tyra(i + 1, sum), tyra(i + 1, sum + t[i]); 
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> x;
    for (int i = 1; i <= n; ++i) cin >> t[i];
    tryxie (1, 0);
    tyra (n / 2 + 1, 0);
    sort (b.begin(), b.end());
    ll cnt = 0;
    for (ll sum : a) {
        cnt += upper_bound(b.begin(), b.end(), x - sum) - lower_bound(b.begin(), b.end(), x - sum);
    }
    cout << cnt;
    return 0;
}