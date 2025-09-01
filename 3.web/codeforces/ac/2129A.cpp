//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll maxn = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;
int parsent[maxn] , sz[maxn] ;
vector<int> wm;
void make_set(int v)
{
    parsent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    return v == parsent[v] ? v : parsent[v] = find_set(parsent[v]);
}
void union_set(int a ,int b , int pos)
{
    a = find_set(a);
    b = find_set(b);
    if(a != b)
    {
        wm.push_back(pos);
        if(sz[a] < sz[b]) swap(a , b);
        sz[a] += sz[b];
        parsent[b] = a;
    }
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        for(int i = 1;i <= 2 * n ; ++i) make_set(i);
        
        for(int i = 1;i <= n; ++i){
            int u , v;
            cin >> u >> v;
            union_set(u , v , i);
        }
        cout << wm.size() << "\n";
        for(auto v : wm) cout << v << " " ;
        cout << "\n";
        wm.clear();
    }
    return 0;
}