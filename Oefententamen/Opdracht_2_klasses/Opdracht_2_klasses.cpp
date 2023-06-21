#include <iostream>
#include <string>

class Punt {
public:
    int x;
    int y;

    Punt(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}

    void zetCoordinaten(int xCoord, int yCoord) {
        x = xCoord;
        y = yCoord;
    }
};

class GrafischObject {
public:
    Punt middelpunt;
    std::string kleur;

    GrafischObject(const Punt& midden, const std::string& objectKleur)
        : middelpunt(midden), kleur(objectKleur) {}

    void print() const {
        std::cout << "Grafisch object met middelpuntX = " << middelpunt.x
            << ", middelpuntY = " << middelpunt.y
            << " met de kleur " << kleur << "." << std::endl;
    }

    void zetMiddelpunt(const Punt& p) {
        middelpunt = p;
    }
};

int main() {
    Punt middelpunt(10, 20);
    GrafischObject object(middelpunt, "rood");

    object.print();

    Punt nieuwMiddelpunt(50, 80);
    object.zetMiddelpunt(nieuwMiddelpunt);

    object.print();

    return 0;
}
