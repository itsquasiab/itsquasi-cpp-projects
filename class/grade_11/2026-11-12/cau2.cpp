#include <bits/stdc++.h>
#define ll long long
#define task "cau2"

using namespace std;

const ll arr = 1e6 + 6, mod = 1e9 + 7;

vector<string> palins;

string b1;

bool check_palin(string x){
    int n = x.size();
    x = ' ' + x;
    for (int i = 1; i <= n / 2; ++i){
        if (x[i] != x[n - i + 1]) return 0;
    }
    return 1;
}

int main(){
    //   level   abc  121   noon
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    int t;
    string s;
    cin >> t;
    cin.ignore();
    getline(cin, s);
    stringstream ss(s);
    string x;
    while (ss >> x){
        b1 += x + " ";
        if (check_palin(x)) palins.push_back(x);
    }
    if (t == 1){
        cout << b1 << "\n" << palins.size();
    }
    else {
        if (palins.empty()){
            cout << "NONE";
        }
        else {
            string p = "";
            for (auto i : palins){
                p += i;
            }
            string pr = p;
            reverse(pr.begin(), pr.end());
            for (int i = 0; i < p.size(); ++i){
                cout << p[i] << pr[i];
            }
        }
    }
    return 0;
}

