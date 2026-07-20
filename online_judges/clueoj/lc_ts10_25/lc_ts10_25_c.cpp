//Goal: Get into CLC
//MΔDE BY ITSQUΔSI
#include <bits/stdc++.h>
#define ll long long

using namespace std;
ll gcd(ll a, ll b) {
    while (b != 0) {
        ll r = a % b;
        a = b;
        b = r;
    }
    return a;
}
int main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    ll c,d;
    cin >> c >> d;
    ll res = LLONG_MAX ;
    bool f = 0;
    for(ll i = 1 ;i * i <= d ; ++i){

        if(d % i ==0)
        {
            ll a1 = c*i , b1 = d/i , a2 = c * (d/i) , b2 = i;
            ll x1 = i,y1 = b1/c , x2 = d/i , y2 = b2/c;
          
            if(b1%c==0&&gcd(x1,y1) == 1) res = min(res , a1+b1) , f = 1;
            if(i%c==0 && gcd(x2,y2) == 1) res = min(res , a2 +b2) , f  = 1;
        }
    }
    if(f)
    cout << res;
    else cout << -1;
    return 0;
}
