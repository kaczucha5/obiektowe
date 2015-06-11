#include <iostream>
#include <time.h>
#include <stdlib.h>
#include "Card.h"
#include "Deck.h"
#include "Player.h"
#include "Pile.h"
#include "User_Player.h"

using namespace std;

int main()
{
  srand(time(NULL));
  int wybor = 0;
  Card karta = Card(0,0);
  Deck talia = Deck();
  Pile stos = Pile();
  User_Player uzytkownik = User_Player("Marek");
  
  Player gracze[3] = {Player("Gracz 1"), Player("Gracz 2"), Player("Gracz 3")};
	
  // poczatek gry, wszystkie funkcje przygotowcze
  // (tasujemy talie, rozdajemy graczom karty, dajemy
  // pierwsza karte na stos
  cout << "Program tasuje talie." << endl;
  talia.tasowanie();
  cin.get();
  
  cout << "Rozdaje karty graczom." << endl;
  for(int i=0; i<5; i++)
  {
    gracze[0].dodaj_karte(talia.oddaj_gorna());
    gracze[1].dodaj_karte(talia.oddaj_gorna());
    gracze[2].dodaj_karte(talia.oddaj_gorna());
    uzytkownik.dodaj_karte(talia.oddaj_gorna());
  }
  cin.get();
  
  cout << "Program wystawia pierwsza karte na stos." << endl;
  do
  {
    stos.dodaj_karte(talia.oddaj_gorna());
  }while(stos.gorna_karta() == 2 && stos.gorna_karta() > 3 && stos.gorna_karta() > 10);

  //tu sie konczy poczatek
  cout << "Karta stosu: ";
  stos.gorna_karta().wyswietl_karte();
  cin.get();
  
  while(gracze[0].wygrana() != true && gracze[1].wygrana()!= true && gracze[2].wygrana() != true && uzytkownik.wygrana() != true)
  {
    for(int z=0; z<3; z++)
    {
      karta = gracze[z].oddaj_karte(stos.gorna_karta());
      if(karta == 0)	
      {
	if(talia.czy_pusta())
	{
	  talia.pobierz_ze_stosu(stos.get_rozmiar()-1, stos.oddaj_do_talii());
	  talia.tasowanie();
	}
	cout << gracze[z].wyswietl_nazwe()<< " ciagnie karte z talii" << endl;
	gracze[z].dodaj_karte(talia.oddaj_gorna());
      }
      else
      {
	cout << gracze[z].wyswietl_nazwe() << " dorzuca karte: ";
	karta.wyswietl_karte();
	stos.dodaj_karte(karta);
      }
      
      cout << gracze[z].makao() << endl;
      if(gracze[z].wygrana())
      {
	cout << endl << gracze[z].wyswietl_nazwe() << " wygrywa!";
	cin.get();
	return 0;
      }
	
      cin.get();
      cout << "Karta stosu: ";
      stos.gorna_karta().wyswietl_karte();
      
    }
    
    cout <<  "Twoja kolej" << endl;
    cout << "Oto twoje karty" << endl;
    uzytkownik.wyswietl_karty();
    
    cout << endl << "Co chcesz zrobic:" << endl;
    cout << "1. Dorzuc karte" << endl;
    cout << "2. Ciagnij karte z talii" << endl;
    cout << "Twoj wybor: ";
    
    while(wybor<1 || wybor >2)
    {
      cin >> wybor;
      
      switch(wybor)
      {
	case 1:
	{
	  bool sprawdz = false;
	  while(!sprawdz)
	  {
	    int nr_karty=0;
	    while(nr_karty<1 || nr_karty>uzytkownik.get_rozmiar())
	    {
	      cout << endl << "Wybierz nr karty: ";
	      cin >> nr_karty;
	      if(nr_karty<1 || nr_karty>uzytkownik.get_rozmiar())
		cout << "Nie ma takiej karty" << endl 
		      << "Wybierz nr karty jeszcze raz: ";
	    }
	    
	    sprawdz = uzytkownik.sprawdz_karte(nr_karty, stos.gorna_karta());
	    
	    if(sprawdz)
	    {
	      stos.dodaj_karte(uzytkownik.oddaj_karte(nr_karty-1));
	      cout << uzytkownik.wyswietl_nazwe()
		    << " dorzuca karte: " ;
	      stos.gorna_karta().wyswietl_karte(); 
	      cin.get();
	    }
	    else
	    {
	      cout << "Wybrales zla karte" << endl
		   << "Wybierz nr karty jeszcze raz: ";
	    }
	  };
	  break;
	}
	case 2:
	{
	  cout << endl << uzytkownik.wyswietl_nazwe() << " ciagnie karte z talii" << endl;
	  uzytkownik.dodaj_karte(talia.oddaj_gorna());
	  cin.get();
	  break;
	}
	default:
	{
	  cout << endl <<"Wybrana opcja nie istnieje" << endl
	      << "Wybierz jeszcze raz: ";
	}
      }
    };
    
    wybor = 0;
    if(uzytkownik.wygrana())
    {
      cout << endl << "Wygrales!";
      cin.get();
      break;
    }
	
    cout << "Karta stosu: ";
    stos.gorna_karta().wyswietl_karte();
    cout << endl;
  };
}
