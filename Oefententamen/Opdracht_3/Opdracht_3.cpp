#include <iostream>
#include <string>

class Punt {
public:
    int x;
    int y;

    Punt(int xCoord, int yCoord) : x(xCoord), y(yCoord) {}
};

class GrafischObject {
protected:
    Punt middelpunt;
    std::string kleur;

public:
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

class Rechthoek : public GrafischObject {
private:
    int lengte;
    int breedte;

public:
    Rechthoek(const Punt& midden, const std::string& objectKleur, int objectLengte, int objectBreedte)
        : GrafischObject(midden, objectKleur), lengte(objectLengte), breedte(objectBreedte) {}

    Punt geefLinkerBovenhoek() {
        int linkerBovenX = middelpunt.x - (lengte / 2);
        int linkerBovenY = middelpunt.y + (breedte / 2);
        return Punt(linkerBovenX, linkerBovenY);
    }

    Punt geefLinkerOnderhoek() {
        int linkerOnderX = middelpunt.x - (lengte / 2);
        int linkerOnderY = middelpunt.y - (breedte / 2);
        return Punt(linkerOnderX, linkerOnderY);
    }

    Punt geefRechterBovenhoek() {
        int rechterBovenX = middelpunt.x + (lengte / 2);
        int rechterBovenY = middelpunt.y + (breedte / 2);
        return Punt(rechterBovenX, rechterBovenY);
    }

    Punt geefRechterOnderhoek() {
        int rechterOnderX = middelpunt.x + (lengte / 2);
        int rechterOnderY = middelpunt.y - (breedte / 2);
        return Punt(rechterOnderX, rechterOnderY);
    }
};

int main() {
    Punt middelpunt(10, 20);
    Rechthoek rechthoek(middelpunt, "blauw", 6, 4);

    rechthoek.print();

    std::cout << "Linker bovenhoek: (" << rechthoek.geefLinkerBovenhoek().x << ", " << rechthoek.geefLinkerBovenhoek().y << ")" << std::endl;
    std::cout << "Linker onderhoek: (" << rechthoek.geefLinkerOnderhoek().x << ", " << rechthoek.geefLinkerOnderhoek().y << ")"
