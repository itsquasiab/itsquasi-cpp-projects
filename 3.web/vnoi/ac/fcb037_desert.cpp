#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll s, c;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     cin >> s >> c;
     ll t = 0;
     while (s--){
          ll a;
          cin >> a;
          t += a;
          if (t >= c){
               cout << "YES\n";
               return 0;
          }
     }
     cout << "NO\n";
     return 0;
}
