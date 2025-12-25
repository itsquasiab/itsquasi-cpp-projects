//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <utility>
#define ll long long
#define task "packages"

using namespace std;

const ll arr = 2e5 + 6, mod = 1e9 + 7;

int t, n;
ll q, a[arr];
pair<ll, int> st[4 * arr];

void update(int id, int l, int r, int i, ll val){
    if (i < l || r < i) return;
    if (l == r){
        st[id].first = val;
        st[id].second = i;
        return;
    }
    int mid = (l + r) >> 1;
    update(id << 1, l, mid, i, val);
    update(id << 1 | 1, mid + 1, r, i, val);
    st[id] = max(st[id << 1], st[id << 1 | 1]); 
}

pair<ll, int> get(int id, int l, int r, int u, int v, ll cmp){
    if (v < l || r < u) return {0, 0};
    if (st[id].first < cmp) return {0, 0};
    if (l == r) return st[id];
    int mid = (l + r) >> 1;
    pair<ll, int> left_res = get(id << 1, l, mid, u, v, cmp);
    if (left_res.first >= cmp) return left_res;
    return get(id << 1 | 1, mid + 1, r, u, v, cmp);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> t;
    while (t--){
        cin >> n >> q;
        for (int i = 1; i <= n; ++i){
            cin >> a[i];
        }
        for (int i = 1; i <= 4 * n; ++i){
            st[i] = {0, 0};
        }
        int cnt = 0;
        for (int i = 1; i <= n; ++i){
            pair<ll, int> u = get(1, 1, n, 1, cnt, a[i]);
            ll val = u.first;
            int pos = u.second;
            if (val < a[i]) cnt++, pos = cnt, val = q - a[i];
            else {
                val -= a[i];
            }
            update(1, 1, n, pos, val);
        }
        cout << cnt << "\n";
    }
    return 0;
}