// Opgave 6.13.5 De klasse Teller
#include <iostream>
#include <iomanip>
#include <sstream>

class Teller {
private:
    int waarde;
public:
    Teller() :
        waarde{ 0 } {
    }

    void verhoog() {
        waarde++;
    }

    void verlaag() {
        waarde--;
    }

    void set_waarde(int w) {
        waarde = w;
    }

    int get_waarde() const {
        return waarde;
    }
};


int main() {
    Teller teller;
    for (int i = 0; i < 10; i++)
       teller.verhoog();
    std::cout << "De teller staat nu op: " << teller.get_waarde() << '\n';

    for (int i = 0; i < 5; i++)
        teller.verlaag();
    std::cout << "De teller staat nu op: " << teller.get_waarde() << '\n';

    teller.set_waarde(0);
    std::cout << "De teller staat nu op: " << teller.get_waarde() << '\n';
}

