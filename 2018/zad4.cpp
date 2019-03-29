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
  cout<<"Copyright (C) 2019 Łukasz Konrad Moskała ukasz_moskala8@tlen.pl"<<endl;
  cout<<"This program comes with ABSOLUTELY NO WARRANTY."<<endl;
  cout<<"This is free software, and you are welcome to redistribute it"<<endl;
  cout<<"under certain conditions; Read attached license file for details."<<endl;
  cout<<endl;
  cout<<"You should have received a copy of the GNU General Public License"<<endl;
  cout<<"along with this program.  If not, see <https://www.gnu.org/licenses/>."<<endl;
  cout<<endl;
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
      litery[int(sygnaly[i][j])]++;
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

  cout<<"[4.3]";
  for(int i=0;i<1000;i++) {
    bool ok=true;
    string s=sygnaly[i];
    for(uint32_t j=0;(j<s.size()) && ok;j++) {
      for(uint32_t k=0;k<s.size() && ok;k++) {
        int l0=s[j];
        int l1=s[k];
        ok=(abs(l1-l0) <= 10);
      }
    }
    if(ok)
      cout<<"\t"<<sygnaly[i]<<endl;
  }

}
