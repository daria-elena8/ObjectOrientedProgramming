#pragma once
#include <iostream>
#include <string>
#include <vector>

class Abonament
{

public:
	Abonament();

	Abonament(const Abonament& other);
	Abonament(Abonament&& other) noexcept;
	Abonament(const std::string& ot1, const float& ot2, const int& ot3);
	virtual ~Abonament();

	Abonament& operator=(const Abonament& other);
	virtual void print();
	//virtual void change();
	//void change(const Abonament& other);

	virtual void getAb(int& count);

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
	Abonament_Premium(const std::string& ot1, const float& ot2, const int& ot3);
	Abonament_Premium(const Abonament& ot1, const int& ot2);
	Abonament_Premium(const Abonament& other);

	virtual ~Abonament_Premium();
	void getAb(int& count);
	Abonament_Premium& operator=(const Abonament_Premium& other);
	void print();
	//void change();
	//int getreducere();

	friend std::istream& operator>>(std::istream& is, Abonament_Premium& other);
	friend std::ostream& operator<<(std::ostream& os, const Abonament_Premium& other);

protected:
	int reducere = -1;
};



class Persoana
{
public:
	Persoana();
	Persoana(const int& id, const std::string& nume, const std::string& cnp);
	Persoana(const Persoana& other);
	//Persoana(const Abonat& other);

	virtual ~Persoana();

	Persoana& operator=(const Persoana& other);
	virtual void print();
	//void change(Persoana& other);

	virtual int getId();
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
	

	Abonat(const int& other);
	Abonat(const Abonat& other);
	virtual ~Abonat();

	//Abonat& operator=(const Abonat& other);
	void print();
	void printPersoana();
	//void printAbonament();

	//void change(Abonat& other);
	int getId();
	int getId(const Abonat& other);

	friend std::istream& operator>>(std::istream& is, Abonat& other);
	friend std::ostream& operator<<(std::ostream& os, const Abonat& other);

protected:
	std::string nr_telefon;
	Abonament x;

};


class Clienti : public Abonat
{
public:

	Clienti();
	~Clienti();


	int getsize();
	Abonat FindID(const int& other);


	//void eraseC(const Abonat& other);
	void Adaugare_Clienti(const Abonat& other);
	int count_premium_abonati();


protected:
	std::vector<Abonat> abonati;
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

