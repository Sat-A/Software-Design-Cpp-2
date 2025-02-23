#ifndef Q7_H
#define Q7_H

#include <iostream>
#include <map>
#include <vector>
#include <queue>
#include <limits>
#include <string>
#include <stack>

using namespace std;

/**
 * @class Map
 * @brief Represents a map with adjacency list and data for edges.
 */
class Map {
public:
    map<vector<char>, double> data;
    map<char, vector<pair<char, double>>> adjList; // Adjacency List

    Map(const Map &M);
    Map(map<vector<char>, double> m);

    void display() const;

    // Dijkstra's Algorithm for shortest path
    map<char, pair<double, char>> shortestPath(char start);

    // Get path from start to end using Dijkstra's data
    string getPath(map<char, pair<double, char>> &dijkstraData, char start, char end);
};

/**
 * @class Orders
 * @brief Represents a collection of orders.
 */
class Orders {
public:
    Orders();
    Orders(const Orders &O);
    Orders(map<char, int> m);

    void emplace(char c, int i);

    using iterator = map<char, int>::iterator;
    iterator begin();
    iterator end();

private:
    map<char, int> data;
};

// Generate random orders
Orders GenerateOrders(int n = 5);

// Display orders
void DisplayOrders(Orders M);

#endif // Q7_H