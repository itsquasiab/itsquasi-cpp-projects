// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define task "CPNT"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

ll prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i < arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
}

ll fastpow(ll x, ll y){
    ll res = 1;
    while (y){
        if (y & 1){
            res *= x;
        }
        x *= x;
        y /= 2;
    }
    return res;
}

ll sumdiv(ll n){
    ll res = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            res = res * ((fastpow(i, e + 1) - 1) / (i - 1));
        }
    }
    if (n > 1) res *= ((n * n - 1) / (n - 1));
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
    sieve();
    int n;
    cin >> n;
    while (n--){
        ll l, r;
        cin >> l >> r;
        ll l1 = sqrt(l);
        if (l1 * l1 < l) l1++;
        ll r1 = sqrt(r);
        ll cnt = 0, prd = 0;
        for (ll i = l1; i <= r1; ++i){
            cnt += i * i;
            if (!prime[sumdiv(i * i)]) prd++;
        }
        cout << cnt << " " << prd << "\n";
    }
    return 0;
}