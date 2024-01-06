#include <bits/stdc++.h>

using namespace std;

const int INF = numeric_limits<int>::max();

// Structure to represent a graph edge
struct Edge {
    int destination;
    int weight;
};

// Structure to represent a node in the graph
struct Node {
    int id;
    int distance;
    bool operator>(const Node& other) const {
        return distance > other.distance;
    }
};

// Dijkstra's algorithm function
void dijkstra(const vector<vector<Edge>>& graph, int start, vector<int>& distances, vector<int>& previous) {
    int n = graph.size();
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    distances.assign(n, INF);
    previous.assign(n, -1);

    distances[start] = 0;
    pq.push({start, 0});

    while (!pq.empty()) {
        Node current = pq.top();
        pq.pop();

        if (current.distance > distances[current.id]) {
            continue; // Skip if the distance is not the current best
        }

        for (const Edge& edge : graph[current.id]) {
            int new_distance = current.distance + edge.weight;

            if (new_distance < distances[edge.destination]) {
                distances[edge.destination] = new_distance;
                previous[edge.destination] = current.id;
                pq.push({edge.destination, new_distance});
            }
        }
    }
}

// Function to find the best path using Dijkstra's algorithm
vector<int> findBestPath(const vector<vector<Edge>>& graph, int start, int end) {
    vector<int> distances, previous;
    dijkstra(graph, start, distances, previous);

    vector<int> path;
    for (int at = end; at != -1; at = previous[at]) {
        path.push_back(at);
    }

    reverse(path.begin(), path.end());
    return path;
}

int main() {
    // Example usage
    int n = 5; // Number of nodes in the graph
    vector<vector<Edge>> graph(n);

    // Adding edges to the graph
    graph[0].push_back({1, 2});
    graph[0].push_back({2, 4});
    graph[1].push_back({2, 1});
    graph[1].push_back({3, 7});
    graph[2].push_back({3, 3});
    graph[2].push_back({4, 1});
    graph[3].push_back({4, 5});

    int startNode = 0;
    int endNode = 4;

    vector<int> bestPath = findBestPath(graph, startNode, endNode);

    cout << "Best Path from Node " << startNode << " to Node " << endNode << ": ";
    for (int node : bestPath) {
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
