#include "Tema6.h"

Abonament::Abonament()
{
	std::cout << " Constructor Default Abonament " << std::endl;
}

Abonament::Abonament(const Abonament& other)
	:nume_abonament(other.nume_abonament), pret(other.pret), perioada(other.perioada)
{
	std::cout << " Constructor cu un Parametru Abonament " << std::endl;
}

Abonament::Abonament(const std::string& ot1, const float& ot2, const int& ot3)
	:nume_abonament(ot1), pret(ot2), perioada(ot3)
{
	std::cout << " Constructor cu Parametrii Abonament " << std::endl;
}

Abonament::~Abonament()
{
	std::cout << " Destructor Abonament " << std::endl;
}


std::istream& operator>>(std::istream& is, Abonament& other)
{
	std::cout << std::endl;
	std::cout << " *** Please insert information about Abonament *** " << std::endl;
		
	std::cout << " Introduceti numele abonamentului: ";
	std::getline(is, other.nume_abonament);

	std::cout << " Introduceti pretul abonamentului: ";
	is >> other.pret;

	std::cout << " Introduceti perioada abonamentului: ";
	is >> other.perioada;

	
	return is;

}

std::ostream& operator<<(std::ostream& os, const Abonament& other)
{
	std::cout << std::endl;
	os << " *** Showing information for Abonament ***" << std::endl;
	os << " Nume Abonament: " << other.nume_abonament << std::endl;
	os << " Pret Abonament: " << other.pret << std::endl;
	os << " Perioada Abonament: " << other.perioada << " luni" << std::endl;
	
	return os;
}

std::istream& operator>>(std::istream& is, Abonament_Premium& other)
{
	is >> static_cast<Abonament&>(other);
	std::cout << " Introduceti Reducere Abonament: ";
	is >> other.reducere;
	std::cout << std::endl;

	return is;
}

std::ostream& operator<<(std::ostream& os, const Abonament_Premium& other)
{
	os << static_cast<const Abonament&>(other);
	os << " Reducere Abonament Premium: " << other.reducere << "%" << std::endl;
	std::cout << std::endl;

	return os;
}


Abonament& Abonament::operator=(const Abonament& other)
{
	std::cout << " Using Abonament Operator = " << std::endl;

	if (this != &other)
	{
		nume_abonament = other.nume_abonament;
		pret = other.pret;
		perioada = other.perioada;
	}

	return *this;
}

void Abonament::print()
{
	std::cout << " - Nume abonament: " << nume_abonament << std::endl;
	std::cout << " - Pret: " << pret << std::endl;
	std::cout << " - Perioada: " << perioada << std::endl;
}

Abonament_Premium::Abonament_Premium()
{
	std::cout << " Constructor Abonament Premium " << std::endl;
}

Abonament_Premium::Abonament_Premium(const std::string& ot1, const float& ot2, const int& ot3, const int& red)
	:Abonament(ot1, ot2, ot3), reducere(red)
{
	std::cout << " Constructor cu Parametrii Abonament Premium " << std::endl;
}

Abonament_Premium::Abonament_Premium(const Abonament& ot1, const int& ot2)
	:Abonament(ot1),reducere(ot2)
{
	std::cout << " Constructor pe Baza de Abonament " << std::endl;
}

Abonament_Premium::~Abonament_Premium()
{
	std::cout << " Destructor Abonament Premium " << std::endl;
}

Abonament_Premium& Abonament_Premium::operator=(const Abonament_Premium& other)
{
	std::cout << " Using Abonament_Premium Operator = " << std::endl;
	if (this != &other)
	{
		Abonament::operator=(other);
		reducere = other.reducere;
	}
	return *this;
}

void Abonament_Premium::print()
{
	Abonament::print();
	std::cout << " - Reducere: " << reducere <<"%" << std::endl;
}

Persoana::Persoana()
{
	std::cout << " Constructor Default Persoana " << std::endl;
}

Persoana::Persoana(const int& id, const std::string& nume, const std::string& cnp)
	:id(id), nume(nume), cnp(cnp)
{
	std::cout << " Constructor cu Parametrii Persoana " << std::endl;
}

Persoana::Persoana(const Persoana& other)
	:id(other.id), nume(other.nume), cnp(other.cnp)
{
	std::cout << " Constructor cu un Parametru Persoana " << std::endl;
}

Persoana::~Persoana()
{
	std::cout << " Destructor Persoana " << std::endl;
}

Persoana& Persoana::operator=(const Persoana& other)
{
	std::cout << " Using Persoana Operator =" << std::endl;
	if (this != &other)
	{
		nume = other.nume;
		id = other.id;
		cnp = other.cnp;
	}
	return *this;
}

