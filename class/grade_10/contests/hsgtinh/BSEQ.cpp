#include <bits/stdc++.h>
#define ll long long
#define tname "BSEQ"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int n;
ll a[arr];
bool prime[arr];

void sieve(){
    prime[1] = prime[0] = 1;
    for (int i = 2; i * i <= arr; ++i){
        if (!prime[i])
        for (int j = i * i; j < arr; j += i){
            prime[j] = 1;
        }
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    sieve();
    cin >> n;
    ll max_so_far = LLONG_MIN, max_current = LLONG_MIN;
    int first_prime = 0;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
        if (a[i] > 1 && !prime[a[i]] && max_so_far == LLONG_MIN){
            max_so_far = a[i];
            max_current = a[i];
            first_prime = i + 1;
        }
    }
    /*for (int i = 1; i <= n; ++i){
        if (a[i] > 1 && !prime[a[i]]) cout << a[i] << " is prime\n";
    }*/
    for (int i = first_prime; i <= n; ++i){
        if (a[i] > 1 && !prime[a[i]]){
            max_so_far = max(max_so_far + a[i], a[i]);
            max_current = max(max_current, max_so_far);
        }
        else {
            max_so_far += a[i];
        }
    }
    /*for (int i = 1; i < pos.size(); ++i){
        for (int j = 0; j < i; ++j){
            mx = max(mx, pf[pos[i]] - pf[pos[j] - 1]);
        }
    }*/
    if (max_current == LLONG_MIN) cout << "NO";
    else cout << max_current;
    return 0;
}
