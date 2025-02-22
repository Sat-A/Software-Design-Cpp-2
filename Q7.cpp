#include <cmath>
#include <iostream>
using namespace std;

class Coord{
    public:
        Coord(Coord & C) : x(C.x), y(C.y) {};
        Coord(double x, double y): x(x), y(y) {};
        double getX() const {return x;}
        double getY() const {return y;}
    private:
        double x;
        double y;
};

double Distance(Coord & c1, Coord & c2){
    return sqrt(pow(c1.getX() - c2.getX(), 2) + pow(c1.getY() - c2.getY(), 2));
};

int main() {
    Coord c1(2, 2);
    Coord c2(3, 3);
    cout << Distance(c1, c2) << endl;

}