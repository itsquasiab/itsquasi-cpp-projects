//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll ARR = 1e6 + 6, MOD = 1e9 + 9;
struct T
{
    ll l , r , ans , sum;
}tree[ARR*4];
ll a[ARR];
void build(int id ,int l ,int r)
{
    if(l == r)
    {
        tree[id] = {a[l],a[l],a[l],a[l]};
        return;
    }
    int mid =l + r >> 1;
    build(id << 1 , l,mid);
    build(id << 1 | 1 ,mid + 1 , r);
    tree[id].ans = max({tree[id << 1].ans , tree[id << 1 | 1].ans , tree[id << 1].r + tree[id << 1 | 1].l});
    tree[id].l = max(tree[id << 1].l , tree[id << 1|1].l + tree[id << 1].sum);
    tree[id].r = max(tree[id << 1 | 1].r , tree[id << 1].r + tree[id << 1 | 1].sum);
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}
void upd(int id ,int l ,int r ,int pos , ll val)
{
    if(pos < l || pos > r) return;
    if(l == r)
    {
        tree[id] = {val ,val ,val ,val};
        return ;
    }
    int mid = l + r >> 1;
    upd(id << 1 , l ,mid ,pos ,val);
    upd(id << 1 | 1 ,mid + 1 , r ,pos ,val);
       tree[id].ans = max({tree[id << 1].ans , tree[id << 1 | 1].ans , tree[id << 1].r + tree[id << 1 | 1].l});
    tree[id].l = max(tree[id << 1].l , tree[id << 1|1].l + tree[id << 1].sum);
    tree[id].r = max(tree[id << 1 | 1].r , tree[id << 1].r + tree[id << 1 | 1].sum);
    tree[id].sum = tree[id << 1].sum + tree[id << 1 | 1].sum;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    build(1 ,1 ,n);
    while(q--)
    {
        int u;
        ll v;
        cin >> u >> v;
        upd(1 ,1 ,n,u , v);
        cout << max(0LL,tree[1].ans) << "\n";
    }
    return 0;
}