#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9;

ll a, b;

void sub12(){
    int64_t sum = a;
    for (int i = a + 1; i <= b; ++i){
        sum = sum / __gcd(sum, i * 1ll) * i;
    }
    string x = to_string(sum);
    ll res = 0;
    for (int i = x.size() - 1; i >= 0; --i){
        if (x[i] == '0') res++;
        else break;
    }
    //cout << x << "\n";
    cout << res;
}

ll tinh(int x){
    ll s = 1;
    ll k = 0;
    while (s * x <= b)
{
k++;
s = s *x;}
while (b / s * s < a){
s = s / x;
k--;}
return k;
}

void sub3(){
    cout << min(tinh(2), tinh(5));
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen("zeros.inp","r")){
        freopen("zeros.inp","r",stdin);
        freopen("zeros.out","w",stdout);
    }
    cin >> a >> b;
    //sub12();
    //cout << "\n";
    sub3();
    return 0;
}
