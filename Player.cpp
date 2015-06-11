#include <iostream>
#include "Player.h"
#include "Card.h"

using namespace std;

Player:: Player(string n_nazwa)
{
  nazwa = n_nazwa;
  rozmiar = 0;
  karty = new Card[rozmiar];
}

Player:: ~Player()
{
  delete []karty;
}

string Player:: wyswietl_nazwe()
{
  return nazwa;
}

void Player:: wyswietl_karty()
{
  for(int i=0; i<rozmiar; i++)
  {
    cout << i+1 << " ";
    karty[i].wyswietl_karte();
  }
}

bool Player:: wygrana()
{
  if(rozmiar == 0)
    return true;
  else
    return false;
}

string Player:: makao()
{
  if(rozmiar == 1)
    return "Makao!";
  if(rozmiar == 0)
    return "Po makale!";
  else
    return "";
}

Card Player:: oddaj_karte(const Card &A)
{
  Card ob = Card(0,0);
  int miejsce=-1;
  
  for(int i=0; i<rozmiar; i++)
  {
    if(karty[i] == A)
    {
      Card *help = new Card[rozmiar-1];
      ob = Card(karty[i]);
      miejsce = i;
      for(int i=0; i<miejsce; i++)
      {
	help[i] = karty[i];
      }
      
      for(int i=miejsce+1; i<rozmiar; i++)
      {
	help[i-1] = karty[i];
      }
      
      delete []karty;
      karty = help;
      rozmiar-=1;
      
      return ob;
    }
  }	
  return ob;
}

void Player:: dodaj_karte(const Card &A)
{
  Card *help = new Card[rozmiar+1];
  for(int i=0; i<rozmiar; i++)
  {
    help[i] = karty[i];
  }
  help[rozmiar] = A;
  
  delete []karty;
  karty = help;
  rozmiar +=1;
}

