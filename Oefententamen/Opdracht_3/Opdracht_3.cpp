#include <iostream>

class GrafischObject {
public:
    GrafischObject() {}
};

class Punt {
public:
    Punt(int x, int y) : x(x), y(y) {}
    int x;
    int y;
};

class Rechthoek : public GrafischObject {
public:
    Rechthoek(const Punt& middelpunt, int lengte, int breedte)
        : middelpunt(middelpunt), lengte(lengte), breedte(breedte) {}

    Punt geefLinkerBovenhoek() const {
        int x = middelpunt.x - lengte / 2;
        int y = middelpunt.y + breedte / 2;
        return Punt(x, y);
    }

    Punt geefLinkerOnderhoek() const {
        int x = middelpunt.x - lengte / 2;
        int y = middelpunt.y - breedte / 2;
        return Punt(x, y);
    }

    Punt geefRechterBovenhoek() const {
        int x = middelpunt.x + lengte / 2;
        int y = middelpunt.y + breedte / 2;
        return Punt(x, y);
    }

    Punt geefRechterOnderhoek() const {
        int x = middelpunt.x + lengte / 2;
        int y = middelpunt.y - breedte / 2;
        return Punt(x, y);
    }

private:
    Punt middelpunt;
    int lengte;
    int breedte;
};

int main() {
    Punt middelpunt(0, 0);
    Rechthoek rechthoek(middelpunt, 4, 2);

    Punt linkerBovenhoek = rechthoek.geefLinkerBovenhoek();
    std::cout << "Linker bovenhoek: (" << linkerBovenhoek.x << ", " << linkerBovenhoek.y << ")" << std::endl;

    Punt linkerOnderhoek = rechthoek.geefLinkerOnderhoek();
    std::cout << "Linker onderhoek: (" << linkerOnderhoek.x << ", " << linkerOnderhoek.y << ")" << std::endl;

    Punt rechterBovenhoek = rechthoek.geefRechterBovenhoek();
    std::cout << "Rechter bovenhoek: (" << rechterBovenhoek.x << ", " << rechterBovenhoek.y << ")" << std::endl;

    Punt rechterOnderhoek = rechthoek.geefRechterOnderhoek();
    std::cout << "Rechter onderhoek: (" << rechterOnderhoek.x << ", " << rechterOnderhoek.y << ")" << std::endl;

    return 0;
}
