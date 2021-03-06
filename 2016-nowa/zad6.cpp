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
using namespace std;
//jak klucz jest ujemny to funkcja odszyfrowywuje
//łatwiej było tak zrobić niż pisać osobną funkcje
string szyfruj(const string& dane, int klucz) {
  //jeżeli to usuniemy, trzeba zmienić w tej funkcji IFy na WHILE
  //jednak to rozwiązanie jest bardziej optymalne pod względem złożoności
  //obliczeniowej
  klucz%=26; //usuwamy pętle z klucza
  string ret="";
  for(uint32_t i=0;i<dane.size();i++) {
    int znak=dane[i]+klucz;
    if(znak > 90)
      znak-=26;
    if(znak < 65)
      znak+=26;
    ret+=char(znak);
  }
  return ret;
}
int odzyskajklucz(const string& tj, const string& sz) {
  for(int i=1;i<=26;i++) {
    if(szyfruj(tj, i) == sz)
      return i;
  }
  return 0;
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
  cout<<"Jestem nieoptymalny i wykonuje się długo! nie wystrasz się jak"<<endl;
  cout<<"nie bedziesz widzial zadnej odpowiedzi przez dlugi czas"<<endl;
  ifstream f;
  ofstream o;
  f.open("dane_6_1.txt");
  o.open("wyniki_6_1.txt");
  if(!f.is_open() || !o.is_open())
    return 1;
  for(int i=0;i<100;i++) {
    string s;
    f>>s;
    o<<szyfruj(s,107)<<endl;
  }
  f.close();
  o.close();

  f.open("dane_6_2.txt");
  o.open("wyniki_6_2.txt");
  if(!f.is_open() || !o.is_open())
    return 1;
  for(int i=0;i<3000;i++) {
    string s;
    int k;
    f>>s;
    f>>k;
    o<<szyfruj(s,-k)<<endl;
  }
  f.close();
  o.close();

  f.open("dane_6_3.txt");
  o.open("wyniki_6_3.txt");
  if(!f.is_open() || !o.is_open())
    return 1;
  for(int i=0;i<3000;i++) {
    string tj;
    string sz;
    f>>tj;
    f>>sz;
    //pod względem złożoności obliczeniowej ten kod to tragedia
    //na szczęście na maturze tego nie oceniają xD
    //w rzeczywistości, jeżeli twój program uruchomisz tylko raz
    //bo służy do rozwiązania tylko jednego konkretnego problemu
    //jest to ok. Ale jak twój program będzie włączony ciągle,
    //optymalizacja staje się bardzo ważna. Tutaj na szczęście jest
    //ten pierwszy przypadek
    for(uint32_t j=1;j<tj.size();j++) {
      if(odzyskajklucz(tj.substr(j,1),sz.substr(j,1)) !=
         odzyskajklucz(tj.substr(j-1,1),sz.substr(j-1,1)) ) {
        o<<tj<<endl;
        break;
      }
    }
  }
  f.close();
  o.close();
  cout<<"Udało się!!! Odpowiedzi masz w wyniki_6_*.txt"<<endl;
}
