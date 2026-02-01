//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int c1 = 0, c2 = 0, c3 = 0, c4 = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] == 1) c1++;
        else if (a[i] == 2) c2++;
        else if (a[i] == 3) c3++;
        else c4++;
    }
    int cnt = 0;
    cnt += c4;
    cnt += c3;
    c1 = max(0, c1 - c3);

    cnt += c2 / 2;
    if (c2 & 1){
        cnt += 1;
        c1 = max(0, c1 - 2);
    }
    if (c1 > 0){
        cnt += (c1 + 3) / 4;
    }
    cout << cnt;
    return 0;
}