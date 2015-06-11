#pragma once
#include "Card.h"

class Deck
{
  protected:
    int rozmiar;
    Card *talia;
    
  public:
    Deck();
    ~Deck();
    
    void wyswietl_talie();
    void tasowanie();
    void pobierz_ze_stosu(int, Card*);
    bool czy_pusta();
    
    Card oddaj_gorna();
		
};
