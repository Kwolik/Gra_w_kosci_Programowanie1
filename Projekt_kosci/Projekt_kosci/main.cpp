#include <iostream>
#include <string>
#include <fstream>
#include <ctime>
#include <cstdlib>

using namespace std;
// Robert Kwoll grupa1A
struct tabela
{
	string nazwa;
	int punkty;

};

//Dodawanie elementow do struktury
tabela jeden{"	jedynki	   ",0 };
tabela dwa{ "	dwojki     ",0 };
tabela trzy{ "	trojki     ",0 };
tabela cztery{ "	czworki    ", 0 };
tabela piec{ "	piatki     ",0 };
tabela szesc{ "	szostki    ",0 };

tabela jed3{ "	3 jednakowe",0 };
tabela jed4{ "	4 jednakowe",0 };
tabela full{ "	full       ",0 };
tabela mstrit{ "	maly strit ",0 };
tabela dstrit{ "	duzy strit ",0 };
tabela general{ "	general    ",0 };
tabela szansa{ "	szansa     ",0 };

int rzut = 1, rz[5]{}, n = 5; //zmienne globalne uzywane w rzuty i zatrzym
int k = 0, tablica[5]{}, a = 0; //zmienne globalne uzywane w  zatrzym
int wynik=0, tab[13]{};

void menu();
void rzuty();
void instrukcja();
void wyniki();
void sprawdz(char);
void sprawdz2(char);
void zapytanie();
void zatrzym(int* kosc);
void zapis(int* reszta);
void wyswietl();

int main()
{
	menu();
	system("pause");
}

void sprawdz(char litera)
{
	system("cls");  //czyszczenie konsoli

	if (litera == 'A' || litera == 'a')
		rzuty();
	if (litera == 'B' || litera == 'b')
		instrukcja();
	if (litera == 'C' || litera == 'c')
		wyniki();
}

void sprawdz2(char litera)
{

	if (litera == 'A' || litera == 'a')
		zatrzym(&rz[0]);
	if (litera == 'B' || litera == 'b')
		zapis(&rz[0]);
	if (litera == 'C' || litera == 'c')
		wyswietl();
	if (litera == 'D' || litera == 'd')
		rzuty();
	if (litera == 'E' || litera == 'e')
		instrukcja();
}

void menu()
{
	char nazwa{};
	for (int i = 1; i <= 17; i++)
		cout << "-";

	cout << endl;
	cout << "|  Gra w kosci  |" << endl;

	for (int i = 1; i <= 17; i++)
		cout << "-";

	cout << endl;
	cout << "|  A.Gra        |" << endl;
	cout << "|  B.Instrukcja |" << endl;
	cout << "|  C.Wyniki     |" << endl;

	for (int i = 1; i <= 17; i++)
		cout << "-";

	cout << endl;

	do
	{
		cout << "Podaj litere przy ktorej zawarta jest funkcja:  ";
		cin >> nazwa;
	} while (nazwa >=0 && nazwa <65 || nazwa >67 && nazwa <97 || nazwa >99);

	sprawdz(nazwa);
}

void rzuty()
{
	srand(time(nullptr));

	if (rzut < 4)
	{
		int los = 0;
		cout << rzut << ". Rzut " << endl;
		cout << "Wyrzucone kosci to: ";
		for (int i = 1; i <= n; i++)
		{
			do
			{
				rz[los] = rand() % 7;   //Petla do while aby losowalo jeszcze raz jesli sie wylosuje 0
			} while (rz[los] == 0);

			cout << rz[los] << "  ";
			los++;
		}
		rzut++;
		zapytanie();

	}

	else
		zapis(&rz[0]);


}

void instrukcja()
{
	string tekst{};

	ifstream plik("instrukcja.txt");
	if (plik.is_open())
	{
		while (!plik.eof())
		{
			getline(plik, tekst);
			cout << tekst << endl;
		}
	}

	else
		cout << "Nie mozna otworzyc pliku." << endl;

	plik.close();

	cout << "\n";
	menu();

}

