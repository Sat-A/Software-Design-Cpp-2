#include <iostream>
using namespace std;

// Function Template
template <class T>
T jump(T a){
    cout << "Function type " << typeid(a).name() << endl;
    return a + 5;
}

int main() {
    int a(10);
    float b(100);
    int c = jump<int>(a); // Template Function
    float d = jump<float>(b); // Template Function
    cout << c << endl;
    cout << d << endl;
}