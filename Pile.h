#pragma once
#include "Card.h"

class Pile
{
  protected:
    int rozmiar;
    int ilosc_kart_do_wziecia;
    Card *stos;

  public:
    Pile();
    ~Pile();

    int get_rozmiar();
    Card gorna_karta();
    void dodaj_karte(Card);
    Card* oddaj_do_talii();
};