void Persoana::print()
{
	std::cout << " - Id_Persoana: " << id << std::endl;
	std::cout << " - Nume_Persoana: " << nume << std::endl;
	std::cout << " - CNP_Persoana: " << cnp << std::endl;
}

std::istream& operator>>(std::istream& is, Persoana& other)
{
	std::cout << std::endl;
	std::cout << " *** Please insert information about Persoana ***" << std::endl;
	std::cout << " Introduceti ID Persoana: ";
	is >> other.id;
	std::cout << " Introduceti Nume Persoana: ";
	is >> other.nume;
	std::cout << " Introduceti CNP Persoana: ";
	is >> other.cnp;
	std::cout << std::endl;

	return is;

}

std::ostream& operator<<(std::ostream& os, const Persoana& other)
{
	std::cout << std::endl;
	std::cout << " *** Showing Informations for Persoana *** " << std::endl;
	os << " ID Persoana: " << other.id << std::endl;
	os << " Nume Persoana: " << other.nume << std::endl;
	os << " CNP Persoana: " << other.cnp << std::endl;
	std::cout << std::endl;
	return os;
}

std::istream& operator>>(std::istream& is, Abonat& other)
{
	std::cout << std::endl;
	std::cout << " *** Please Insert Information about Abonat ***" << std::endl;
	is >> static_cast<Persoana&>(other);

	std::cout << " Introduceti Numar de Telefon: ";
	is >> other.nr_telefon;

	std::cout << std::endl;
	is >> static_cast<Abonament&>(other);
	std::cout << std::endl;

	// !!!! Sare peste nume_abonament

	return is;

}

std::ostream& operator<<(std::ostream& os, const Abonat& other)
{
	std::cout << std::endl;
	std::cout << " *** Showing Informations for Abonat *** " << std::endl;

	const Persoana* pers_ptr = dynamic_cast<const Persoana*>(&other);
	if(pers_ptr == nullptr)
		throw std::runtime_error("Dynamic Cast Failed --- Nu s-a putut face conversia la Persoana");
	
	os << *pers_ptr;
		
	os << " Numar telefon Abonat: " << other.nr_telefon;

	const Abonament* ab_ptr = dynamic_cast<const Abonament*>(&other);
	if(ab_ptr == nullptr)
		throw std::runtime_error("Dynamic Cast Failed --- Nu s-a putut face conversia la Abonament");
	
	os << *ab_ptr;
		
	return os;

}


Abonat::Abonat()
{
	std::cout << " Constructor Default Abonat " << std::endl;
}

Abonat::Abonat(const int& id_persoana, const std::string& nume_persoana, const std::string& cnp_persoana, const std::string& nr_tel, const std::string& nume_abonament, const float& pret_abonament, const int& perioada_abonament)
	:Persoana(id_persoana, nume_persoana, cnp_persoana), nr_telefon(nr_tel), Abonament(nume_abonament, pret_abonament, perioada_abonament)
{
	std::cout << " Constructor 1 Abonat " << std::endl;
}

Abonat::Abonat(const int& id_persoana, const std::string& nume_persoana, const std::string& cnp_persoana, const std::string& nr_tel, const Abonament& other)
	:Persoana(id_persoana, nume_persoana, cnp_persoana), nr_telefon(nr_tel), Abonament(other)
{
	std::cout << " Constructor 2 Abonat " << std::endl;
}

Abonat::Abonat(const Persoana& other1, const std::string& nr_tel, const std::string& nume_abonament, const float& pret_abonament, const int& perioada_abonament)
	:Persoana(other1), nr_telefon(nr_tel), Abonament(nume_abonament, pret_abonament, perioada_abonament)
{
	std::cout << " Constructor 3 Abonat " << std::endl;
}

Abonat::Abonat(const Persoana& other1, std::string other2, const Abonament& other3)
	:Persoana(other1), nr_telefon(other2), Abonament(other3)
{
	std::cout << " Constructor 4 Abonat " << std::endl;
}

Abonat::Abonat(const Abonat& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;
	id = other.id;
	nume = other.nume;
	cnp = other.cnp;
	nr_telefon = other.nr_telefon;
	std::cout << " Constructor de Copiere Abonat " << std::endl;
}

Abonat::~Abonat()
{
	std::cout << " Destructor Abonat " << std::endl;
}

void Abonat::print()
{
	Persoana::print();
	std::cout << " - Numar de telefon: " << nr_telefon << std::endl;
	Abonament::print();
}


