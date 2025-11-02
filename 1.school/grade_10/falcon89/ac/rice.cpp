//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7, base = 31;

int n;
ll a[24];
ll dp[arr], sum[arr], bit1[arr];

ll price(int pos, int cur){
    ll avg = sum[pos] / bit1[pos];
    if (avg < a[cur]){
        if (sum[pos] % bit1[pos] == 0) return a[cur] - avg;
        else return a[cur] - (avg + 1);
    }
    return avg - a[cur];
}

void bitconv(int n, int i){
    for (int bit = n - 1; bit >= 0; --bit)
        cout << ((i >> bit) & 1);
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int mask = 0; mask < (1 << n); ++mask){
        sum[mask] = 0;
        bit1[mask] = 0;
        int cur = mask; //current mask
        int pos = 1; //current pos in mask
        while (cur != 0){
            int bit = cur & 1; //check bit 1
            sum[mask] += bit * a[pos]; //sum
            bit1[mask] += bit; //bit1
            pos++;
            cur >>= 1;
        }
    }
    dp[0] = 0;
    for (int i = 1; i < (1 << n); ++i) dp[i] = LLONG_MAX;
    const int sizearr = n;
    for (int i = 0; i < (1 << n); ++i){
        //cout << "mask: ";
        //bitconv(n, i);
        //cout << '\n';
        for (int p = 0; p < n; ++p){
            if (((i >> p) & 1) == 0){
                int j = i | (1 << p);
                dp[j] = min(dp[j], dp[i] + price(j, p + 1));
                //cout << "dp[";
                //bitconv(n, j);
                //cout << "] = " << dp[j] << " | ";
            }
        }
        //cout << "\n";
    }
    //cout << "result: ";
    cout << dp[(1 << n) - 1] << '\n';
    return 0;
}