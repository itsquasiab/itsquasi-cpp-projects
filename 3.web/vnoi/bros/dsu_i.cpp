//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;
int n , m ,parsent[arr] , sz[arr] , res = 0;
void make_set(int v)
{
    parsent[v] = v;
    sz[v] = 1;
}
int find_set(int v)
{
    if(v == parsent[v]) return v;
    res++;
    return parsent[v] = find_set(parsent[v]);
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1;i <= n; ++i) make_set(i);
    while(m--)
    {
        int type ;
        cin >> type ;
        res = 0;
        if(type == 1)
        {
            int a , b;
            cin >> a >> b;
            a = find_set(a); b = find_set(b);
            if(a != b)
            {
                if(sz[a] < sz[b]) swap(a , b);
                sz[a] += sz[b];
                parsent[b] = a;
            }
        }else 
        {
            int u ;
            cin >> u;
            u = find_set(u);
            cout << res << '\n';
        }
    }   
    return 0;
}