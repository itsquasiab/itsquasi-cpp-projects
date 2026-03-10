// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <utility>
#include <vector>
#define ll long long
#define task "xepmaso"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int partition(vector<pair<ll, ll>>& a, int l, int r){
    pair<ll, ll> pivot = a[r];
    int i = l - 1;
    for (int j = l; j <= r - 1; ++j){
        if (a[j].second > pivot.second || a[j].second == pivot.second && a[j].first < pivot.first) {
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[i + 1], a[r]);
    return i + 1;
}

void quicksort(vector<pair<ll, ll>>& a, int l, int r){
    if (l < r){
        int p = partition(a, l, r);
        quicksort(a, l, p - 1);
        quicksort(a, p + 1, r);
    }
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
    vector<pair<ll, ll>> a(n + 5);
    for (int i = 1; i <= n; ++i){
        cin >> a[i].first >> a[i].second;
    }
    quicksort(a, 1, n);
    for (int i = 1; i <= n; ++i){
        cout << a[i].first << " " << a[i].second << "\n";
    }
    return 0;
}