#include "Pile.h"
#include "Card.h"

#include <iostream>

using namespace std;

Pile:: Pile()
{
  rozmiar =0;
  stos = new Card[rozmiar];
}

Pile:: ~Pile()
{
  delete []stos;
}

Card Pile:: gorna_karta()
{
  if(rozmiar!=0)
    return stos[rozmiar-1];
  else
    cout << "Pusty stos" << endl;
}

int Pile:: get_rozmiar()
{
  return rozmiar;
}

void Pile:: dodaj_karte(Card A)
{
  Card *help = new Card[rozmiar+1];
  for(int i=0; i<rozmiar; i++)
  {
    help[i] = stos[i];
  }
  help[rozmiar] = A;
  
  if(A==2) ilosc_kart_do_wziecia+=2;
  if(A==3) ilosc_kart_do_wziecia+=3;
  if(A==13 && A.get_kolor()==3) ilosc_kart_do_wziecia+=5;
  if(A==13 && A.get_kolor()==0) ilosc_kart_do_wziecia+=5;
  
  delete []stos;
  stos = help;
  rozmiar +=1;
}

Card* Pile:: oddaj_do_talii()
{
  Card ob = Card(stos[rozmiar-1]);
  Card *help = new Card[rozmiar-1];
  
  for(int i=0; i<rozmiar-2; i++)
  {
    help[i] = stos[i];
  }
  
  delete []stos;
  rozmiar = 1;
  stos = new Card[rozmiar];
  stos[rozmiar-1] = ob;
  
  return help;
}

