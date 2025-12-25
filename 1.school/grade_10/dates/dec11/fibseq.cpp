#include <iostream>
#include <vector>
#define ll long long
#define tname "fibseq"

using namespace std;

const ll arr = 10006, mod = 1e9 + 7;

int n, p, q, res = 0;
ll a[arr];
vector<ll> fib;

void pre(){
    fib.push_back(0);
    fib.push_back(1);
    ll t1 = fib[fib.size() - 1], t2 = fib[fib.size() - 2];
    while (t1 + t2 <= 1000000){
        fib.push_back(t1 + t2);
        t1 = fib[fib.size() - 1], t2 = fib[fib.size() - 2];
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    pre();
    cin >> n >> p >> q;
    for (int i = 1; i <= n; ++i) cin >> a[i], a[i] += a[i - 1];
    for (int i = q; i <= n; ++i){
        for (int j = i - q + 1; j <= i - p + 1; ++j){
            ll sum = a[i] - a[j - 1];
            int k = lower_bound(fib.begin(), fib.end(), sum) - fib.begin();
            if (fib[k] == sum) res++;
        }
    }
    cout << res;
    return 0;
}



