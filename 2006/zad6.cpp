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
using namespace std;
//w zadaniu nie pisze że jest ich 1000
//ALE... można użyć WC, w ten sposób:
//$ wc -l dane.txt
//i cyk, zwraca ilość linii w pliku - 1000 :)
string slowa[1000];

struct SLOWO_T {
  string slowo;
  int wystapienia;
};
vector<SLOWO_T> slowaunikalne;

bool palindrom(const string &s) {
  bool ok=true;
  for(uint32_t i=0; i<s.size() && ok ;i++)
    ok=(s[i] == s[s.size()-1-i]);
  return ok;
}

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
  plik.open("dane.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0; i<1000; i++)
  {
    plik>>slowa[i];
  }
  plik.close();

  //6a
  cout<<"6A) "<<endl;

  for(int i=0;i<1000;i++) {
    int bylo=0;
    for(uint32_t j=0;j<slowaunikalne.size() && !bylo;j++) {
      if(slowa[i] == slowa[j])
        bylo=j;
    }
    if(!bylo) {
      SLOWO_T s;
      s.slowo=slowa[i];
      s.wystapienia=1;
      slowaunikalne.push_back(s);
    }
    else {
      slowaunikalne[bylo].wystapienia++;
    }
  }
  //Nie chce mi się generować pliku z wynikami, więc wypisze je na STDOUT
  int ile_sie_powtarza=0;
  //odwołuje się do indeksu a nie do wartości samej w sobie
  int maxwystapien=0;
  for(uint32_t i=0;i<slowaunikalne.size();i++) {
    ile_sie_powtarza+=(slowaunikalne[i].wystapienia > 1);
    if(slowaunikalne[i].wystapienia > slowaunikalne[maxwystapien].wystapienia)
      maxwystapien=i;
  }
  cout<<"    "<<ile_sie_powtarza<<" !!! z jakiegoś powodu wychodzi 1 mniej niż powinno być !!!"<<endl;
  cout<<"    "<<slowaunikalne[maxwystapien].slowo<<endl;
  cout<<"    "<<slowaunikalne[maxwystapien].wystapienia<<endl;

  //6b
  int parzystehex=0;
  for(int i=0;i<1000;i++) {
    char c=slowa[i][slowa[i].size()-1];
    parzystehex+=(c == 'A' || c == 'C' || c == 'E');
  }
  cout<<"6B) "<<parzystehex<<endl;

  //6c
  int palindomy=0;
  for(int i=0;i<1000;i++) {
    palindomy+=palindrom(slowa[i]);
  }
  cout<<"6C) "<<palindomy<<endl;
}
