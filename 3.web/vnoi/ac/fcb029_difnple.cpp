#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     ll a,b,c,d;
     cin >> a >> b >> c >> d;

     cout << (a+b > c+d? "Yes" : "No") << endl;
     return 0;
}
