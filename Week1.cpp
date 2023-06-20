#include <iostream>
#include <vector>

int inproduct(std::vector<int> u, std::vector<int> v) {
    int result = 0;
    for (size_t i = 0; i < u.size(); i++) {
        result += u[i] * v[i];
    }
    return result;
}

int main() {
    std::vector<int> x = { 1, 2, 3, 4 };
    std::vector<int> y = { 4, 3, 2, 1 };
    std::cout << "inproduct = " << inproduct(x, y) << std::endl;
    return 0;
}
