// Minding my own business. :)
// MADE BY ITSQUASI
#include <iostream>
#include <vector>
#include <utility>
#define ll long long
#define task "graph"

using namespace std;

const ll arr = 1006, mod = 1e9 + 7;

bool graph[arr][arr];
int n, k;
vector<pair<int, int>> check;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    if (fopen(task ".inp", "r"))
    {
        freopen(task ".inp", "r", stdin);
        freopen(task ".out", "w", stdout);
    }
    string s;
    int any_u = 1, any_v = 1;
    while (cin >> s){
        if (s == "NEW"){
            cin >> n >> k;
            for (int u = 1; u <= n; ++u){
                fill(graph[u] + 1, graph[u] + 1 + n, k);
            }
            if (k){
                any_u = 1;
                any_v = 1;
            }
        }
        else if (s == "ADD"){
            int u, v;
            cin >> u >> v;
            graph[u][v] = 1;
            if (u < any_u || (u == any_u && v < any_v)){
                any_u = u;
                any_v = v;
            }
        }
        else if (s == "DEL"){
            int u, v;
            cin >> u >> v;
            graph[u][v] = 0;
        }
        else if (s == "ANY"){
            bool found = 0;
            while (any_u <= n){
                while (any_v <= n){
                    if (graph[any_u][any_v] == 1){
                        graph[any_u][any_v] = 0;
                        cout << any_u << " " << any_v << "\n";
                        found = 1;
                        break;
                    }
                    any_v++;
                }
                if (found) break;
                any_u++;
                any_v = 0;
            }
            if (!found) cout << "-1\n";
        }
        else if (s == "EDG"){
            int u, v;
            cin >> u >> v;
            if (graph[u][v]) cout << "YES\n";
            else cout << "NO\n";
        }
        else if (s == "END") break;
    }
    return 0;
}