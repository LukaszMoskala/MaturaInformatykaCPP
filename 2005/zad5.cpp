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
#include <vector>
#include <sstream>
using namespace std;
vector<int> ciag;
int ilosci[1000];
int sumaItself(uint32_t start, uint32_t end) {
  int ret=0;
  for(uint32_t i=start;i<=end;i++) {
    ret+=ciag[i];
  }
  return ret;
}
int supersumakozakwogolesuperfajne() {
  int max=0;
  for(uint32_t poczatek=0;poczatek<ciag.size();poczatek++) {
    for(uint32_t koniec=poczatek;koniec<ciag.size();koniec++) {
      int t=sumaItself(poczatek, koniec);
      if(t > max)
        max=t;
    }
  }
  return max;
}
//złożoność obliczeniowa tego syfu to n^2 lub n^3.
//Arkusz z odpowiedziami wspomina możliwość stworzenia algorytmu o złożoności
//znacznie lepszej niż n^2
//ja nie będę próbował tego robić, ale jak ktoś ma pomysł, spróbuj i stwórz
//pull request jak się uda
int najpopularniejsze() {
  memset(ilosci, 0, sizeof(ilosci));
  for(uint32_t i=0;i<ciag.size();i++) {
    ilosci[ciag[i]+500]++;
  }
  uint32_t imax=0;
  for(uint32_t i=1;i<1000;i++) {
    if(ilosci[i] > ilosci[imax])
      imax=i;
  }
  return imax-500;
}
void zaladowawszy(const char* f) {
  ifstream plik;
  plik.open(f);
  if(!plik.is_open())
    exit(1);
  while(plik.good()) {
   int l;
   plik>>l;
    if(plik.good()) {
      ciag.push_back(l);
    }
  }
  plik.close();
}
int main() {
  cout<<"Copyright (C) 2019 Łukasz Konrad Moskała ukasz_moskala8@tlen.pl"<<endl;
  cout<<"This program comes with ABSOLUTELY NO WARRANTY."<<endl;
  cout<<"This is free software, and you are welcome to redistribute it"<<endl;
  cout<<"under certain conditions; Read attached license file for details."<<endl;
  cout<<endl;
  cout<<"You should have received a copy of the GNU General Public License"<<endl;
  cout<<"along with this program.  If not, see <https://www.gnu.org/licenses/>."<<endl;
  cout<<endl;

  cout<<"#####################################################################"<<endl;
  cout<<"# TRAGICZNA ZŁOŻONOŚĆ OBLICZENIOWA PROGRAM WYKONUJE SIE BARDZO DŁUGO#"<<endl;
  cout<<"#  i5-4670k @ 4.9GHz - 5 minut 36 sekund  -  ostrzegałem            #"<<endl;
  cout<<"#####################################################################"<<endl;
  cout<<endl;

  zaladowawszy("dane5-1.txt");
  cout<<"5.1 "<<supersumakozakwogolesuperfajne()<<" "<<najpopularniejsze()<<endl;
  ciag.erase(ciag.begin(), ciag.end());
  zaladowawszy("dane5-2.txt");
  cout<<"5.2 "<<supersumakozakwogolesuperfajne()<<" "<<najpopularniejsze()<<endl;
  ciag.erase(ciag.begin(), ciag.end());
  zaladowawszy("dane5-3.txt");
  cout<<"5.3 "<<supersumakozakwogolesuperfajne()<<" "<<najpopularniejsze()<<endl;
  ciag.erase(ciag.begin(), ciag.end());
}
