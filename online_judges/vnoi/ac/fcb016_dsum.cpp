#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a, t = 0;
     cin >> a;
     while(a > 0){
          t += a%10;
          a /= 10;
     }
     cout << t << endl;
     return 0;
}
