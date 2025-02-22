#include <cmath>
using namespace std;
class Func{
    public:
        Func(const Func & F) {};
        virtual double Value(double x) const{};
        virtual bool HasDerivative() const{};
        virtual double Derivative(double x) const{};

};

class Expoverx2: Func{
    public:
        double Value(double x) const {
            return exp(x)/(x * x);
        };
        bool HasDerivative() const {return true;}
        double Derivative(double x) const {
            return exp(x)/(x * x) - 2*exp(x)/(x * x * x);
        }
        
};