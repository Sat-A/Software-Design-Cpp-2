#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class Map {
public:
    Map(const Map &M) : data(M.data) {}
    Map(map<vector<char>, double> m) : data(m) {}

    void display() const {
        for (const auto &pair : data) {
            for (char c : pair.first) {
                cout << c << " ";
            }
            cout << ": " << pair.second << endl;
        }
    }

private:
    map<vector<char>, double> data;
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

Orders GenerateOrders(int n = 3) {
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
        {{'j', 'a'}, 0.5},
        };

    Map map1(m);
    Orders orders;
    orders = GenerateOrders();
    DisplayOrders(orders);


    cout << "Map 1:" << endl;
    map1.display();

    return 0;
};