#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s, prime[arr] ,p[arr];

void sang()
{
     for (ll i = 0; i < arr; i++)
          prime[i] = 1;
     prime[0] = prime[1] = 0;
     for (ll i = 2; i < arr; i++)
          if (prime[i])
               for (ll j = i * i; j < arr; j += i)
                    prime[j] = 0;
}

int main()
{
     sang();
     ios_base::sync_with_stdio(NULL);
     cin.tie(0);
     cout.tie(0);
     vector<int>wm;
     for(int i = 1;i <= 1000000 ; ++i){
          if(prime[i])
          wm.push_back(i);
     }
     cin >> s;
     for (ll i = 1; i <= s; i++)
     {
          cin >> a[i];
          p[i] = p[i-1] + a[i];
     }
     ll res = INT_MIN , mn = INT_MAX ;
     for(int i = 0 ;i < wm.size() ; ++i){
          if(wm[i] > s) break;
          
               res = max(res , p[wm[i]] - mn);
          
          mn = min(mn , p[wm[i]-1]);

     }
     cout << res;
     return 0;
}
