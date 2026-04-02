// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <string>
#include <utility>
#define ll long long
#define task "cau2a"

using namespace std;

const ll arr = 1e6 + 6, md1 = 1e9 + 7, md2 = 1e9 + 9, bs1 = 31, bs2 = 131;

ll hs[arr];
ll hs2[arr];
ll pw[arr], pw2[arr];
string s, r;
int n;

void make_hash(){
    pw[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i <= n; ++i){
        hs[i] = (hs[i - 1] * bs1 + (s[i] - 'a' + 1)) % md1;
        hs2[i] = (hs2[i - 1] * bs2 + (s[i] - 'a' + 1)) % md2;
        pw[i] = (pw[i - 1] * bs1) % md1;
        pw2[i] = (pw2[i - 1] * bs2) % md2;
    }
}

pair<ll, ll> get_hash(int i, int j){
    ll h1 = (hs[j] - hs[i - 1] * pw[j - i + 1] + md1 * md1) % md1;
    ll h2 = (hs2[j] - hs2[i - 1] * pw2[j - i + 1] + md2 * md2) % md2;
    return {h1, h2};
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> s;
    n = s.size();
    s = ' ' + s;
    make_hash();
    for (int i = 1; i <= n; ++i){
        string x = s.substr(1, i);
        ll hx1 = 0, hx2 = 0, xz = x.size();
        if (n % xz != 0) continue;
        for (int j = 0; j < xz; ++j){
            hx1 = (hx1 * bs1 + (x[j] - 'a' + 1)) % md1;
            hx2 = (hx2 * bs2 + (x[j] - 'a' + 1)) % md2;
        }
        bool valid = 1;
        for (int j = 1; j <= n; j += xz){
            pair<ll, ll> comp = get_hash(j, j + xz - 1);
            //cout << comp << " " << hx << "\n";
            if (hx1 == comp.first && hx2 == comp.second){
                valid = 1;
            }
            if (hx1 != comp.first || hx2 != comp.second) {
                valid = 0;
                break;
            }
        }
        if (valid == 1){
            cout << x;
            break;
        }
    }
    return 0;
}