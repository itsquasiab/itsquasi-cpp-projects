#include<iostream>
#define ll long long
#define task "diagame"

using namespace std;

const ll arr = 106;

int n, m;

ll a[arr][arr];
bool checked[arr][arr];

bool checkdag13(int i, int j){
    if (checked[i][j]){
        if (a[i][j] == 1 || a[i][j] == 3) return 0;
    }
    return 1;
}

bool checkdag23(int i, int j){
    if (checked[i][j]){
        if (a[i][j] == 2 || a[i][j] == 3) return 0;
    }
    return 1;
}

bool checkdag123(int i, int j){
    if (checked[i][j]){
        if (a[i][j] != 0) return 0;
    }
    return 1;
}


int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r")){
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    cin >> n >> m;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            cin >> a[i][j];
        }
    }
    ll sum = 0;
    for (int i = 1; i <= n; ++i){
        for (int j = 1; j <= m; ++j){
            if (a[i][j]==1
                &&checkdag13(i-1,j-1)
                &&checkdag23(i-1,j)
                &&checkdag23(i,j-1))
                sum++, checked[i][j] = 1;
            else if (a[i][j]==2
                &&checkdag13(i-1,j)
                &&checkdag23(i-1,j+1)
                &&checkdag13(i,j-1))
                sum++, checked[i][j] = 1;
            else if (a[i][j]==3
                &&checkdag13(i-1,j-1)
                &&checkdag123(i-1,j)
                &&checkdag23(i-1,j+1)
                &&checkdag123(i,j-1))
                sum+=2, checked[i][j] = 1;
            //cout << "at pos [" << i << "][" << j << "], sum is " << sum << "\n";
        }
    }
    cout << sum;
    return 0;
}
