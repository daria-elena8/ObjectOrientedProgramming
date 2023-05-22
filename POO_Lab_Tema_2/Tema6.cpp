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

Abonament::Abonament(Abonament&& other) noexcept
{
	std::cout << " Abonament Moved " << std::endl;
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;

	other.nume_abonament = "";
	other.pret = 0;
	other.perioada = 0;
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
	is >> other.nume_abonament;
	
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
	std::cout << " - Pret: " << pret << "$" << std::endl;
	std::cout << " - Perioada: " << perioada << " months " << std::endl;
}
void Abonament::getAb(int &count)
{
	
}
/*
void Abonament::change()
{
	std::cout << " Nume abonament: ";
	std::cin >> nume_abonament;
	std::cout << std::endl << " Pret: ";
	std::cin >> pret;
	std::cout << std::endl << " Perioada: ";
	std::cin >> perioada;
	std::cout << std::endl;
}

void Abonament::change(const Abonament& other)
{
	nume_abonament = other.nume_abonament;
	pret = other.pret;
	perioada = other.perioada;

	std::cout << " Abonament schimbat cu succes!" << std::endl;
}
*/

Abonament_Premium::Abonament_Premium()
{
	std::cout << " Constructor Abonament Premium " << std::endl;
}

Abonament_Premium::Abonament_Premium(const std::string& ot1, const float& ot2, const int& ot3, const int& red)
	:Abonament(ot1, ot2, ot3), reducere(red)
{
	std::cout << " Constructor cu Parametrii Abonament Premium " << std::endl;
}

Abonament_Premium::Abonament_Premium(const std::string& ot1, const float& ot2, const int& ot3)
	:Abonament(ot1, ot2, ot3)
{
	std::cout << std::endl << " Warning!  Your Subscription Was Downgraded To Free" << std::endl << std::endl;
}

Abonament_Premium::Abonament_Premium(const Abonament& ot1, const int& ot2)
	:Abonament(ot1),reducere(ot2)
{
	std::cout << " Constructor pe Baza de Abonament " << std::endl;
}

Abonament_Premium::Abonament_Premium(const Abonament& other)
	:Abonament(other)
{
	std::cout << std::endl << " Warning!  Your Subscription Was Downgraded To Free" << std::endl << std::endl;

}

Abonament_Premium::~Abonament_Premium() 
{
	std::cout << " Destructor Abonament Premium " << std::endl;
}

void Abonament_Premium::getAb(int &count)
{
	count++;
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
	
	if (reducere > 0)
	{
		Abonament::print();
		std::cout << " - Reducere: " << reducere << "%" << std::endl;
	}
	
}
/*
void Abonament_Premium::change()
{
	Abonament::change();
	std::cout << " Reducere: " << std::endl;
	std::cin >> reducere;

}

int Abonament_Premium::getreducere()
{
	return reducere;
}
*/

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
/*
Persoana::Persoana(const Abonat& other)
	:id(other.id), nume(other.nume), cnp(other.cnp)
{
}*/

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
/*
void Persoana::change(Persoana& other)
{
	
	std::cout << " ID: " << std::endl;
	std::cin >> other.id;
	std::cout << " Nume: " << std::endl;
	std::cin >> other.nume;
	std::cout << " CNP: " << std::endl;
	std::cin >> other.cnp;

	std::cout << " Date personale modificate cu succes! " << std::endl;

}*/

int Persoana::getId()
{
	return id;
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

	std::cout << std::endl;

		
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

Abonat::Abonat(const int& other)
{
	id = other;
	std::cout << "Constructor Verificare Abonat" << std::endl;
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

void Abonat::printPersoana()
{
	Persoana::print();
}
/*
void Abonat::printAbonament(const Abonament& other)
{
	if (other.getreducere() > 0)
	{
		std::cout << " Status: Abonament Premium " << std::endl;
		Abonament::print();
		std::cout << " - Reducere: " << other.getreducere << "%" << std::endl;
	}
	else
	{
		std::cout << " Status: Abonament Free " << std::endl;
		Abonament::print();

	}
	
}*/
/*
void Abonat::change(Abonat& other)
{

	Persoana p( other.id, other.nume, other.cnp );
	Persoana::change(p);
}*/

int Abonat::getId()
{
	int idd = Persoana::getId();
	return idd;
}

int Abonat::getId(const Abonat& other)
{
	return other.id;
}

Clienti::Clienti()
{
	std::cout << " Constructor Default Clienti " << std::endl;

}

Clienti::~Clienti() 
{
	std::cout << " Destructor Clienti " << std::endl;
}


int Clienti::getsize()
{
	return abonati.size();
}

Abonat Clienti::FindID(const int& other)
{
	for (int i = 0; i < abonati.size(); i++) 
		if (getId(abonati[i]) == other)
		{
			Abonat b = abonati[i];
			return b;
		}
			
	 Abonat a(0);
	 return a;
}
/*
void Clienti::eraseC(const Abonat& other)
{
	for (int i = 0; i < abonati.size(); i++)
		if (getId(abonati[i]) == getId(other)) {
              abonati.erase(i);
			break;
		}
}
*/
void Clienti::Adaugare_Clienti(const Abonat& other)
{
	abonati.push_back(other);
	std::cout << " Am adaugat cu succes un nou abonat! " << std::endl;
}

int Clienti::count_premium_abonati()
{
	int count = 0;
	for (int i = 0; i < size(abonati); i++)
		abonati[i].getAb(count);
	return count;
}


