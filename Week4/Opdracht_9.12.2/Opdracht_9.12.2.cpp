// Opgave 0902 Klasse Tijdschrift, Boek en CD erven van klasse Uitgave
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

class Uitgave {
protected:
	std::string titel;
	double prijs;
public:
	void lees_in();
	std::string to_string() const;
};

class Tijdschrift : public Uitgave {
private:
	std::string maand;
public:
	void lees_in();
	std::string to_string() const;
};


class Boek : public Uitgave {
private:
	std::string auteur;
	int aantal_bladzijden;
public:
	void lees_in();
	std::string to_string() const;
};


class BlueRay : public Uitgave {
private:
	int aantal_minuten;
public:
	void lees_in();
	std::string to_string() const;
};


int main() {
	using std::cout;
	Tijdschrift t;
	Boek b;
	BlueRay c;

	t.lees_in();
	b.lees_in();
	c.lees_in();
	cout << '\n';
	cout << t.to_string() << '\n';
	cout << b.to_string() << '\n';
	cout << c.to_string() << '\n';
}


// Implementatie Uitgave
void Uitgave::lees_in() {
	std::cout << "Titel: ";
	std::getline(std::cin, titel);
	std::cout << "Prijs: ";
	std::cin >> prijs;
	std::cin.get();
}

std::string Uitgave::to_string() const {
	std::ostringstream os;
	os << titel << ", prijs: " << std::setiosflags(std::ios::showpoint | std::ios::fixed)
		<< std::setprecision(2) << prijs;
	return os.str();
}

// Implementatie Tijdschrift
void Tijdschrift::lees_in() {
	std::cout << "Voer de gegevens van tijdschrift in" << '\n';
	Uitgave::lees_in();
	std::cout << "Maand: ";
	std::getline(std::cin, maand);
}

std::string Tijdschrift::to_string() const {
	std::ostringstream os;
	os << "Tijdschrift: " << Uitgave::to_string() << ", "
		<< "maand " << maand;
	return os.str();
}

// Implementatie Boek
void Boek::lees_in() {
	std::cout << "Voer de gegevens van boek in" << '\n';
	Uitgave::lees_in();
	std::cout << "Auteur: ";
	std::getline(std::cin, auteur);
	std::cout << "Aantal bladzijden: ";
	std::cin >> aantal_bladzijden;
	std::cin.get();
}

std::string Boek::to_string() const {
	std::ostringstream os;
	os << "Boek: " << Uitgave::to_string() << ", " << auteur
		<< ", " << aantal_bladzijden << " bladzijden";
	return os.str();
}


// Implementatie BlueRay
void BlueRay::lees_in() {
	std::cout << "Voer de gegevens van blue-ray in" << '\n';
	Uitgave::lees_in();
	std::cout << "Aantal minuten: ";
	std::cin >> aantal_minuten;
	std::cin.get();
}

std::string BlueRay::to_string() const {
	std::ostringstream os;
	os << "Blue-ray: " << Uitgave::to_string() << ", "
		<< aantal_minuten << " minuten";
	return os.str();
}
