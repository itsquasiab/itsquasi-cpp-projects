#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll rv(ll x){
     ll t = 0;
     while (x > 0){
          t = t * 10 + x%10;
          x/=10;
     }
     return t;
}

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a,b,t = 0;
     cin >> a >> b;
     for (ll i = a; i <= b; i++){
          if (__gcd(i, rv(i)) == 1) t++;
     }
     cout << t << endl;
     return 0;
}
