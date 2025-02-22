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
    Map map2(map1);

    cout << "Map 1:" << endl;
    map1.display();

    cout << "Map 2:" << endl;
    map2.display();

    return 0;
}