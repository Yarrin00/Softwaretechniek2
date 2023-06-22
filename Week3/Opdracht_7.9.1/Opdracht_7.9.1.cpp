#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>

class Datum {
private:
    int dag, maand, jaar;
public:
    Datum(int dag, int maand, int jaar)
        : dag{ dag }, maand{ maand }, jaar{ jaar } {
    }
    std::string toString() const {
        std::ostringstream os;
        os << std::setfill('0') << std::setw(2) << dag << '-'
            << std::setw(2) << maand << '-' << std::setw(4) << jaar;
        return os.str();
    }
};

class Student {
private:
    std::string naam, opleiding, geslacht;
    int nummer;
    Datum gebdat;
public:
    Student(std::string n, std::string opl, std::string gesl, int nr, const Datum& gbd)
        : naam{ n }, opleiding{ opl }, geslacht{ gesl }, nummer{ nr }, gebdat{ gbd } {
    }

    void setNaam(std::string n) {
        naam = n;
    }

    std::string toString() const {
        std::ostringstream os;
        os << naam << " (" << gebdat.toString() << "), ";
        os << opleiding << ", (";
        os << geslacht << "), ";
        os << nummer;
        return os.str();
    }
};

class Team {
private:
    std::string sport;
    std::string teamnaam;
    std::vector<const Student*> teamleden;

public:
    Team(std::string sport, std::string teamnaam) : sport{ sport }, teamnaam{ teamnaam } {
    }

    void voegToe(const Student* lid) {
        teamleden.push_back(lid);
    }

    std::string getTeamnaam() const {
        return teamnaam;
    }

    std::string getSport() const {
        return sport;
    }

    std::string toString() const {
        std::ostringstream os;
        os << "Het team '" << teamnaam << "' (" << sport << ") bestaat uit:\n";
        for (const auto& lid : teamleden)
            os << lid->toString() << '\n';
        return os.str();
    }
};

class Wedstrijd {
private:
    const Team& team1;
    const Team& team2;
    Datum wedstrijddatum;
    std::string uitslag;

public:
    Wedstrijd(const Team& t1, const Team& t2, Datum d)
        : team1{ t1 }, team2{ t2 }, wedstrijddatum{ d }, uitslag{ "geen" } {
    }

    void setUitslag(std::string u) {
        uitslag = u;
    }

    std::string toString() const {
        std::ostringstream os;
        os << "Wedstrijd (" << team1.getSport() << ") op " << wedstrijddatum.toString() << " tussen ";
        os << team1.getTeamnaam() << " en " << team2.getTeamnaam() << "\n\n";
        os << team1.toString() << '\n';
        os << team2.toString() << '\n';
        return os.str();
    }
};

int main() {
    // Maak de studenten
    Student student1("Heleen", "wiskunde", "v", 201053, Datum(13, 5, 1990)),
        student
}