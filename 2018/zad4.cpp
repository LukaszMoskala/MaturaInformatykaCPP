/*
Copyright (C) 2019 Łukasz Konrad Moskała

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;
string sygnaly[1000];

int main()
{
  ifstream plik;
  plik.open("sygnaly.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<1000;i++)
    plik>>sygnaly[i];
  plik.close();

  //4.1
  //Naukowcy zauważyli, że po złączeniu dziesiątych liter co czterdziestego
  //słowa (zaczynając od słowa czterdziestego) otrzymamy pewne przesłanie.
  //Wypisz to przesłanie.

  //i=39 bo numerujemy od 0
  cout<<"[4.1] ";
  for(int i=39;i<1000;i+=40) {
    cout<<sygnaly[i][9];
  }
  cout<<endl;

  //4.2
  //Znajdź słowo, w którym występuje największa liczba różnych liter. Wypisz to
  //słowo i liczbę występujących w nim różnych liter. Jeśli słów o największej
  //liczbie różnych liter jest więcej niż jedno, wypisz pierwsze z nich
  //pojawiające się w pliku z danymi.
  uint8_t litery[256];
  int max=0;
  int imax=0;
  for(int i=0;i<1000;i++) {
    memset(litery, 0, sizeof(litery));
    for(uint32_t j=0;j<sygnaly[i].size();j++) {
      litery[sygnaly[i][j]]++;
    }
    int ile=0;
    for(int i=0;i<256;i++)
      ile+=(litery[i] > 0);
    if(ile > max) {
      max=ile;
      imax=i;
    }
  }
  cout<<"[4.2] "<<sygnaly[imax]<<" "<<max<<endl;


  //4.3
  //tym zadaniu rozważmy odległość liter w alfabecie – np. litery A i B są od
  //siebie oddalone  o 1, A i E o 4, F i D o 2, a każda litera od siebie samej
  //jest oddalona o 0. Wypisz wszystkie słowa, w których każde dwie litery
  //oddalone są od siebie w alfabecie co najwyżej o 10. Słowa wypisz w
  //kolejności występowania w pliku sygnaly.txt, po jednym w wierszu.

  cout<<"[4.3]\t";
  for(int i=0;i<1000;i++) {
    bool ok=true;
    string s=sygnaly[i];
    for(uint32_t j=1;(j<s.size()) && ok;j++) {
      int l0=s[j-1];
      int l1=s[j];
      ok=(abs(l1-l0) <= 10);
    }
    if(ok)
      cout<<"\t"<<sygnaly[i]<<endl;
  }
  cout<<"UWAGA: ZADANIE [4.3] PRODUKUJE WYNIK NIEZGODNY Z TYM CO JEST W ODPOWIEDZIACH"<<endl;
  cout<<"       ale no nie widze jak inaczej może to być, jak znalazłeś mój błąd - "<<endl;
  cout<<"       stwórz pull request z poprawką"<<endl;

}
