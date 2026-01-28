#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

ll num[10000008];

/*int tp(int x){
     int t = 0;
     while (x > 0){
          t += x%10;
          x /= 10;
     }
     return t;
}*/

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     /*int e = 0;
     for (int i = 1; i <= 10000007; i++){
          if (i % 2 == 0){
               if (tp(i) % 9 == 0){
                    e++;
                    num[e] = i;
               }
          }
     }*/

     ll s;
     cin >> s;

     cout << s * 18 << endl;
     return 0;
}
