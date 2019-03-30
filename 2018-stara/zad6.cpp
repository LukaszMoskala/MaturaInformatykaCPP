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
string slowa[1000][2];
//UWAGA: w celu optymalizacji funkcja zakłada że slowo1 i slowo2 zawierają
//WYŁĄCZNIE wielkie litery alfabetu angielskiego (spełnia warunki zadania)
//przy próbie uruchomienia z innymi danymi prawdopodobnie przywita Cię
//SIGSEGV
bool sprawdzAnagram(const string& slowo1, const string& slowo2) {
  //nie może być anagramem jeżeli mają różne długości
  //nie trzeba tego sprawdzać, ale jest to optymalizacja
  if(slowo1.size() != slowo2.size()) {
    return false;
  }
  uint8_t ilosci1[26];
  uint8_t ilosci2[26];
  memset(ilosci1, 0, sizeof(ilosci1));
  memset(ilosci2, 0, sizeof(ilosci2));
  //można było użyć 1 pętli bo wcześniej sprawdziliśmy czy dane są tej samej
  //długości, jednakowoż pisanie idiotoodpornych programów jest dobrym
  //nawykiem (choć jak bardzo idiotoodporny program by nie był, wszechświat
  //i tak wyprodukuje większego idiote)
  for(uint32_t i=0;i<slowo1.size();i++) {
    ilosci1[int(slowo1[i]-'A')]++;
  }
  for(uint32_t i=0;i<slowo2.size();i++) {
    ilosci2[int(slowo2[i]-'A')]++;
  }

  return (memcmp(ilosci1, ilosci2, 26) == 0);
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
  plik.open("slowa.txt");
  if(!plik.is_open()) {
    return 1;
  }
  for(int i=0; i<1000; i++)
  {
    plik>>slowa[i][0];
    plik>>slowa[i][1];
  }
  plik.close();

  //6.1
  int ile_na_a=0;
  for(int i=0;i<1000;i++) {
    ile_na_a+=(slowa[i][0][slowa[i][0].size()-1] == 'A');
    ile_na_a+=(slowa[i][1][slowa[i][1].size()-1] == 'A');
  }
  cout<<"[6.1] "<<ile_na_a<<endl;
  //6.2
  int drugie_w_pierwszym=0;
  for(int i=0;i<1000;i++) {
    drugie_w_pierwszym+=(slowa[i][0].find(slowa[i][1]) != string::npos);
  }
  cout<<"[6.2] "<<drugie_w_pierwszym<<" - W ODPOWIEDZIACH JEST 234"<<endl;
  //6.3
  int anagramy=0;
  for(int i=0;i<1000;i++) {
    anagramy+=sprawdzAnagram(slowa[i][0],slowa[i][1]);
  }
  cout<<"[6.3] "<<anagramy<<endl;
}
