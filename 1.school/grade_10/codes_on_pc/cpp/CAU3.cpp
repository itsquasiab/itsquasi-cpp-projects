#include<bits/stdc++.h>
#define ll long long

using namespace std;

const int limit = 1e6 + 6;

ll divs[limit];
// if l, r <= 1e6
void sieve(){
    for (int i = 1; i <= limit; ++i){
        for (int j = i; j <= limit; j += i){
            divs[j]++;
        }
    }
}
// if l, r > 1e6
ll fastdivcnt(ll n){
    ll power = 1;
    for (int i = 2; i * i <= n; ++i){
        ll cnt = 0;
        if (n % i == 0){
            while (n % i == 0) n /= i, cnt++;
            power *= (cnt + 1);
        }
    }
    if (n > 1) power *= 2;
    return power;
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    ll  l, r, k;
    cin >> l >> r >> k;
    ll cnt = 0;
    for (int i = l; i <= r; ++i){
        if (i >= 1e6 && fastdivcnt(i) == k) cnt++;
        else if (i < 1e6 && divs[i] == k) cnt++;
    }
    cout << cnt;
    return 0;
}