void wyniki()
{
	string nick;
	cout << "Podaj swoj nick" << endl;
	cin >> nick;

	ofstream plik;
	plik.open("wynik.txt");
	plik << nick << "  " << wynik;

	plik.close();

	cout << "Twoj wynik zostal zapisany :)" << endl;
}

void zapytanie()
{
	char nazwa{};

	if (k == 0)
	{
		cout << endl;
		cout << "|  A.Zatrzymanie wybranej kosci  |" << endl;
		cout << "|  B.Zapis wyniku do tabeli      |" << endl;
		cout << "|  C.Wyswietlanie tabeli         |" << endl;
		cout << "|  D.Wroc do rzucania koscmi     |" << endl;
		cout << "|  E.Instrukcja                  |" << endl;
	}
	k++;

	cout << endl;
	do
	{
		cout << "Podaj litere przy ktorej zawarta jest funkcja:  ";
		cin >> nazwa;
	} while (nazwa >= 0 && nazwa < 65 || nazwa >69 && nazwa < 97 || nazwa >101);

	sprawdz2(nazwa);

}

void zatrzym(int *kosc)
{
	int oczko{};
	do
	{
		cout << "Podaj ilosc oczek na kosci do zapisu:  ";
		cin >> oczko;
	} while (oczko < 1 || oczko > 6);

	for (int i = 0; i < 5; i++)
	{
		if (i > 0  && *(kosc + i) == oczko)
		{
			*(kosc + i) = 0;    //usuwa zapisana kosc z wskaznika
			tablica[a] = oczko;
			n--;  //zmniejsza ilosc kosci do rzutu
			a++;  //zapisuje kosc
			break;
		}

		if (i == 0 && *kosc == oczko)
		{
			*kosc = 0;    
			tablica[a] = oczko;
			n--;  
			a++;  
			break;
		}
	}

	if (n == 0)
		zapis(&rz[0]);

	zapytanie();
}

void wyswietl()
{
	cout << endl;
	cout << jeden.nazwa << " | " << jeden.punkty << endl;
	cout << dwa.nazwa << " | " << dwa.punkty << endl;
	cout << trzy.nazwa << " | " << trzy.punkty << endl;
	cout << cztery.nazwa << " | " << cztery.punkty << endl;
	cout << piec.nazwa << " | " << piec.punkty << endl;
	cout << szesc.nazwa << " | " << szesc.punkty << endl;
	cout << jed3.nazwa << " | " << jed3.punkty << endl;
	cout << jed4.nazwa << " | " << jed4.punkty << endl;
	cout << full.nazwa << " | " << full.punkty << endl;
	cout << mstrit.nazwa << " | " << mstrit.punkty << endl;
	cout << dstrit.nazwa << " | " << dstrit.punkty << endl;
	cout << general.nazwa << " | " << general.punkty << endl;
	cout << szansa.nazwa << " | " << szansa.punkty << endl;
	zapytanie();
}

