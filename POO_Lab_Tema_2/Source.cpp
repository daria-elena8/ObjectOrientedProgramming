#include "Tema6.h"



int main()
{
	Abonament a1, a2("Netfix", 13.5, 12), a7("Youtube", 10.8, 6);
	//a2.print();
	//Abonament_Premium a3, a4("Youtube", 10.0, 6, 20), a5(a2, 10);
	//a4.print();
	//a5.print();

	//a1 = a7;
	//std::cin >> a1;
	//a1.print();
	

	//std::cout << a7;
	
	//std::cin >> a3;
	//a3 = a4;
	//std::cout << a3;

	Persoana p1, p2(123, "Maria", "60328712812"), p3(p2);
	//p3.print();

	//std::cin >> p1;
	//p1 = p2;
	//std::cout << p1;



	Abonat c1, c3(p2, "0192383091", a2);
	//Abonat c2( 51, "Jessica", "601229218321", "0712345678", "Facebook", 16.4, 24);
	//c1 = c3;

	std::cin >> c1;
	std::cout << c1;

	//c1.print();

	return 0;
}