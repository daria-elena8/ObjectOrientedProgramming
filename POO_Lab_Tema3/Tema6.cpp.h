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
	/*template <typename U>
	typename std::enable_if<!std::is_same<U, Base>::value, Base&>::type
		operator<<(Base& object, const U& other) {
		std::cout << obj;
		return object;
	}

	template <typename U>
	typename std::enable_if<std::is_same<U, Base>::value, Base&>::type
		operator<<(Base& object, const U& other) {
		object.print(other);
		return object;
	}*/
	template <typename U>
	friend typename std::enable_if<!std::is_same<U, Base>::value, Base&>::type
		operator<<(Base& object, const U& other) {
		std::cout << other;
		return object;
	}

	template <typename U>
	friend typename std::enable_if<!std::is_same<U, Base>::value, Base&>::type
		operator>>(Base& object, U& other) {
		std::cin >> other;
		return object;
	}

	template <typename U>
	void print(const T& other) const = 0;
};





class Abonament : public Base<Abonament>{

protected:
	std::string nume_abonament;
	float pret;
	int perioada;
public:

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

	void print(const Abonament& other) {
		std::cout << "Abonament: " << other.nume_abonament << std::endl;
		std::cout << "Pret: " << other.pret << std::endl;
		std::cout << "Perioada: " << other.perioada << std::endl;
	}

	/*

	friend std::istream& operator>>(std::istream& in, Abonament& other) {
		std::cout << "Introduceti detalii despre abonament: " << std::endl;
		std::cout << "Nume: ";
		in >> other.nume_abonament;
		std::cout << "Pret: ";
		in >> other.pret;
		std::cout << "Perioada: ";
		in >> other.perioada;

		return in;
	}*/
	/*
	friend std::ifstream& operator>>(std::ifstream& in, Abonament& other) {
		
		in >> other.nume_abonament;
		in >> other.pret;
		in >> other.perioada;
		return in;
	}

	friend std::ostream& operator<<(std::ostream& out, const Abonament& other) {
		out << "Abonament: " << other.nume_abonament << std::endl;
		out << "Pret: " << other.pret << std::endl;
		out << "Perioada: " << other.perioada << std::endl;
	}

	friend std::ofstream& operator<<(std::ofstream& out, const Abonament& other) {
		out << "Abonament: " << other.nume_abonament << std::endl;
		out << "Pret: " << other.pret << std::endl;
		out << "Perioada: " << other.perioada << std::endl;
	}*/


};

class Abonament_Premium : public Abonament {
protected:
	int reducere;

public:
	Abonament_Premium(const std::string& n, const float& p, const int& per, const int& red)
		:Abonament(n, p, per), reducere(red) {};

};

class Persoana {
protected:
	int id;
	std::string nume;
	std::string cnp;
public:

};

class Abonat : public Persoana {
protected:
	std::string nr_telefon;
	Abonament x;
};