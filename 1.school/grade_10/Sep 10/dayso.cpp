//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

ll a[arr];
int n;

void nv1(){
    bool f = 1;
    for (int i = 1; i <= n; ++i){
        if (a[i] != a[n - i + 1]) f = 0;
    }
    cout << (f ? "Yes\n" : "No\n");
}

bool special(ll x){
    ll t = 1;
    if (x <= 1) return 0;
    for (int i = 2; i * i <= x; ++i){
        if (x % i == 0){
            t += i;
            if (x / i != i) t += x / i;
        }
    }
    return t == x;
}

void nv2(){
    bool f = 0;
    for (int i = 1; i <= n; ++i){
        if (special(a[i])) cout << a[i] << " ", f = 1;
    }
    if (!f) cout << 0;
    cout << "\n";
}

void nv3(){
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; ++i){
        cout << a[i] << " ";
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i];
    }
    nv1();
    nv2();
    nv3();
    return 0;
}