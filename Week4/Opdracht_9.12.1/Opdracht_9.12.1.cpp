// Opgave 0901 Klasse Voertuig
#include <iostream>
#include <string>
#include <sstream>

class Voertuig {
protected:
	int aantal_wielen;
public:
	Voertuig();
	Voertuig(int aw);
	std::string to_string() const;
};


class Fiets : public Voertuig {
private:
	int framenummer;
public:
	Fiets();
	Fiets(int framenr);
	std::string to_string() const;
};


int main() {
	Voertuig v1, v2(3);
	Fiets f1, f2(7653);

	std::cout << v1.to_string() << '\n';
	std::cout << v2.to_string() << '\n';

	std::cout << f1.to_string() << '\n';
	std::cout << f2.to_string() << '\n';
}

Voertuig::Voertuig() : aantal_wielen{ 4 } {}
Voertuig::Voertuig(int aw) : aantal_wielen{ aw } {}

std::string Voertuig::to_string() const {
	std::ostringstream os;
	os << aantal_wielen << " wielen";
	return os.str();
}


Fiets::Fiets() : Voertuig{ 2 }, framenummer{ 0 } {}
Fiets::Fiets(int framenr) : Voertuig{ 2 }, framenummer{ framenr } {}

std::string Fiets::to_string() const {
	std::ostringstream os;
	os << "Deze fiets heeft ";
	os << Voertuig::to_string();
	os << ", en het framenummer is ";
	if (framenummer == 0)
		os << "onbekend";
	else
		os << framenummer;
	return os.str();
}

