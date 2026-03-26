// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "mink"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll st[4 * arr];
ll a[arr];

void build(int id, int l, int r){
    if (l == r){
        st[id] = a[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);
    st[id] = min(st[id << 1], st[id << 1 | 1]);
}

ll get(int id, int l, int r, int u, int v){
    if (r < u || v < l) return 1e18;
    if (u <= l && r <= v) return st[id];
    int mid = (l + r) >> 1;
    return min(get(id << 1, l, mid, u, v), get(id << 1 | 1, mid + 1, r, u, v));
}

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
        int n, k;
        cin >> n >> k;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        build(1, 1, n);
        for (int i = 1; i <= n - k + 1; ++i){
            cout << get(1, 1, n, i, i + k - 1) << " ";
        }
        cout << "\n";
    }
    return 0;
}