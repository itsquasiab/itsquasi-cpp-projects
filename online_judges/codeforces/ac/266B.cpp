//Minding my own business. :)
//MADE BY ITSQUASI
#include <bits/stdc++.h>
#define ll long long
#define kien long long
#define FOR(i, a, b) for(int i = (a); i <= (b); i++); 

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9, inf = LLONG_MIN;

main()
{
    ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    string s;
    kien n, t;
    cin >> n >> t;
    cin >> s;
    for (int k = 1; k <= t; k++) {
        int m = s.size() - 1;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == 'B' and s[i + 1] == 'G') {
                swap(s[i], s[i + 1]);
                i++;
            }
        }
    }
    cout << s << "\n";
    return 0;
}