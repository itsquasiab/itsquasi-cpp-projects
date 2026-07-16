// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#define ll long long
#define task "diffmax"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

void quicksort2(vector<ll>& a, int l, int r){
    int i = l;
    int j = r;
    int x = a[(i + j) >> 1];
    while (i <= j){
        while (a[i] < x) i++;
        while (a[j] > x) j--;
        if (i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j) quicksort2(a, l, j);
    if (i < r) quicksort2(a, i, r);
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
    vector<ll> a(n + 5);
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    ll s = -1e18, mn = a[1];
    for (int i = 2; i <= n; ++i){
        s = max(s, a[i] - mn);
        mn = min(mn, a[i]);
    }
    cout << s;
    return 0;
}