#include "User_Player.h"

User_Player:: User_Player(string n_nazwa)
{
  nazwa = n_nazwa;
  rozmiar = 0;
  karty = new Card[rozmiar];
}
  
int User_Player:: get_rozmiar()
{
  return rozmiar;
}

bool User_Player:: sprawdz_karte(int nr, Card A)
{
  if(karty[nr-1] == A)
    return true;
  else
    return false;
}

Card User_Player:: oddaj_karte(int nr)
{
  Card *help = new Card[rozmiar-1];
  Card ob = Card(karty[nr]);
  int miejsce = nr;

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