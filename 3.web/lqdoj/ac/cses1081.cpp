//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#define ll long long
#define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll mx = 0;
int cnt[arr];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /*if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }*/
    cin >> n;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        cnt[a]++;
        mx = max(mx, a);
    }
    for (int d = mx; d >= 1; d--){
        int total = 0;
        for (int j = d; j <= mx; j += d){
            total += cnt[j];
            if (total >= 2){
                cout << d;
                return 0;
            }
        }
    }
    cout << 0;
    return 0;
}