//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll parent[arr], sz[arr], ans;
pair<int,pair<int,int>> a[arr];
void make_set(ll p){
    parent[p] = p;
    sz[p] = 1;
}

ll find_set(ll p){
    return p == parent[p] ? parent[p] : parent[p] = find_set(parent[p]);
}

void union_set(ll a, ll b , ll x){
    a = find_set(a);
    b = find_set(b);
    if (a != b){
        ans = x;
        if (sz[a] < sz[b]) swap(a, b);
        parent[b] = a;
        sz[a] += sz[b];
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    if (fopen("TAITRONG.inp","r"))
        {
            freopen("TAITRONG.inp", "r", stdin);
            freopen("TAITRONG.out", "w", stdout);
        }
    int m, n, s, t;
    cin >> n >> m >> s >> t;
    for (int i = 1; i <= n; ++i) make_set(i);
    for(int i = 1;i <=m ;++i) cin >> a[i].second.first >> a[i].second.second >> a[i].first;
    sort(a + 1 ,a + m + 1);
    for(int i = m;i >= 1; --i)
    {
        union_set(a[i].second.first , a[i].second.second , a[i].first);
        if(find_set(s) == find_set(t)) break;
    }
    cout << ans ;
    return 0;
}