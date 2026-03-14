#include <iostream>
#include <string>
#include <map>
#include <sstream>
#define ll long long
#define task "cau2"

using namespace std;

map<ll, int> cnt;

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    getline(cin, s);
    stringstream ss(s);
    string x;
    while (ss >> x){
        cnt[x.size()]++;
    }
    cout << cnt.size() << "\n";
    for (auto i : cnt){
        cout << i.first << " " << i.second << "\n";
    }
    return 0;
}
