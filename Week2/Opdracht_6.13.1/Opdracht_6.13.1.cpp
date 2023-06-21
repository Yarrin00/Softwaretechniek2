#include <iostream>
#include <iomanip>
#include <sstream>

class Rechthoek {
private:
	int breedte;
	int hoogte;
public:
	Rechthoek(int breedte = 0, int hoogte = 0);
	void print() const;
};


int main()
{
	Rechthoek r1{ 5, 3 };
	r1.print();
	Rechthoek r2{ 15, 5 };
	r2.print();
}

Rechthoek::Rechthoek(int breedte, int hoogte) :
	breedte(breedte), hoogte(hoogte) {
}

void Rechthoek::print() const {

	//Teken bovenlijn
	for (int i = 0; i < Rechthoek::breedte; i++)
		std::cout << "X ";
	std::cout << '\n';

	//Teken middellijn
	for (int r = 1; r < hoogte - 1; r++)
		std::cout << "X " << std::setw(2*breedte - 2) << "X " << '\n';

	//Teken onderlijn
	for (int i = 0; i < breedte; i++)
		std::cout << "X ";
	std::cout << '\n';
}
