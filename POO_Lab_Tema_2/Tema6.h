#pragma once
#include <iostream>
#include <string>
#include <vector>

class Abonament
{

public:
	Abonament();
	Abonament(const Abonament& other);
	Abonament(const std::string& ot1, const float& ot2, const int& ot3);
	~Abonament();

	Abonament& operator=(const Abonament& other);
	virtual void print();


	friend std::istream& operator>>(std::istream& is, Abonament& other);
	friend std::ostream& operator<<(std::ostream& os, const Abonament& other);


protected:
	std::string nume_abonament;
	float pret;
	int perioada;

};

class Abonament_Premium : public Abonament
{
public:
	Abonament_Premium();
	Abonament_Premium(const std::string& ot1, const float& ot2, const int& ot3, const int& red);
	Abonament_Premium(const Abonament& ot1, const int& ot2);
	~Abonament_Premium();

	Abonament_Premium& operator=(const Abonament_Premium& other);
	void print();

	friend std::istream& operator>>(std::istream& is, Abonament_Premium& other);
	friend std::ostream& operator<<(std::ostream& os, const Abonament_Premium& other);

protected:
	int reducere;
};



class Persoana
{
public:
	Persoana();
	Persoana(const int& id, const std::string& nume, const std::string& cnp);
	Persoana(const Persoana& other);
	~Persoana();

	Persoana& operator=(const Persoana& other);
	virtual void print();

	friend std::istream& operator>>(std::istream& is, Persoana& other);
	friend std::ostream& operator<<(std::ostream& os, const Persoana& other);


protected:
	int id;
	std::string nume;
	std::string cnp;
};



class Abonat : public Persoana, public Abonament
{

public:

	Abonat();
	Abonat(const int& id_persoana, const std::string& nume_persoana, const std::string& cnp_persoana, const std::string& nr_tel, const std::string& nume_abonament, const float& pret_abonament, const int& perioada_abonament);
	Abonat(const int& id_persoana, const std::string& nume_persoana, const std::string& cnp_persoana, const std::string& nr_tel, const Abonament& other);
	Abonat(const Persoana& other1, const std::string& nr_tel, const std::string& nume_abonament, const float& pret_abonament, const int& perioada_abonament);
	Abonat(const Persoana& other1, std::string other2, const Abonament& other3);

	Abonat(const Abonat& other);
	~Abonat();

	//Abonat& operator=(const Abonat& other);
	void print();

	friend std::istream& operator>>(std::istream& is, Abonat& other);
	friend std::ostream& operator<<(std::ostream& os, const Abonat& other);

protected:
	std::string nr_telefon;
	Abonament x;

};
















/*
 
while(true)
{
 cout<<"1. Introdu o persoana";
 cin>>b;
 cout<<"2. Modifica numele persoanei";
 cout<<"3. Exit";

swich(a)
   { case 1:   
	case 2:
	case 3:
	      break;
	}

*/