#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

int n, t;
string s;

struct{
    char l, r;
    ll d;
}st[arr * 4];

void build(int id, int l, int r){
    if (l == r){
        st[id].l = s[l];
        st[id].r = s[r];
        st[id].d = 0;
        return;
    }
    int mid = l + r >> 1;
    build(id << 1, l, mid);
    build(id << 1 | 1, mid + 1, r);

}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> t >> s;
    return 0;
}
