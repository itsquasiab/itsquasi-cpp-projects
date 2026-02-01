#include<iostream>
#include<vector>
#include<stack>
#include<unordered_map>
#include<cmath>
#include<climits>
#define ll long long
#define tname "security"

using namespace std;

const ll arr = 1e5 + 6, mod = 1e9 + 7;

vector<ll> node[arr];
stack<ll> st;
ll height[arr];
ll num[arr], low[arr];
int n, m, cnt = 0;
int d = 0;
vector<pair<ll, ll>> i_found_it;

void dfs(ll u){
    num[u] = low[u] = ++cnt;
    st.push(u);
    for (auto v : node[u]){
        if (num[v]){
            low[u] = min(low[u], num[v]);
        }
        else {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
    }
    if (num[u] == low[u]){
        d++;
        int tg;
        ll min_height = LLONG_MAX;
        unordered_map<ll, ll> cntcnt;
        do {
            tg = st.top();
            st.pop();
            low[tg] = num[tg] = -1;
            min_height = min(min_height, height[tg]);
            cntcnt[height[tg]]++;
        } while(tg != u);
        i_found_it.push_back({min_height,cntcnt[min_height]});
    }
}

int main(){
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(tname".inp","r")){
        freopen(tname".inp","r",stdin);
        freopen(tname".out","w",stdout);
    }
    cin >> n;
    for (int i = 1; i <= n; ++i){
        cin >> height[i];
    }
    cin >> m;
    for (int i = 1; i <= m; ++i){
        int u, v;
        cin >> u >> v;
        node[u].push_back(v);
    }
    for (int i = 1; i <= n; ++i){
        if (!num[i]){
            dfs(i);
        }
    }
    ll res = 0, stp = 0;
    for(auto i : i_found_it){
        res += i.first;
        stp += i.second;
    }
    cout << res << " " << stp;
    return 0;
}

