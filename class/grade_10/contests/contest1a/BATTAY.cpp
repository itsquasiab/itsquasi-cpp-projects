#include<bits/stdc++.h>
#define ll long long

using namespace std;

const ll arr = 2e5 + 6;
struct kien{
    int x, y;
    char d;
} a[arr];

bool sorter(kien a, kien b){
    if (a.y == b.y) return a.x < b.x;
    return a.y < b.y;
}

vector<ll> clap_l, clap_r;
int go_r = 0, go_l = 0;
bool there_is_r = 0;

ll get_answer(ll res){
    for (int l = 0; l < clap_l.size(); ++l){
        for (int l2 = l + 1; l2 < clap_l.size(); ++l2){
            clap_l[l] += clap_l[l2];
        }
    }
    ll sumtotal = 0;
    for (int r = 0; r < clap_r.size(); ++r){
        sumtotal += clap_l[r] * clap_r[r];
        //cout << clap_r[r] << " " << clap_l[r] << "\n";
    }
    res += sumtotal * 3;
    clap_l.clear();
    clap_r.clear();
    go_r = 0;
    go_l = 0;
    there_is_r = 0;
    return res;
}

int main(){
    if (fopen("BATTAY.inp","r")){
        freopen("BATTAY.inp","r",stdin);
        freopen("BATTAY.out","w",stdout);
    }
    ios_base::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> a[i].x >> a[i].y;
    }
    string arg;
    cin >> arg;
    arg = " " + arg;
    for (int i = 1; i <= n; ++i){
        a[i].d = arg[i];
    }
    sort (a + 1, a + 1 + n, sorter);

    ll res = 0;

    int i = 1;

    while (i <= n){
        if (a[i].d == 'R'){
            while (a[i].d == 'R'){
                go_r++;
                i++;
            }
            there_is_r = 1;
        }
        else if (a[i].d == 'L' && there_is_r == 1){
            while (a[i].d == 'L'){
                go_l++;
                i++;
            }
            clap_l.push_back(go_l);
            clap_r.push_back(go_r);
            go_r = 0;
            go_l = 0;
        }
    }
    res += get_answer(res);
    cout << res;
}
