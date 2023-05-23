#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <exception>
#include <memory>


std::ifstream fin("abonamente.in");
std::ofstream fout("abonamente.out");



template <typename T>
class Base {
public:

	virtual void print(std::ostream& os) const = 0;
	virtual void read(std::istream& is) = 0;

};

template <typename T>
std::istream& operator>>(std::istream& is, Base<T>& other) {
	other.read(is);
	return is;
}

template <typename T>
std::ostream& operator<<(std::ostream& os, const Base<T>& other) {
	other.print(os);
	return os;
}


class Abonament : public Base<Abonament>{

protected:
	std::string nume_abonament;
	float pret;
	int perioada;
public:
	Abonament() {};

	Abonament(const std::string& n, const float& p, const int& per)
		:nume_abonament(n), pret(p), perioada(per)
	{};

	~Abonament() {};

	std::string getNumeAbonament(){
		return nume_abonament;
	}

	float getPret() {
		return pret;
	}

	int getPerioada() {
		return perioada;
	}

	virtual void print(std::ostream& os) const  {
		os << "Abonament: "; std::cout << nume_abonament << std::endl;
		os << "Pret: "; std::cout << pret << std::endl;
		os << "Perioada: "; std::cout << perioada << std::endl;
	}

	virtual void read(std::istream& is)  {
		std::cout << "Nume Abonament: ";
		is >> nume_abonament;
		std::cout << "Pret: ";
		is >> pret;
		std::cout << "Perioada: ";
		is >> perioada;
	}


};

class Abonament_Premium : public Abonament {
protected:
	int reducere;

public:
	Abonament_Premium() {};
	Abonament_Premium(const std::string& n, const float& p, const int& per, const int& red)
		:Abonament(n, p, per), reducere(red) {};
	~Abonament_Premium() {};

	/*Abonament_Premium getAbonament() {
		return this*;
	}*/

	void print(std::ostream& os) const override{
		Abonament::print(os);
		os << "Reducere: "; std::cout << reducere << std::endl;
	}
	void read(std::istream& is) override {
		Abonament::read(is);
		std::cout << "Reducere: ";
		is >> reducere;
	}
	void setReducere(const int& red)
	{
		reducere = red;
	}

};

class Persoana : public Base<Persoana> {
protected:
	int id;
	std::string nume;
	std::string cnp;
public:
	Persoana() {};
	Persoana(const int& i, const std::string& n, const std::string& c)
		:id(i), nume(n), cnp(c) {};
	~Persoana() {};

	void print(std::ostream& os) const override {
		os << "ID Persoana: "; std::cout << id << std::endl;
		os << "Nume: "; std::cout << nume << std::endl;
		os << "CNP: "; std::cout << cnp << std::endl;
	}

	void read(std::istream& is) override {
		std::cout << "ID Persoana: ";
		is >> id;
		std::cout << "Nume: ";
		is >> nume;
		std::cout << "CNP: ";
		is >> cnp;
	}
};

class Abonat : public Persoana{
protected:
	std::string nr_telefon;
	Abonament* x;

public:
	Abonat() {};
	Abonat(bool is_premium) {
		if (is_premium) {
			x = new Abonament();
		}
		else
			x = new Abonament;
	}
	~Abonat() {
		delete x;
	}

	std::string getNrTel() {
		return nr_telefon;
	}

	

	void print(std::ostream& os) {
		
		std::cout << "Numar Telefon: "; std::cout << nr_telefon << std::endl;
		x->print(os);
		Persoana::print(os);

		
	}
	

	void read(std::istream& is) {
		Persoana::read(is);

		std::cout << "Numar Telefon: ";
		is >> nr_telefon;
		
		bool is_premium;

		std::cout << "Doriti abonament premium? (0 - Nu, 1 - Da): ";
		std::cin >> is_premium;

		if (is_premium) 			
			x = new Abonament_Premium;
		else			
			x = new Abonament();
		
		x->read(is);
	
	}


	std::ostream& operator<<(std::ostream& os, const Abonat& other) {

		Persoana::print(os);
		os << "Numar Telefon: " << other.getNrTel << endl;
		x->print(os);
	}

};



