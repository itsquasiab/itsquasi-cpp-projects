// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "xau10"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

string a;
int k;

ll p(bool x, int pos){
    if (!x) return pos % 2;
    return 1 - (pos % 2);
}

ll get(bool x){
    int l = 0, r = 0, ms = 0, res = 0;
    while (l < a.size() && r < a.size()){
        if (a[r] - '0' != p(x, r)) ms++;
        while (ms > k){
            if (a[l] != p(x, l)) ms--;
            l++;
        }
        res = max(res, r - l + 1);
        r++;
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> a >> k;
    cout << max(get(1), get(0));
    return 0;
}