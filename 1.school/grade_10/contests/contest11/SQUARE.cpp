//Minding my own business. :)
//MADE BY ITSQUASI
#include <iostream>
#include <cmath>
#define ll long long
#define task "square"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n, k;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task".inp","r"))
    {
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    cin >> n >> k;
    if (k == 2){
        for (ll i = 1; i <= n; ++i){
            int tg1 = sqrt(i);
            if (tg1 * tg1 == i){
                ll j = n - i;
                int tg2 = sqrt(j);
                if (tg2 * tg2 == j){
                    cout << "YES\n";
                    cout << i << " " << j;
                    return 0;
                }
            }
        }
    }
    else if (k == 3){
        for (ll i = 1; i <= n; ++i){
            for (ll j = 1; j <= n - i; ++j){
                ll k = n - i - j;
                ll sum1 = i + j, sum2 = i + k, sum3 = j + k;
                ll s1 = sqrt(sum1), s2 = sqrt(sum2), s3 = sqrt(sum3);
                if (s1 * s1 == sum1 && s2 * s2 == sum2 && s3 * s3 == sum3){
                    cout << "YES\n";
                    cout << i << " " << j << " " << k;
                    return 0;
                }
            }
        }
    }
    cout << "NO";
    return 0;
}