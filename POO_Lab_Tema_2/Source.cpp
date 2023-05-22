#include "Tema6.h"

std::vector<Abonament> subs;
std::vector<Abonament_Premium> subsP;
std::vector<Persoana> pers;
Clienti lista;

void Creare_Date()
{
	Abonament Ab1("Clasic", 12.5, 1), Ab2("Kids", 35, 3), Ab3("Variety 1", 15, 2), Ab4("Variety 2", 17.5, 3), Ab5("Variety 3", 19, 2);
	subs = { Ab1, Ab2, Ab3, Ab4, Ab5 };

	Abonament_Premium AP1("Premium 1", 30, 2, 10), AP2(Ab3, 7), AP3(Ab4, 15);
	subsP = { AP1, AP2, AP3 };

	Persoana p1(100, "Maria", "6020103708367"), p2(101, "Cristian", "60702074024169"), p3(102, "Mircea", "5203725681819");
	Persoana p4(103, "Bogdan", "9287918902617"), p5(104, "Ioana", "40221208358462");
	pers = { p1, p2, p3, p4, p5 };

	Abonat St1(429, "Andreea", "6012867371732", "0724768173", "Clasic", 12.5, 1), St2(p2, "0734366254", Ab4);
	Abonat St3(p3, "0789526396", AP2), St4(563, "Iuliana", "6058253916384", "0752935193", AP3);

	lista.Adaugare_Clienti(St1);
	lista.Adaugare_Clienti(St2);
	lista.Adaugare_Clienti(St3);
	lista.Adaugare_Clienti(St4);
}




