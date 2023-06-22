// Opgave 0706 Cijferadministratie
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>


class Datum {
private:
    int dag, maand, jaar;
public:
    Datum(int dag, int maand, int jaar) :
        dag{ dag }, maand{ maand }, jaar{ jaar } {
    }

    std::string to_string() {
        std::ostringstream os;
        os << std::setfill('0') << std::setw(2) << dag << '-'
            << std::setfill('0') << std::setw(2) << maand << '-'
            << std::setw(4) << jaar;
        return os.str();
    }
};


class Tentamenresultaat {
private:
    std::string vak;
    double cijfer;
    Datum tentamendatum;

public:
    Tentamenresultaat(std::string vak, double cijfer, Datum tentamendatum) :
        vak{ vak }, cijfer{ cijfer }, tentamendatum{ tentamendatum } {
    }

    double get_cijfer() {
        return cijfer;
    }

    std::string to_string() {
        std::ostringstream os;
        os << vak << ' ' << std::setprecision(1) << cijfer
            << "; " << tentamendatum.to_string();
        return os.str();
    }
};


class Student {
private:
    std::string naam;
    Datum gebdatum;
    std::vector<Tentamenresultaat> resultatenlijst;

public:
    Student(std::string naam, Datum gebdatum) :
        naam{ naam }, gebdatum{ gebdatum } {
    }

    std::string get_naam() {
        return naam;
    }

    Datum get_gebdatum() {
        return gebdatum;
    }

    void voegtoe(Tentamenresultaat resultaat) {
        resultatenlijst.push_back(resultaat);
    }

    std::string to_string() {
        return naam + ", geboren op " + gebdatum.to_string();
    }

    void print_resultaten() {
        std::cout << "Resultaten van " + to_string() + ":" << std::endl;
        for (auto pos = resultatenlijst.begin(); pos != resultatenlijst.end(); ++pos)
            std::cout << pos->to_string() << std::endl;
    }
};

class Administratie {
private:
    std::vector<Student> lijst;
public:
    void voegtoe(Student s) {
        lijst.push_back(s);
    }

    void print_studenten() {
        for (auto pos = lijst.begin(); pos != lijst.end(); ++pos)
            std::cout << pos->to_string() << std::endl;
    }

    void print_resultaten(Student s) {
        s.print_resultaten();
    }
};


int main() {
    Administratie administratie;

    Student s1 = Student("Klaas", Datum(31, 1, 1994));
    Student s2 = Student("Charlotte", Datum(1, 11, 1994));
    Student s3 = Student("Floor", Datum(9, 4, 1993));

    administratie.voegtoe(s1);
    administratie.voegtoe(s2);
    administratie.voegtoe(s3);

    std::cout << "Studenten in deze administratie:" << std::endl;
    administratie.print_studenten();

    s1.voegtoe(Tentamenresultaat("C++", 8, Datum(8, 12, 2018)));
    s1.voegtoe(Tentamenresultaat("Analyse", 9, Datum(17, 12, 2018)));
    s1.voegtoe(Tentamenresultaat("Lineaire Algebra", 6.5, Datum(10, 1, 2019)));

    std::cout << std::endl;
    administratie.print_resultaten(s1);

    std::cout << std::endl;
}
