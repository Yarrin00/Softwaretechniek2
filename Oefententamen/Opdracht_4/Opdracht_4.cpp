#include <iostream>
#include <vector>

class GrafischObject {
public:
    virtual ~GrafischObject() {}
    virtual void print() const = 0;
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

    void print() const override {
        std::cout << "Rechthoek, lengte: " << lengte << ", breedte: " << breedte
            << ", middelpunt (" << middelpunt.x << "," << middelpunt.y << ")" << std::endl;
    }

private:
    Punt middelpunt;
    int lengte;
    int breedte;
};

class Tekening {
public:
    void voegRechthoekToe(Rechthoek* rechthoek) {
        rechthoeken.push_back(rechthoek);
    }

    void print() const {
        std::cout << "Tekening bestaat uit:" << std::endl;
        for (const auto& rechthoek : rechthoeken) {
            rechthoek->print();
        }
    }

private:
    std::vector<Rechthoek*> rechthoeken;
};

int main() {
    Tekening tekening;

    Rechthoek* rechthoek1 = new Rechthoek(Punt(20, 20), 8, 4);
    Rechthoek* rechthoek2 = new Rechthoek(Punt(50, 120), 12, 40);
    Rechthoek* rechthoek3 = new Rechthoek(Punt(100, 200), 60, 20);

    tekening.voegRechthoekToe(rechthoek1);
    tekening.voegRechthoekToe(rechthoek2);
    tekening.voegRechthoekToe(rechthoek3);

    tekening.print();

    // Geheugen opruimen
    delete rechthoek1;
    delete rechthoek2;
    delete rechthoek3;

    return 0;
}
