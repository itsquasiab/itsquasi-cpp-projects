#include <bits/stdc++.h>
using namespace std;
#define maxn 1000005
#define ll long long 
#define fi first
#define se second
#define mod 1000000007
#define inf 100000000000000
int parsent[maxn] , sz[maxn] , n , m;
ll cow[maxn] , off[maxn];
void make_set(int v)
{
    parsent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if(v == parsent[v]) return v;
    int p = parsent[v];
    parsent[v] = find_set(p);
    off[v] += off[p];
    return parsent[v];
}
void union_set(int a ,int b)
{
    a = find_set(a); b = find_set(b);
    if(a != b)
    {
        if(sz[a] < sz[b]) swap(a , b);
        parsent[b] = a;
        sz[a] += sz[b];
        off[b] = cow[b] - cow[a];
    }
}
void add(int v , ll x)
{
    v = find_set(v);
    cow[v] += x;
    
}
ll get(int v)
{
    int r = find_set(v);
    return off[v] + cow[r];
}
int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; ++i) make_set(i);
    while(m--)
    {
        string s;
        int l , r;
        cin >> s >> l;
        if(s != "get") cin >> r;
        if(s == "join") union_set(l , r);
        else if(s == "add") add(l , r);
        else cout << get(l) << "\n";
    }
    return 0;
}