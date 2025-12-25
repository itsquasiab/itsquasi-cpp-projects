#include <iostream>
#include <vector>
#define ll long long
#define ii pair<ll,ll>
#define tname "cdiv"

using namespace std;

const ll arr = 5e5 + 6, mod = 2024;

int n;
bool prime[arr];
vector<ll> p;
ll a[arr];

void sieve(){
    prime[0] = prime[1] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i]){
            for (int j = i * i; j < arr; j += i){
                prime[j] = 1;
            }
        }
    }
    for (int i = 2; i < arr; ++i){
        if (!prime[i]) p.push_back(i);
    }
}

ll num_divs(ll n){
    if (n == 1) return 1;
    ll res = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            ll cnt = 0;
            while (n % i == 0){
                n /= i;
                cnt++;
            }
            res *= cnt + 1;
            res %= mod;
        }
    }
    if (n > 1){
        res *= 2;
        res %= mod;
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    //sieve();
    cin >> n;
    ll t = 1;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        t = t * a[i];
    }
    //cout << t << " ";
    ll res = num_divs(t);
    cout << res;
    return 0;
}
