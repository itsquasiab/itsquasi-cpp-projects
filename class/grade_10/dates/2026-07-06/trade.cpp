// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#define ll long long
#define task "trade"

using namespace std;

const ll arr = 5e5 + 6, mod = 1e9 + 7;

bool islands_with_store[arr];

struct trade
{
    int u, v;
    ll c;
} prj[arr];

ll parent[arr], sz[arr];

int n, m, k;

bool sorter(trade a, trade b){
    return a.c < b.c;
}

void subtask2(){
    if (k == 1){
        sort(prj + 1, prj + 1 + m);
        for (int i = 1; i <= n; ++i){
            parent[i] = i;
            sz[i] = 0;
        }
        for (int i = 1; i <= m; ++i){
            
        }
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
    cin >> n >> m >> k;
    for (int i = 1; i <= k; ++i){
        int x;
        cin >> x;
        islands_with_store[x] = 1;
    }
    for (int i = 1; i <= m; ++i){
        cin >> prj[i].u >> prj[i].v >> prj[i].c;
    }
    return 0;
}