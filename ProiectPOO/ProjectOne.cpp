#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Materie {
private:
	string denumire;
	bool optional;
public:
	Materie()
	{
		cout << "*** Constructor default materie ***" << endl;

	}

	Materie(const string& param, const bool& param2)
		:denumire(50, ' '), optional(param2)
	{
		cout << "*** Constructor cu parametru materie ***" << endl;

	}

	Materie(const Materie& other)
		:denumire(other.denumire), optional(other.optional)
	{
		cout << "*** Constructor de copiere materie ***" << endl;

	}

	~Materie()
	{
		cout << "*** Destructor materie ***" << endl;
	}

	bool operator==(const Materie& other) const
	{
		return optional == other.optional &&
			denumire == other.denumire;
	}

};

class Student {
private:
	int nrMatricol;
	string nume;
	int grupa;
public:
	Student()
	{
		cout << "*** Constructor default student ***" << endl;
	}

	Student(const int& op1, const string& op2, const int& op3)
		:nrMatricol(op1), nume(op2), grupa(op3)
	{
		cout << "*** Constructor cu parametru student ***" << endl;
	}

	Student(const Student& other)
		:nrMatricol(other.nrMatricol), nume(other.nume), grupa(other.grupa)
	{
		cout << "*** Constructor de copiere student ***" << endl;
	}

	~Student()
	{
		cout << "*** Destructor student ***" << endl;
	}

	friend istream& operator>>(istream&, Student&);
	friend ostream& operator<<(ostream&, Student&);

};

istream& operator>>(istream& in, Student& s)
{
	cout << "Introduceti Nr_matricol:  ";
	in >> s.nrMatricol;
	cout << "Introduceti numele:  ";
	in >> s.nume;
	cout << "Introduceti grupa:  ";
	in >> s.grupa;
	return in;
}

ostream& operator<<(ostream& out, Student& s)
{
	cout << "Nr_matricol: ";
	out << s.nrMatricol;
	cout << endl << "Numele:  ";
	out << s.nume;
	cout << endl << "Grupa:  ";
	out<< s.grupa;
	cout << endl;
	return out;
}


class Curs {
private:
	Materie mat;
	int nrStudenti;
	vector<Student> St;
public:
	Curs()
	{
		cout << "*** Constructor default curs ***" << endl;
	}

	Curs(const Materie& other)
		:mat(other)
	{
		cout << "*** Constructor cu un parametru curs ***" << endl;
	}

	Curs(const Materie& op1, const int& op2, const Curs& op3)
		:mat(op1), nrStudenti(op2), St(op3.St)
	{
		cout << "*** Constructor de copiere curs ***" << endl;
	}

	~Curs()
	{
		cout << "*** Destructor curs ***" << endl;
	}

	Curs& operator+=(const Student& other)
	{
		St.push_back(other);
		return *this;
	}

	friend ostream& operator<<(ostream&, Curs&);
};

ostream& operator<<(ostream& out, Curs& op)
{
	cout << "Materie: ";
	out << op.mat;
	cout << endl << "nrStudenti:  ";
	out << op.nrStudenti;
	cout << endl << "Studenti:  ";
	for i in op.St:
	   out << op.St[i];
	cout << endl;
	return out;
}


int main()
{

	Materie m1("POO", 0), m2("Pedagogie", 1), m3;
	if (m1 == m2)
		cout << "Cursuri identice";
	else
		cout << "Denumiri diferite";

	cout << endl;
	
	Student s1(12, "Ionescu", 133), s2;
    /*
	cin >> s2;
	cout << s1 << endl << s2 << endl;
	*/

	Curs c1(m1);
	c1 += s1;
	Curs c2 = c1;
	return 0;
}