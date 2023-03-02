#pragma once
#include <bits/stdc++.h>

template <typename T>
class Dijkstra {
private:
    struct Node {
        int position;
        int parent;
    };
    int num_nodes_;
    std::vector<T> dist_;
    std::vector<bool> visited_;
    std::unordered_map<int, std::vector<std::pair<Node, T>>> edges_;

public:
    Dijkstra(int num_nodes) : num_nodes_(num_nodes) {
        dist_.resize(num_nodes_, std::numeric_limits<T>::max());
    }

    void AddEdge(int u, int v, T weight) {
        Node newNode;
        newNode.position = v;
        newNode.parent = -1;
        edges_[u].push_back({ newNode, weight });
    }

    std::vector<T> ShortestPath(int start) {
        std::priority_queue<std::pair<T, Node>, std::vector<std::pair<T, Node>>, std::greater<>> pq;
        dist_[start] = 0;
        Node startNode;
        startNode.position = 0;
        pq.push({ 0, startNode });

        while (!pq.empty()) {
            auto element = pq.top;
            T dist = element.first;
            Node u = element.second;
            pq.pop();

            if (visited_[u.position]) continue;
            visited_[u.position] = true;

            for (auto element : edges_[u]) {
                if (dist_[element.second.position] > dist + element.first) {
                    dist_[element.second.position] = dist + element.first;
                    pq.push({ dist_[element.second.position], element.second });
                }
            }
        }
        return dist_;
    }
};