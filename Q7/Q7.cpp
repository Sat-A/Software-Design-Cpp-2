#include <cmath>
#include <iostream>
#include "Q7.hpp"
using namespace std;

Coord::Coord(Coord & C) : x(C.x), y(C.y) {}
Coord::Coord(double x, double y) : x(x), y(y) {}
double Coord::getX() const { return x; }
double Coord::getY() const { return y; }

double Distance(Coord & c1, Coord & c2) {
    return sqrt(pow(c1.getX() - c2.getX(), 2) + pow(c1.getY() - c2.getY(), 2));
}

Map::Map(Map & M) {}
Map::Map(map<Coord, vector<Coord>>) {}

int main() {
    Coord c1(2, 2);
    Coord c2(3, 3);
    cout << Distance(c1, c2) << endl;
};
