#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <stack>

using namespace std;

class Map {
public:
    map<vector<char>, double> data;
    map<char, vector<pair<char, double>>> adjList; // Adjacency List

    Map(const Map &M) : data(M.data), adjList(M.adjList) {}

    Map(map<vector<char>, double> m) : data(m) {
        for (const auto &pair : m) {
            char u = pair.first[0], v = pair.first[1];
            double weight = pair.second;
            adjList[u].push_back({v, weight});
            adjList[v].push_back({u, weight}); // Undirected graph
        }
    }

    void display() const {
        for (const auto &pair : data) {
            for (char c : pair.first) {
                cout << c << " ";
            }
            cout << ": " << pair.second << endl;
        }
    }

    // Dijkstra's Algorithm for shortest path
    map<char, pair<double, char>> shortestPath(char start) {
        map<char, double> distances;
        map<char, char> parent;
        
        for (const auto &node : adjList) {
            distances[node.first] = numeric_limits<double>::max();
        }
        distances[start] = 0;

        priority_queue<pair<double, char>, vector<pair<double, char>>, greater<>> pq;
        pq.push({0, start});

        while (!pq.empty()) {
            auto [currentDist, currentNode] = pq.top();
            pq.pop();

            for (auto &[neighbor, weight] : adjList[currentNode]) {
                double newDist = currentDist + weight;
                if (newDist < distances[neighbor]) {
                    distances[neighbor] = newDist;
                    parent[neighbor] = currentNode;
                    pq.push({newDist, neighbor});
                }
            }
        }

        map<char, pair<double, char>> result;
        for (const auto &[node, dist] : distances) {
            result[node] = {dist, parent[node]};
        }
        return result;
    }

    string getPath(map<char, pair<double, char>> &dijkstraData, char start, char end) {
        if (dijkstraData.find(end) == dijkstraData.end() || dijkstraData[end].first == numeric_limits<double>::max()) {
            return "No path found";
        }

        stack<char> pathStack;
        char node = end;
        while (node != start) {
            pathStack.push(node);
            node = dijkstraData[node].second;
        }
        pathStack.push(start);

        string path = "";
        while (!pathStack.empty()) {
            path += pathStack.top();
            pathStack.pop();
            if (!pathStack.empty()) path += ">";
        }
        return path;
    }
};

class Orders {
public:
    Orders() = default;
    Orders(const Orders &O) : data(O.data) {}
    Orders(map<char, int> m) : data(m) {}

    void emplace(char c, int i) {
        data.emplace(c, i);
    }

    using iterator = map<char, int>::iterator;
    iterator begin() {
        return data.begin();
    }
    iterator end() {
        return data.end();
    }

private:
    map<char, int> data;
};

Orders GenerateOrders(int n = 5) {
    Orders M;
    for (int i = 0; i < n; i++) {
        M.emplace(char(97 + rand() % 10), rand() % 2 + 1);
    }
    return M;
}

void DisplayOrders(Orders M) {
    Orders::iterator it;
    cout << "House \t Order" << endl;
    for (it = M.begin(); it != M.end(); ++it) {
        cout << it->first << "\t" << it->second << endl;
    }
}

int main() {
    // Initialise Map
    map<vector<char>, double> m = {
        {{'s', 'a'}, 0.1},
        {{'s', 'b'}, 0.2},
        {{'s', 'c'}, 0.5},
        {{'s', 'd'}, 1},
        {{'s', 'e'}, 0.7},
        {{'a', 'f'}, 0.2},
        {{'f', 'g'}, 0.9},
        {{'f', 'h'}, 0.4},
        {{'e', 'i'}, 0.2},
        {{'h', 'j'}, 0.8},
        {{'a', 'b'}, 0.3},
        {{'j', 'a'}, 0.5}
    };

    Map map1(m);
    Orders orders;
    orders = GenerateOrders(10);
    DisplayOrders(orders);

    // cout << "Map 1:" << endl;
    // map1.display();

    // Compute shortest paths from 's'
    char start = 's';
    map<char, pair<double, char>> shortestPaths = map1.shortestPath(start);

    // Simulate orders and find shortest paths
    cout << "\nShortest Paths from Store ('s') to Orders:\n";
    for (auto it = orders.begin(); it != orders.end(); ++it) {
        char destination = it->first;
        cout << "Order to " << destination << ": " << map1.getPath(shortestPaths, start, destination) << endl;
    }

    return 0;
};