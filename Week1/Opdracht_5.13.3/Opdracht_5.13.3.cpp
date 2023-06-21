// Opgave 5.13.3  Verdubbelen de waarden van v
#include <iostream>
#include <vector>
using namespace std;

void verdubbel(std::vector<int>& v) {
    for (auto pos = v.begin(); pos != v.end(); ++pos)
        *pos *= 2;
}

void print(const std::vector<int>& v) {
    for (auto pos = v.begin(); pos != v.end(); ++pos)
       cout << *pos << ' ';
       cout << '\n';
}

int main() {
    vector<int> v;
    for (int i = 0; i < 5; i++)
        v.push_back(i);
    print(v);
    verdubbel(v);
    print(v);
}

