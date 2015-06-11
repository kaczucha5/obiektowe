#pragma once

#include "Player.h"

class User_Player: public Player
{
  public:
    User_Player(){};
    User_Player(string);
    
    int get_rozmiar();
    bool sprawdz_karte(int, Card);
    Card oddaj_karte(int);
};