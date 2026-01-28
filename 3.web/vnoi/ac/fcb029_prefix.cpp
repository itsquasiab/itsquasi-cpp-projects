#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     string a,b;
     
     cin >> a >> b;

     for (ll i = 0; i < a.size(); i++){
          if (a[i] == b[i]) continue;
          else{
               cout << "No\n";
               return 0;
          }
     }

     cout << "Yes" << endl;
     return 0;
}