void zapis(int *reszta)
{
	string opcja{};
	int suma = 0, liczba = 0, c=0;
	system("cls");
	k = 0;
	cout << "Twoje kosci to: ";
	for (int i = 0; i < 5; i++)
	{
		if (tablica[i] == 0)
		{
			while (*reszta == 0)
			{
				reszta++;
			}
			tablica[i] = *reszta;
			reszta++;
		}
		cout << tablica[i] << " ";
		suma += tablica[i];
	}

	cout << endl;
	cout << "Do jakiej kategorii chcesz wpisac swoje kosci? Wprowadz odpowiednia cyfre" << endl;
	cout << "1.Jedynki" << endl;
	cout << "2.Dwojki" << endl;
	cout << "3.Trojki" << endl;
	cout << "4.Czworki" << endl;
	cout << "5.Piatki" << endl;
	cout << "6.Szostki" << endl;
	cout << "7.3 jednakowe" << endl;
	cout << "8.4 jednakowe" << endl;
	cout << "9.Full" << endl;
	cout << "10.Maly Strit" << endl;
	cout << "11.Duzy Strit" << endl;
	cout << "12.General" << endl;
	cout << "13.Szansa" << endl;
	do
	{
		cin >> liczba;
	} while (liczba > 13);
	c = liczba - 1;

	if (tab[c] == 1)
		zapis(&rz[0]);

	if (liczba == 1 && tab[0] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 1)
			{
				suma += 1;
			}
		}
		jeden.punkty = suma;
		wynik += suma;
		tab[0] = 1;
	}

	if (liczba == 2 && tab[1] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 2)
			{
				suma += 2;
			}
		}
		dwa.punkty = suma;
		wynik += suma;
		tab[1] = 1;
	}

	if (liczba == 3 && tab[2] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 3)
			{
				suma += 3;
			}
		}
		trzy.punkty = suma;
		wynik += suma;
		tab[2] = 1;
	}

	if (liczba == 4 && tab[3] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 4)
			{
				suma += 4;
			}
		}
		cztery.punkty = suma;
		wynik += suma;
		tab[3] = 1;
	}

	if (liczba == 5 && tab[4] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 5)
			{
				suma += 5;
			}
		}
		piec.punkty = suma;
		wynik += suma;
		tab[4] = 1;
	}

	if (liczba == 6 && tab[5] == 0)
	{
		suma = 0;
		for (int i = 0; i < 5; i++)
		{
			if (tablica[i] == 6)
			{
				suma += 6;
			}
		}
		szesc.punkty = suma;
		wynik += suma;
		tab[5] = 1;
	}

	if (liczba == 7 && tab[6] == 0) //3 jednakowe
	{
		int a = 0;
		for (int i = 1; i <= 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tablica[j] == i)
					a += 1;
			}

			if (a < 3)
			{
				a = 0;
				jed3.punkty = 0;
				wynik += 0;
			}

			if (a == 3)
			{
				jed3.punkty = suma;
				wynik += suma;
				break;
			}
		}
		tab[6] = 1;
	}

	if (liczba == 8 && tab[7] == 0) // 4 jednakowe
	{
		int a = 0;
		for (int i = 1; i <= 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tablica[j] == i)
					a += 1;
			}

			if (a < 4)
			{
				a = 0;
				jed4.punkty = 0;
				wynik += 0;
			}

			if (a == 4)
			{
				jed4.punkty = suma;
				wynik += suma;
				break;
			}
		}
		tab[6] = 1;
	}

	if (liczba == 9 && tab[8] == 0) //full
	{
		int a = 0, b = 0;
		for (int i = 1; i <= 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tablica[j] == i)
					a += 1;
			}

			if (a != 2)
				a = 0;

			if (a == 2)
				break;
		}

		for (int i = 1; i <= 6; i++)
		{
			for (int j = 0; j < 5; j++)
			{
				if (tablica[j] == i)
					b += 1;
			}

			if (b != 3)
				b = 0;

			if (b == 3)
				break;
		}

		if (a == 2 && b == 3)
		{
			full.punkty = 25;
			wynik += 25;
		}
		else
		{
			full.punkty = 0;
			wynik += 0;
		}

		tab[8] = 1;
	}

	if (liczba == 10 && tab[9] == 0) // maly strit
	{
		if (tablica[0] == 1 || tablica[1] == 1 || tablica[2] == 1 || tablica[3] == 1 || tablica[4] == 1)
		{
			if (tablica[0] == 2 || tablica[1] == 2 || tablica[2] == 2 || tablica[3] == 2 || tablica[4] == 2)
			{
				if (tablica[0] == 3 || tablica[1] == 3 || tablica[2] == 3 || tablica[3] == 3 || tablica[4] == 3)
				{
					if (tablica[0] == 4 || tablica[1] == 4 || tablica[2] == 4 || tablica[3] == 4 || tablica[4] == 4)
					{
						mstrit.punkty = 30;
						wynik += 30;
					}
				}
			}
		}

		if (tablica[0] == 2 || tablica[1] == 2 || tablica[2] == 2 || tablica[3] == 2 || tablica[4] == 2)
		{
			if (tablica[0] == 3 || tablica[1] == 3 || tablica[2] == 3 || tablica[3] == 3 || tablica[4] == 3)
			{
				if (tablica[0] == 4 || tablica[1] == 4 || tablica[2] == 4 || tablica[3] == 4 || tablica[4] == 4)
				{
					if (tablica[0] == 5 || tablica[1] == 5 || tablica[2] == 5 || tablica[3] == 5 || tablica[4] == 5)
					{
						mstrit.punkty = 30;
						wynik += 30;
					}
				}
			}
		}

		if (tablica[0] == 3 || tablica[1] == 3 || tablica[2] == 3 || tablica[3] == 3 || tablica[4] == 3)
		{
			if (tablica[0] == 4 || tablica[1] == 4 || tablica[2] == 4 || tablica[3] == 4 || tablica[4] == 4)
			{
				if (tablica[0] == 5 || tablica[1] == 5 || tablica[2] == 5 || tablica[3] == 5 || tablica[4] == 5)
				{
					if (tablica[0] == 6 || tablica[1] == 6 || tablica[2] == 6 || tablica[3] == 6 || tablica[4] == 6)
					{
						mstrit.punkty = 30;
						wynik += 30;
					}
				}
			}
		}

		else
		{
			mstrit.punkty = 0;
			wynik += 0;
		}

		tab[9] = 1;
	}

	if (liczba == 11 && tab[10] == 0) //duzy strit
	{
		if (tablica[0] == 1 || tablica[1] == 1 || tablica[2] == 1 || tablica[3] == 1 || tablica[4] == 1)
		{
			if (tablica[0] == 2 || tablica[1] == 2 || tablica[2] == 2 || tablica[3] == 2 || tablica[4] == 2)
			{
				if (tablica[0] == 3 || tablica[1] == 3 || tablica[2] == 3 || tablica[3] == 3 || tablica[4] == 3)
				{
					if (tablica[0] == 4 || tablica[1] == 4 || tablica[2] == 4 || tablica[3] == 4 || tablica[4] == 4)
					{
						if (tablica[0] == 5 || tablica[1] == 5 || tablica[2] == 5 || tablica[3] == 5 || tablica[4] == 5)
						{
							dstrit.punkty = 40;
							wynik += 40;
						}
					}
				}
			}
		}

		if (tablica[0] == 2 || tablica[1] == 2 || tablica[2] == 2 || tablica[3] == 2 || tablica[4] == 2)
		{
			if (tablica[0] == 3 || tablica[1] == 3 || tablica[2] == 3 || tablica[3] == 3 || tablica[4] == 3)
			{
				if (tablica[0] == 4 || tablica[1] == 4 || tablica[2] == 4 || tablica[3] == 4 || tablica[4] == 4)
				{
					if (tablica[0] == 5 || tablica[1] == 5 || tablica[2] == 5 || tablica[3] == 5 || tablica[4] == 5)
					{
						if (tablica[0] == 6 || tablica[1] == 6 || tablica[2] == 6 || tablica[3] == 6 || tablica[4] == 6)
						{
							dstrit.punkty = 40;
							wynik += 40;
						}
					}
				}
			}
		}
		tab[10] = 1;
	}

	if (liczba == 12 && tab[11] == 0) //general
	{
		if (tablica[0] == tablica[1] && tablica[1] == tablica[2] && tablica[2] == tablica[3] && tablica[3] == tablica[4])
		{
			general.punkty = 50;
			wynik += 50;
		}
		else
			general.punkty = 0;

		tab[11] = 1;
	}

	if (liczba == 13 && tab[12] == 0) //szansa
	{
		szansa.punkty = suma;
		wynik += suma;
		tab[12] = 1;
	}

	// Ustawianie zmiennych globalnych na pozycjach startowych
	rzut = 1;
	for (int i = 0; i < 5; i++)
	{
		rz[i] = 0;
		tablica[i] = 0;
	}
	n = 5;
	a = 0;

	if (tab[12] == 1 && tab[11] == 1 && tab[10] == 1 && tab[9] == 1 && tab[8] == 1 && tab[7] == 1 && tab[6] == 1 && tab[5] == 1 && tab[4] == 1 && tab[3] == 1 && tab[2] == 1 && tab[1] == 1)
		wyniki();

	rzuty();

}