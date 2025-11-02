//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i) prime[j] = 1;
        }
    }
}

bool checkpalin(ll n){
    string num = to_string(n);
    for (int i = 0; i <= num.size() / 2; ++i){
        if (num[i] != num[num.size() - 1 - i]) return 0;
    }
    return 1;
}

bool sumofprime(ll n){
    ll t = 0;
    while (n){
        t += n % 10;
        n /= 10;
    }
    return !prime[t];
}

/*string num;
ll dp[20][20][2]; //dp[pos][sum][flag]

ll solver(int pos, int sum, bool flag){
    if (pos == num.size()){
        return (!prime[sum]);
    }
    if (dp[pos][sum][flag] != -1) return dp[pos][sum][flag];
    int limit = flag ? (num[pos] - '0') : 9;
    ll res = 0;
    for (int d = 0; d <= limit; ++d){
        bool new_flag = flag && (d == limit);
        res += solver(pos + 1, sum + d, new_flag);
    }
    return dp[pos][sum][flag] = res;
}

ll cnt(ll n){
    num = to_string(n);
    memset(dp, -1, sizeof(dp));
    return solver(0, 0, 1);
}*/

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("PALINPRIME.inp","r"))
    {
        freopen("PALINPRIME.inp", "r", stdin);
        freopen("PALINPRIME.out", "w", stdout);
    }
    sieve();
    ll l, r;
    cin >> l >> r;
    ll res = 0;
    for (int i = l; i <= r; ++i){
        if (checkpalin(i) && sumofprime(i)){
            //cout << i << " ";
            res++;
        }
    }
    cout << res;
    return 0;
}