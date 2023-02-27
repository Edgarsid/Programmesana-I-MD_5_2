#include <iostream>
#include "structure.h"

using namespace std;

clientData ieraksts[100];  // Shajaa gadiijumaa ir 100. Taa kaa masiiva pirmais elements ir 0, tad visi briivie elementi struktuuraa ir 0. Tas noziimee, ka izvadot 0 elementu -
// - izvadiisies visi neaiznjemtie elementi. Un, taa kaa viena no prasiibamm - konta Nr. ir elementa indeks massiivaa, tas shajaa gadiijumaa sanaak papildus 99 ieraksti. 
// Lai reaali uztaisiitu masiivu ar 100 ierakstiem, es rakstiitu shaadi: clientData ieraksts[101]
int nr, select;


void pievienot ()   // Funkcija, lai pievienotu ierakstu
{
	int check;   // nepiecieshams, lai ievadiitu pareizu skaitli
	cout << "Pievienot ierakstu  " << endl;
	do
	{
		check = 0;
		cout << "Ievadiet konta Nr.  " << endl;
		cin >> nr;
		if((nr < 1) || (nr > 99))  // Konta Nr. no 1 - 99 (atsauce uz 7 liiniju). Turpmaak darbaa visur buus diapazons no 1 - 99
		{
			cout << "Atlauts ievadit no 1 - 99" << endl;  // Atljauts ievadiit no 1 - 99
			check = 1;
		}
		else if(nr == ieraksts[nr].accNum)  // Ja ieraksts jau ir aiznjemts
		{
			cout << "Ieraksts jau ir aiznjemts" << endl; 
			check = 1;
		}		
	}
	while(check != 0);
	
	ieraksts[nr].accNum = nr;   // Masiiva elements = konta Nr.
	cout << "Ievadiet uzvardu  " << endl;
	cin >> ieraksts[nr].Sur;  
	cout << "Ievadiet vardu  " << endl;
	cin >> ieraksts[nr].Name;
	cout << "Ievadiet bilanci  " << endl;
	cin  >> ieraksts[nr].balance;
	cout << endl << endl;
	cout << "Ieraksts pievienots" << endl; 
	cout << "-----------------------------------------------------" << endl;
}

void dzest ()   // Funkcija, lai izdzestu ierakstu
{
	int dzest;
	cout << "Dzest ierakstu  " << endl;

	cout << "Ievadiet konta Nr., kuru velaties izdzest " << endl;
	cin >> dzest;
	if(dzest != ieraksts[dzest].accNum || dzest == 0)  // Ja neatrod ierakstu. 0 poziicijaa tiek izmantota izdzestajiem elementiem
		cout << "Ieraksts nav atrasts" << endl;
	else
	{
		ieraksts[dzest].accNum	= '\0';   // Paarvieto uz 0 poziiciju (atsauce uz 7 liiniju)
		cout << endl << "Ieraksts izdzests"<< endl;
	}

	cout << "-----------------------------------------------------" << endl;
}

void izvadit ()   // Funkija lai izvadiitu visus ierakstus
{
	int nav = 0;   // Papildus mainiigais, ja ieraksts neeksistee
	for(int i = 0; i < 100; i++)
		if(ieraksts[i].accNum > 0)  // Ja ieraksts eksistee, tad tas tiek izvadiits
		{
			cout << "Konta nr:  " << ieraksts[i].accNum << endl << "Uzvards:  " << ieraksts[i].Sur << endl 
			<<"Vards:  " << ieraksts[i].Name << endl << "Bilance:  " << ieraksts[i].balance << endl << endl;
			nav = 1;
		}

	if(nav == 0 )  // ja neeksistee, tad neizvada
		cout << "Ierakstu nav" << endl;
		
	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
}

