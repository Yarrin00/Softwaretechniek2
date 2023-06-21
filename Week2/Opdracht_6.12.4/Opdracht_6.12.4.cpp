#include <iostream> 
#include <sstream> 
#include <string> 

class Bankrekening {
private:
	std::string achternaam;
	std::string rekeningnummer;
	double saldo;
public:
	// constructor 
	Bankrekening(std::string n, std::string nr) {
		achternaam = n;
		rekeningnummer = nr;
		saldo = 0;
	}
	//functies 
	void stort(double bedrag) {
		saldo += bedrag;
	}
	double neem_op(double bedrag) {
		if (saldo < bedrag)
			bedrag = saldo;
		else;
		{
			saldo -= bedrag;
		}
		return bedrag;
	}
	double get_saldo() {
		return saldo;
	}
	std::string to_string() {
		std::ostringstream os;
		os << achternaam << ": nr " << rekeningnummer
			<< ", saldo: " << saldo;
		return os.str();
	}
};

int main() {
	Bankrekening rekeningl("Kesseler", "313");
	std::cout << rekeningl.to_string() << '\n';
	rekeningl.stort(100);
	std::cout << "saldo is nu: " << rekeningl.get_saldo() << '\n';
	rekeningl.neem_op(2003.45);
	std::cout << "saldo is nu: " << rekeningl.get_saldo() << '\n';
	rekeningl.stort(2300);
	std::cout << rekeningl.to_string() << '\n';
}