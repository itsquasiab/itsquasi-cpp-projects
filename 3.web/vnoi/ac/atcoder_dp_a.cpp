#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef const long long cll;
typedef pair<ll, ll> ii;

cll arr = 1e6 + 9;
ll a[arr], s, dp[arr];

int main()
{
     ios_base::sync_with_stdio(NULL);
     cin.tie(0);
     cout.tie(0);

     cin >> s;
     for (ll i = 1; i <= s; i++)
     {
          cin >> a[i];
     }
     ll res = 0;
     dp[2] = abs(a[2] - a[1]);
     for(int i = 3 ; i <= s; ++i){
          dp[i] = min(dp[i - 1] + abs(a[i-1]-a[i]), dp[i - 2] + abs(a[i-2] - a[i]));
     }
     cout << dp[s]; 
     return 0;
}
