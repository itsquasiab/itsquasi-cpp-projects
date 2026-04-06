// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task "table"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int n;
    cin >> n;
    int res = 1000, ri = 0, rj = 0;
    for (int i = 1; i <= 231; ++i){
        int l = 1, r = 231, j = 0;
        while (l <= r){
            int mid = (l + r) >> 1;
            if (i * mid >= n){
                j = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        if ((i + j) << 1 < res){
            res = (i + j) << 1;
            ri = i;
            rj = j;
        }
    }
    cout << ri << " " << rj;
    return 0;
}