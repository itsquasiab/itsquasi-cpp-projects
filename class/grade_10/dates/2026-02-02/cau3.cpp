#include <iostream>
#include <string>
#define ll long long
#define task "cau3"
#define mod 1000000007

using namespace std;

int rem(ll n){
    int cnt = 1;
    for (int i = 2; i * i <= n; ++i){
        if (n % i == 0){
            int e = 0;
            while (n % i == 0){
                n /= i;
                e++;
            }
            cnt *= (e + 1);
            cnt %= mod;
        }
    }
    if (n > 1) cnt *= 2;
    cnt %= mod;
    return cnt;
}

ll cnt = 1;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task".inp", "r")){
        freopen(task".inp", "r", stdin);
        freopen(task".out", "w", stdout);
    }
    int n;
    cin >> n;
    for (int i = 2; i <= n; ++i){
        cnt *= i;
    }
    cout << rem(cnt);
    return 0;
}