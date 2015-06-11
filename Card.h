#pragma once
#include <string>

using namespace std;

class Card
{
  protected:
    string znak_karty;
    int figura;
    int kolor;
    
  public:
    Card(){};
    Card(int, int);
    Card(const Card &);
    
    void wyswietl_karte();
    int get_kolor();

    bool operator <(const Card &);
    bool operator >(const Card &);
    bool operator ==(const Card &);
    bool operator ==(int);
    bool operator > (int);
};
