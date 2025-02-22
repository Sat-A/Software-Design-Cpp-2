#include <iostream>
#include <vector>
using namespace std;

template <class T>
class Image
{
private:
    int height;
    int width;
    vector<vector<T>> v;

public:
    Image(int h, int w) : height(h), width(w), v(h, vector<T>(w)) {}

    T getPixel(int h, int w)
    {
        return v[h][w];
    }

    void setPixel(int h, int w, T c)
    {
        v[h][w] = c;
    }
};

int main()
{
    Image<double> I(10, 2);
    I.setPixel(5, 1, 65);
    I.setPixel(4, 0, 97);
    double p1 = I.getPixel(5, 1);
    double p2 = I.getPixel(4, 0);
    cout << "Pixel at (5,1): " << p1 << endl;
    cout << "Pixel at (4,0): " << p2 << endl;
}
