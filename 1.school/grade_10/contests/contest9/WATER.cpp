//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

bool a[arr];
int n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("water.inp","r"))
    {
        freopen("water.inp", "r", stdin);
        freopen("water.out", "w", stdout);
    }
    cin >> n >> k;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    int len = 0;
    int total = 0;
    for (int i = 1, j = 1; j <= n; ++j){
        total += (a[j] == 0);
        while (total > k){
            if (a[i] == 0) total--;
            i++;
        }
        len = max(len, j - i + 1);
    }
    cout << len;
    return 0;
}