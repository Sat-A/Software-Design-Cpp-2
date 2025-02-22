#include <iostream>
#include <vector>
#include <array>

int main(){
    std::vector<int> v(5, 1);
    std::vector<int>::iterator it1;

    for (it1 = v.begin(); it1 != v.end(); it1++){
        std::cout << *it1 << " ";
    }
    std::cout << std::endl;

    std::array<int, 5> a = {1,2,3,4,5};
    std::array<int, 5>::iterator it2;

    for (it2 = a.begin(); it2 != a.end(); it2++){
        std::cout << *it2 << " ";
    }
    std::cout << std::endl;

}