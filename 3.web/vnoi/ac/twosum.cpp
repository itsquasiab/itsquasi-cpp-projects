//Minding my own business. :)
//MΔDE BY ITSQUΔSI
//https://itsquasi23.github.io/
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr], pf[arr];

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        pf[i] = pf[i - 1] + a[i];
    }
    int res = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = i + 1; j <= n; ++j){
            ll sum = (pf[j] - pf[i - 1]);
            if (sum & 1) continue;
            sum /= 2;
            int l = i, r = j;
            while (l <= r){
                int mid = l + r >> 1;
                ll s1 = pf[j] - pf[mid];
                ll s2 = pf[mid] - pf[i - 1];
                if (s1 == sum && s2 == sum){
                    res = max(res, j - i + 1);
                    break;
                }
                else if(s1 < s2){
                    r = mid - 1;
                }
                else l = mid + 1;
            }
        }
    }
    cout << res;
    return 0;
}