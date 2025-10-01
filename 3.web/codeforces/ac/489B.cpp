//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], b[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        cin >> b[i];
    }
    sort (a + 1, a + 1 + n);
    sort (b + 1, b + 1 + m);
    int i = 1, j = 1, res = 0;
    while (i <= n && j <= m){
        if (abs(a[i] - b[j]) <= 1){
            res++;
            i++;
            j++;
        }
        else if (a[i] < b[j]){
            i++;
        }
        else {
            j++;
        }
    }
    cout << res;
    return 0;
}