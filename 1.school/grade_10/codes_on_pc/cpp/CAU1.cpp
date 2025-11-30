#include<bits/stdc++.h>
#define ll long long

using namespace std;

vector<ll> val;

void sieve(){
    for (int i = 1; (i * (i + 1)) / 2 <= 1e9; ++i){
        ll calc = (i * (i + 1)) / 2;
        val.push_back(calc);
    }
}

int main(){
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    sieve();
    ll n;
    cin >> n;
    ll cnt = 0;
    for (int i = 1; i <= n; ++i){
        ll a;
        cin >> a;
        int pos = lower_bound(val.begin(), val.end(), a) - val.begin();
        if (a == val[pos]) cnt++;
    }
    cout << cnt;
    return 0;
}