void atrast ()   // Funkcija, lai atrasu ierakstu
{
	int atrast;
	cout << "Ievadiet konta Nr., lai atrastu ierakstu " << endl;
	cin >> atrast;
	
	
	for(int i = 0; i < 100; i++)
	{
		if(ieraksts[i].accNum == atrast)   // ja ievadiitais skaitlis sakriit ar esosho, tad tas tiek izvadiits aaaraa
		{
			atrast = -1;  // jauna veertiiba -1
			cout << "Konta nr:  " << ieraksts[i].accNum << endl << "Uzvards:  " << ieraksts[i].Sur << endl 
			<<"Vards:  " << ieraksts[i].Name << endl << "Bilance:  " << ieraksts[i].balance << endl;
		}
	}
	if(atrast != -1)  // ja nav -1, tad ieraksts nav atrasts
		cout << "Ieraksts nav atrasts" << endl;
		
	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
}

void izmainit ()   // Funkcija, lai izmainiitu bilanci
{
	int nr;
	float bal;

	cout << "Ievadiet konta nr, kuru velaties izmainit" << endl;
	cin >> nr;
	if(nr != ieraksts[nr].accNum || nr == 0)   // LAi paarbaudiitu, vai eksistee ieraksts
		cout << "Ieraksts nav atrasts" << endl;
	else
	{
		cout << "Esoshaa bilance: " << ieraksts[nr].balance << endl;
		cout << "Ievadiet pozitivo vai negativo vertibu, kadu japiesumme esoshai summai" << endl;
		cin >> bal;
		ieraksts[nr].balance = ieraksts[nr].balance + bal;   // Tiek veikta kalkulaacija jaunam ierakstam
		cout << "Jaunaa bilance:  " << ieraksts[nr].balance << endl;
	}
	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
}

void paradnieki ()   // Funkcija paraadniekiem
{
	int check;  // papildus mainiigais, ja nav ierakstu
	for(int i = 0; i < 100; i++)
		if((ieraksts[i].balance < 0) && (ieraksts[i].accNum >= 1))  // Ja bilance ierakstam ir negatiiva, tad tas tiek izvadiits
		{
			cout << "Konta nr:  " << ieraksts[i].accNum << endl << "Uzvards:  " << ieraksts[i].Sur << endl 
			<<"Vards:  " << ieraksts[i].Name << endl << "Bilance:  " << ieraksts[i].balance << endl << endl;
			check = 1;
		}
	if(check != 1)   // ja ierakstu nav
			cout << "Paradnieku nav" << endl;
	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
}

void saskaitit ()  // izvadiit visus ierakstus
{
	int skaits = 0;
	for(int i = 0; i < 100; i++)
		if(ieraksts[i].accNum !=0)   // ja ieraksts eksistee
			++skaits;
	cout << "Datu Baze ir: " << skaits << " ieraksti" << endl;
	cout << endl << endl;
	cout << "-----------------------------------------------------" << endl;
}

void iziet()   // Funkcija, lai izietu.  Var iztikt arii bez, bet bija taada prasiiba.
{
	select = 1010;  // briivi izveeleets skaitlis
}

void menu()   // Funkcija prieksh menu
{
	do  // Cikls funkcijaam
	{
		cout << "1: Pievienot ierakstu" << endl
            << "2: Dzest ierakstu" << endl
			<< "3: Izvadit visus ierakstus" << endl
			<< "4: Atrast ierakstu" << endl
			<< "5: Izmainit konta balansu" << endl
			<< "6: Izvadit paradniekus" << endl
			<< "7: Saskaitit ierakstus" << endl
			<< "8: Iziet" << endl
            << endl;

    cout << "-----------------------------------------------------" << endl;
    
    cin >> select;
    
    if(select == 1)
		pievienot();
	else if(select == 2)
		dzest();
	else if(select == 3)
		izvadit();
	else if(select == 4)
		atrast();
	else if(select == 5)
		izmainit();
	else if(select == 6)
		paradnieki();
	else if(select == 7)
		saskaitit();
	else if(select == 8)
		iziet();
	else
		cout << endl << "Ievadiet skaitli operaciju no 1 lidz 8" << endl <<
		"-----------------------------------------------------" << endl;
	}
	while(select != 1010);

}
