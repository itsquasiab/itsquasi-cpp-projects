// Merry Christmas and Happy New Year!
// MADE BY ITSQUASI
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define ll long long
// #define task ""

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

int t;
ll n;

bool just_nine(string s){
    int cnt = 0;
    for (auto c : s){
        if (c == '9') cnt++;
    }
    return cnt == s.size();
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    /* if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    } */
    cin >> t;
    while (t--){
        string s;
        cin >> s;
        if (just_nine(s)){
            cout << 1 << string(s.size() - 1, '0') << 1 << "\n";
        }
        else {
            string mirror_left = s.substr(0, (s.size()) / 2);
            string mirror_right = mirror_left;
            reverse(mirror_right.begin(), mirror_right.end());
            string center;
            if (s.size() & 1) center = s[(s.size() + 1) / 2 - 1];
            string pal = mirror_left + center + mirror_right;
            if (pal > s) {
                cout << pal << "\n";
            }
            else {
                string t;
                if (s.size() & 1)
                    t = mirror_left + center;   // ví dụ: "123" từ "12321"
                else
                    t = mirror_left;            // ví dụ: "12" từ "1221"
                int i = t.size() - 1;
                while (i >= 0 && t[i] == '9') {
                    t[i] = '0';
                    i--;
                }
                if (i >= 0)
                    t[i]++;
                    
                if (s.size() & 1) {
                    mirror_left = t.substr(0, t.size() - 1);
                    center = t.back();
                } else {
                    mirror_left = t;
                    center = "";
                }

                mirror_right = mirror_left;
                reverse(mirror_right.begin(), mirror_right.end());

                string ans = mirror_left + center + mirror_right;
                cout << ans << "\n";
            }
        }
    }
    return 0;
}