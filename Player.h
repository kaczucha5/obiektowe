#pragma once
#include <string>
#include "Card.h"

using namespace std;

class Player
{
  protected:
    string nazwa;
    int rozmiar;
    Card *karty;
    
  public:
    Player(){};
    Player(string);
    ~Player();
    
    string wyswietl_nazwe();
    void wyswietl_karty();
    bool wygrana();
    string makao();
    bool po_makale();
    Card oddaj_karte(const Card &);
    void dodaj_karte(const Card &);	
};
