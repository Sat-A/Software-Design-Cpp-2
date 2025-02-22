#include <vector>
#include <map>

class Coord {
public:
    Coord(Coord & C);
    Coord(double x, double y);
    double getX() const;
    double getY() const;
private:
    double x;
    double y;
};

double Distance(Coord & c1, Coord & c2);

class Map {
public:
    Map(Map & M);
    Map(std::map<Coord, std::vector<Coord>>);
};