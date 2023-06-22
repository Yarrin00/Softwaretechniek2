#include <iostream>
#include <string>

class Teller {
private:
    int waarde;

public:
    Teller() : waarde(0) {}

    void verhoog() {
        waarde++;
    }

    void set_waarde(int nieuweWaarde) {
        waarde = nieuweWaarde;
    }

    int get_waarde() const {
        return waarde;
    }
};

class MV {
private:
    Teller mTeller;
    Teller vTeller;

public:
    void man() {
        mTeller.verhoog();
    }

    void vrouw() {
        vTeller.verhoog();
    }

    void zet_op_nul() {
        mTeller.set_waarde(0);
        vTeller.set_waarde(0);
    }

    std::string to_string() const {
        std::string result = "Aantal vrouwen: " + std::to_string(vTeller.get_waarde()) + "\n";
        result += "Aantal mannen: " + std::to_string(mTeller.get_waarde()) + "\n";
        return result;
    }
};

int main() {
    MV mv;
    char keuze;

    while (true) {
        std::cout << "Druk M voor man, V voor vrouw, of S om te stoppen: ";
        std::cin >> keuze;

        if (keuze == 'M' || keuze == 'm') {
            mv.man();
        }
        else if (keuze == 'V' || keuze == 'v') {
            mv.vrouw();
        }
        else if (keuze == 'S' || keuze == 's') {
            break;
        }
        else {
            std::cout << "Ongeldige invoer. Probeer opnieuw." << std::endl;
        }
    }

    std::cout << mv.to_string() << std::endl;
    mv.zet_op_nul();
    std::cout << "Tellers zijn op nul gezet." << std::endl;

    return 0;
}
