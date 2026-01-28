#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> ii;

int main() {
     ios_base::sync_with_stdio(NULL);
     cin.tie(0); cout.tie(0);

     char c;
     cin >> c;

     cout << (c == 'z' ? 'a' : char(c+1)) << endl;
     return 0;
}
