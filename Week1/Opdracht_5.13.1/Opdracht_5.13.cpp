#include <iostream>
#include<string>
using namespace std;

void vervang(std::string& s, char bron, char doel);

int main() {
    std::string str = "staal";
    std::cout << str << '\n';
    vervang(str, 'a', 'e');
    std::cout << str << '\n';
}

void vervang(std::string& s, char bron, char doel) {
    for (auto pos = s.begin(); pos != s.end(); ++pos) {
        if (*pos == bron)
            *pos = doel;
    }
}


