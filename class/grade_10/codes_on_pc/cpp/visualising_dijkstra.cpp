#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>

using namespace std;

// Constants
const ll MAX_NODES = 1e6 + 6;
const ll INF = LLONG_MAX;
const ll MOD = 1e9 + 7;

// Graph adjacency list: adjList[u] = vector of (v, weight)
vector<pii> adjList[MAX_NODES];

// Distance array: dist[u] = shortest distance from source to node u
ll dist[MAX_NODES];

// Number of nodes and edges
int numNodes, numEdges;

// Dijkstra's algorithm to find shortest paths from a source node
void dijkstra(int source) {
    // Min-heap priority queue storing (distance, node)
    priority_queue<pii, vector<pii>, greater<pii>> minHeap;

    // Initialize all distances as infinity
    for (int i = 1; i <= numNodes; ++i)
        dist[i] = INF;

    // Distance to the source is 0
    dist[source] = 0;
    minHeap.push({0, source});

    // Process nodes in increasing order of distance
    while (!minHeap.empty()) {
        ll currentDist = minHeap.top().first;
        int currentNode = minHeap.top().second;
        minHeap.pop();

        // Ignore if this is not the latest shortest distance
        if (currentDist != dist[currentNode])
            continue;

        // Relaxation step for all neighbors
        for (auto edge : adjList[currentNode]) {
            int neighbor = edge.first;
            ll weight = edge.second;

            if (dist[neighbor] > currentDist + weight) {
                dist[neighbor] = currentDist + weight;
                minHeap.push({dist[neighbor], neighbor});
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> numNodes >> numEdges;

    // Read edges
    for (int i = 1; i <= numEdges; ++i) {
        int from, to, weight;
        cin >> from >> to >> weight;
        adjList[from].push_back({to, weight});
    }

    // Run Dijkstra from node 1
    dijkstra(1);

    // Output shortest distances from node 1 to all others
    for (int i = 2; i <= numNodes; ++i) {
        // If unreachable, print 1e9 as per the problem's requirement
        cout << (dist[i] == INF ? 1000000000 : dist[i]) << " ";
    }

    return 0;
}
