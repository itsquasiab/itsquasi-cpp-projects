#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a, res = 1;
     cin >> a;

     for (ll i = 2; i <= 31; i++){
          ll b = pow(a, 1.0 / i);
          if (pow(b,i) <= a){ res = max(res, (ll)pow(b,i)); }
          if (pow(b + 1,i) <= a){ res = max(res, (ll)pow(b + 1,i)); }
     }

     cout << res << endl;
     return 0;
}