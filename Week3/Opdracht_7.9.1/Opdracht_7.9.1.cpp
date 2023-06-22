// Opgave 0701 Team met teamnaam, wedstrijd tussen twee teams
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <vector>
;

class Datum {
private:
    int dag, maand, jaar;
public:
    Datum(int dag, int maand, int jaar)
        : dag{ dag }, maand{ maand }, jaar{ jaar } {
    }
    std::string to_string() const {
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

    std::string to_string() const {
        std::ostringstream os;
        os << naam << " (" << gebdat.to_string() << "), ";
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

    void voeg_toe(const Student* lid) {
        teamleden.push_back(lid);
    }

    std::string get_teamnaam() {
        return teamnaam;
    }

    std::string get_sport() {
        return sport;
    }

    std::string to_string() const {
        std::ostringstream os;
        os << "Het team '" << teamnaam << "' (" << sport << ") bestaat uit:" << '\n';
        for (auto pos = teamleden.begin(); pos != teamleden.end(); ++pos)
            os << (**pos).to_string() << '\n';
        return os.str();
    }
};

class Wedstrijd {
private:
    Team team1, team2;
    Datum wedstrijddatum;
    std::string uitslag;

public:
    Wedstrijd(Team t1, Team t2, Datum d) :
        team1{ t1 }, team2{ t2 }, wedstrijddatum{ d }, uitslag{ "geen" } {
    }

    void setUitslag(std::string u) {
        uitslag = u;
    }

    std::string to_string() {
        std::ostringstream os;
        os << "Wedstrijd (" << team1.get_sport() << ") op " << wedstrijddatum.to_string() << " tussen ";
        os << team1.get_teamnaam() << " en " << team2.get_teamnaam() << '\n' << '\n';
        os << team1.to_string() << '\n';
        os << team2.to_string() << '\n';
        return os.str();
    }
};


int main() {
    // Maak de studenten
    Student student1("Heleen", "wiskunde", "v", 201053, Datum(13, 5, 1990)),
        student2("Lucia", "Engels", "v", 227756, Datum(16, 4, 1991)),
        student3("Jeannette", "muziek", "v", 233475, Datum(29, 7, 1989)),
        student4("Menno", "informatica", "m", 212364, Datum(6, 3, 1992));

    // Vorm de teams
    Team team1("roeien", "Triton");
    team1.voeg_toe(&student1);
    team1.voeg_toe(&student2);

    Team team2("roeien", "Neptunus");
    team2.voeg_toe(&student3);
    team2.voeg_toe(&student4);

    // Maak de wedstrijd
    Wedstrijd wedstrijd(team1, team2, Datum(29, 7, 2025));

    // Verzorg de uitvoer
    std::cout << wedstrijd.to_string() << '\n';
}
