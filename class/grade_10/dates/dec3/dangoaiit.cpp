#include<bits/stdc++.h>
#define ll long long
#define fname "dangoaiit"

using namespace std;

const ll arr = 306, mod = 1e9 + 7;

int n, k;
string s;

string str_grp[15];

char get_majority(char a, char b, char c) {
    int A = (a=='A') + (b=='A') + (c=='A');
    return (A >= 2 ? 'A' : 'B');
}

string reduce_string(const string &s) {
    string res = "";
    for (int i = 0; i < (int)s.size(); i += 3) {
        res.push_back(get_majority(s[i], s[i+1], s[i+2]));
    }
    return res;
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(fname".inp","r")){
        freopen(fname".inp","r",stdin);
        freopen(fname".out","w",stdout);
    }
    cin >> n >> k >> s;
    str_grp[0] = s;
    for (int i = 1; i <= n; ++i) {
        str_grp[i] = reduce_string(str_grp[i-1]);
    }
    while (k--){
        int p;
        cin >> p;
        p--;
        str_grp[0][p] = (str_grp[0][p]=='A' ? 'B' : 'A');
        int idx = p;
        int t = n;
        string res = s;
        for (int level = 1; level <= n; ++level) {
            int parent = idx / 3;

            // Lấy 3 con ở level-1
            char c1 = str_grp[level-1][3*parent];
            char c2 = str_grp[level-1][3*parent + 1];
            char c3 = str_grp[level-1][3*parent + 2];

            // cập nhật parent
            str_grp[level][parent] = get_majority(c1, c2, c3);

            idx = parent;
        }
        cout << str_grp[n][0] << "\n";
    }
}
