#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Func{
    // Start by implementing a polynomial function 
    public:
        Func(const Func & F) {};
        // Coefficient list
        // Syntax: [a0, a1, a2, ..., an]
        // Where func:= a0*x^n + a1*x^(n-1) + a2*x^(n-2) + ... + an
        Func(const vector<double> coeff): _coeff(coeff) {};
        double Value(double x=0) const {
            double out = 0;
            int size = _coeff.size();
            for (int i = 0; i < size; i++){
                out = out + _coeff[i]*pow(x, size-i-1);
            };
            return out;
        };
    private:
        vector<double> _coeff;    
};

int main(){
    vector<double> c = {1,2, 3};
    double x = 2;
    Func f{c};
    cout << f.Value(x) << endl;
}