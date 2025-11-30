//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

struct kbc{
    ll df, pt;
    int pos;
} a[arr], b[arr];

bool cmp1(kbc a, kbc b){
    if (a.df == b.df){ 
        if (a.pt == b.pt) return a.pos < b.pos;
        return a.pt > b.pt;
    }
    return a.df > b.df;
}

bool cmp2(kbc a, kbc b){
    if (a.pt == b.pt){
        if (a.df == b.df) return a.pos < b.pos;
        return a.df > b.df;
    }
    return a.pt > b.pt;
}

unordered_map<int, bool> encounted;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].df;
        b[i].df = a[i].df;
        a[i].pos = b[i].pos = i;
    }
    for (int i = 1; i <= n; ++i){
        cin >> a[i].pt;
        b[i].pt = a[i].pt;
    }
    sort (a + 1, a + 1 + n, cmp1);
    sort (b + 1, b + 1 + n, cmp2);
    int id1 = 1, id2 = 1;
    for (int i = 1; i <= n; ++i){
        ll p;
        cin >> p;
        if (p == 0){
            while (id1 <= n && encounted[a[id1].pos]) id1++;
            cout << a[id1].pos << " ";
            encounted[a[id1].pos] = 1;
            id1++;
        }
        else {
            while (id2 <= n && encounted[b[id2].pos]) id2++;
            cout << b[id2].pos << " ";
            encounted[b[id2].pos] = 1;
            id2++;
        }
    }
    return 0;
}