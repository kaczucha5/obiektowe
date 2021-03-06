#include "Card.h"
#include <iostream>
#include <string>

using namespace std;

string tab[13] = {"2","3","4","5","6","7","8","9","10","J","Q","K","A"};
string tab2[4] = {"pik", "trefl", "karo", "kier"};

Card:: Card(int n_figura, int n_kolor)
{
  if(n_figura ==0 && n_kolor == 0)
  {
    znak_karty = "brak";
    figura =0;
    kolor =0;
  }
  else
  {	
    figura = n_figura;
    kolor = n_kolor-1;
    znak_karty = tab[figura-2]+"_"+tab2[kolor];
  }
}

Card:: Card(const Card &A)
{
  znak_karty = A.znak_karty;
  figura = A.figura;
  kolor = A.kolor;
}

void Card:: wyswietl_karte()
{
  cout << znak_karty << endl;
}

int Card:: get_kolor()
{
  return kolor;
}

bool Card:: operator <(const Card &A)
{
  if(figura < A.figura)
    return true;
  else
    return false;
}

bool Card:: operator >(const Card &A)
{
  if(figura > A.figura)
    return true;
  else
    return false;
}
bool Card:: operator ==(const Card &A)
{
  if(figura ==  A.figura || kolor == A.kolor)
    return true;
  else
    return false;
}

bool Card:: operator == (int n_figura)
{
  if(figura == n_figura)
    return true;
  else
    return false;
}

bool Card:: operator > (int n_figura)
{
  if(figura > n_figura)
    return true;
  else
    return false;
}