int main()
{

	// Declarare ok

	//Abonament a1, a2("Netfix", 13.5, 12), a7("Youtube", 10.8, 6);
	//a2.print();
	//Abonament_Premium a3, a4("Youtube", 10.0, 6), a5(a2, 10);
	//a4.print();
	//a5.print();

	//a1 = a7;
	//std::cin >> a1;
	//a1.print();
	

	//std::cout << a7;
	
	//std::cin >> a3;
	//a3 = a4;
	//std::cout << a3;

	//Persoana p1, p2(123, "Maria", "60328712812"), p3(p2);
	//p3.print();

	//std::cin >> p1;
	//p1 = p2;
	//std::cout << p1;



	std::cout << std::endl;
	
	std::cout << "  *** Bun venit! ***  " << std::endl;
	//std::cout << " What would you like to do? " << std::endl;


	Creare_Date();
/*
	bool program = 1;
	while (program == 1) {
		std::cout << std::endl << " 1. Vizualizare Client       |  2. Vizualizare Manager       |  3. Vizualizare detalii generale " << std::endl;
		int opt1;
		std::cout << std::endl << " Optiunea dvs: ";
		std::cin >> opt1;

		switch (opt1){

			default: {
				std::cout << " Introduceti o optiune valida. " << std::endl;
				std::cout << " Optiunea dvs: ";
				std::cin >> opt1;
				std::cout << std::endl;
				break;
			}

			case 1:
			{		
				int progr = 1;

				while (progr) {


					std::cout << " Ce operatiune ati dori sa faceti?" << std::endl;
					//std::cout << " 1 - Afisare detalii pentru abonamentul curent  " << std::endl;
					//std::cout << " 2 - Schimbare abonament " << std::endl;
					//std::cout << " 3 - Incheiere abonament " << std::endl;
					std::cout << " 4 - Afisare detalii personale " << std::endl;
					//std::cout << " 5 - Reinnoire detalii personale " << std::endl;
					std::cout << " 6 - Reintoarcere la meniul principal " << std::endl;
					std::cout << std::endl;
					std::cout << " Optiunea dvs: ";
					int op11;
					int idp;
					std::cin >> op11;

					if (op11 == 1 || op11 == 2 || op11 == 3 || op11 == 4 || op11 == 5) {
						std::cout << "Va rugam introduceti ID-ul Dvs:" << std::endl;
						std::cout << " ID: ";
						std::cin >> idp;
					}



					switch (op11) {
						/*case 1: {
							int idd = lista.FindID(idp);
							if (lista.FindID(idp).getId() != 0) {
								std::cout << std::endl;
							    for(int i=0; i< subs.size(); i++)
									if 
								
								std::cout << std::endl;
							}
							else
								std::cout << " Abonatul nu exista in baza noastra de date!" << std::endl;
							break; 
						}
								
						/*
						case 2: {


							
									int indice = 0;
									std::cout << " Alegeti noul abonament:" << std::endl;
									std::cout << " Abonamente Free: " << std::endl;
									for (int i = 0; i < subs.size(); i++) {
										std::cout << "  " << indice << "." << std::endl;
										indice++;
										subs[i].print();
										std::cout << std::endl;
									}
									std::cout << std::endl << " Abonamente Premium: " << std::endl;
									for (int i = 0; i < subsP.size(); i++) {
										std::cout << "  " << indice << "." << std::endl;
										indice++;
										subs[i].print();
										std::cout << std::endl;
									}

									std::cin >> indice;
									if (indice < subs.size()) {
										lista.FindID(idp).Abonament::change(subs[i]);
										std::cout << "Datele noului abonament:" << std::endl;
										lista.FindID(idp).printAbonament();

									}
								else {
										lista.FindID(idp).Abonament_Premium::change(subsP[indice + subs.size()]);
										std::cout << "Datele noului abonament:" << std::endl;
										lista.FindID(idp).printAbonament();
									}

								}
							break;
						}
						
						case 3: {
							lista.erase(lista.FindID(idp));
							std::cout << " Abonamentul a fost sters cu succes!" << std::endl;
							break;
						}

						/*case 4: {
							if (lista.FindID(idp).getId() != 0) {
								std::cout << std::endl;
								if (dynamic_cast<Abonament*>(&lista.FindID(idp) != nullptr)
								{

								}
								std::cout << std::endl;
								break;
							}
							else
								std::cout << " Abonatul nu exista in baza noastra de date!" << std::endl;
							}
						

						case 5: {
							std::cout << " Introduceti datele personale: ";



							lista.FindID(idp).change(lista.FindID(idp));
							std::cout << std::endl;
							break;
						}


						case 6: {
							progr = 0;
							break;
						}

						default: {
							std::cout << " Input invalid. Alegeti alta optiune. " << std::endl;
							break;
						}

						}

					
					}
				break;
				}
				
			case 2: {
				
				std::cout << " Adaugare Abonament:" << std::endl;
				std::cout << "1. Free Subscription   |    2. Premium Subscription   | 3. Cancel " << std::endl;

				int s;
				std::cin >> s;
				
				int progr3;
				progr3 = 1;

				while (progr3 == 1) {

					switch (s){
						case 1: {
							Abonament a1;
							std::cin >> a1;

							subs.push_back(a1);

							std::cout << std::endl << " Here`s what we got: " << std::endl;
							a1.print();
							break;
						}

						case 2: {
							Abonament_Premium a1;
							std::cin >> a1;

							subsP.push_back(a1);

							std::cout << std::endl << " Here`s what we got: " << std::endl;
							a1.print();
							break;
						}

						case 3: {
							progr3 = 0;
							break;
						}


						default: {
							std::cout << " Please type in a valid input. " << std::endl;
							std::cin >> s;
							break;
						}
					}

				}
				
				
				std::cout << " Datele introduse sunt corecte?  Yes(y)/No(n) " << std::endl;
				char c;
				std::cin >> c;

				while (cont) {
					switch (c)
					{
					case 'y': {
						std::cout << " Great! ";
						cont = 0;
						break;
					}

					case 'n': {
						std::cout << " Please type in the modified data: " << std::endl;

						std::cout << "1. Free Subscription   |    2. Premium Subscription   | 3. Cancel " << std::endl;
						
						int p3;
						std::cin >> p3;

						switch (p3) {

						}
						
						lista[lista.size() - 1].Abonament::change();
						break;
					}

					default: {
						std::cout << " Please type in a valid input. " << std::endl;
						break;
					}
					
			}
		
		}
			
		}
	*/

	

	std::cout << " Afisare Abonamente Free" << std::endl << std::endl;
	for (int i = 0; i < subs.size(); i++) {
		subs[i].print();
		std::cout << std::endl;
	}

	std::cout << " Afisare Abonamente Premium" << std::endl << std::endl;
	for (int i = 0; i < subsP.size(); i++) {
		subsP[i].print();
		std::cout << std::endl;
	}

	std::cout << " 1. Aflarea numarului de abonati la serviciul premium." << std::endl;
	std::cout << " Numarul de abonati la serviciul premium: " << lista.count_premium_abonati() << std::endl;
	std::cout << std::endl;

	//Abonat c1, c3(p2, "0192383091", a2);
	//Abonat c2( 51, "Jessica", "601229218321", "0712345678", "Facebook", 16.4, 24);
	//c1 = c3;

	//std::cin >> c1;
	//std::cout << c1;

	//c1.print();

	/*
	int cerere = 1;
	std::cout << "Bine ati venit la Meniul principal!" << std::endl;

	while (cerere)
	{
		int opt1;
		std::cout << " Sunteti:   1. Client;      2. Manager; " << std::endl;
		std::cin >> opt1;

		if (opt1 == 1)
		{
			std::cout << " Ce operatiune ati dori sa faceti?";
			std::cout << " 1 - Afisare detalii abonamente disponibile " << std::endl;
			std::cout << " 2 - Afisare detalii pentru abonamentul curent  " << std::endl;
			std::cout << " 3 - Schimbare abonament " << std::endl;
			std::cout << " 4 - Incheiere abonament " << std::endl;
			std::cout << " 5 - Afisare detalii personale " << std::endl;
			std::cout << " 6 - Reinnoire detalii personale " << std::endl;

			int opt2;
			std::cin >> opt2;

			switch (opt2)
			{
			       case 1:
			}

		}
		else
		{
			std::cout << " 1 - Afisare abonamente " << std::endl;
			std::cout << " 2 - Afisare persoane " << std::endl;
		}

		
	}*/



	return 0;
}