#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll dvs(ll x){
     ll t = 0;
     for(ll i = 1; i <= sqrt(x); i++){
          if (x % i == 0){
               t++;
               if (x / i != i) t++;
          }
     }
     return t;
}

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     if (fopen ("Cau1.inp","r")){
     freopen("Cau1.inp","r",stdin);
     freopen("Cau1.out","w",stdout);}

     ll a,b;
     cin >> a >> b;
     cout << dvs(__gcd(a,b)) << endl;
     return 0;
}
