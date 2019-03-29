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
string liczby[1000];
int main() {
  ifstream plik;
  plik.open("liczby.txt");
  if(!plik.is_open())
    return 1;
  for(int i=0;i<1000;i++) {
    plik>>liczby[i];
  }
  plik.close();

  //4.1
  int ile=0;
  for(int i=0;i<1000;i++) {
    int z[2]={0,0};
    for(uint32_t j=0;j<liczby[i].size();j++) {
      z[ liczby[i][j]-'0' ]++;
    }
    ile+=(z[0] > z[1]);
  }

  cout<<"[4.1] "<<ile<<endl;

  //4.2
  int przez2=0;
  int przez8=0;
  for(int i=0;i<1000;i++) {
    //liczba binarna jest podzielna przez 2, jeżeli jej ostatnia cyfra to 0
    if(liczby[i][liczby[i].size()-1] == '0')
      przez2++;
    //jest podzielna przez 3 jeżeli 3 ostatnie cyfry to 0
    //Teoretycznie, powinno się tu sprawdzać czy liczba ma co najmniej 3 cyfry
    //ale chyba wszystkie mają bo mi się ten program nie wysypał xD

    //EDIT: przy próbie rozwiązania 4.3 okazało się że najkrótsza liczba w pliku
    //ma dokładnie 3 cyfry, także brak sprawdzania długości tutaj przejdzie
    if(liczby[i].substr(liczby[i].size()-3) == "000")
      przez8++;
  }
  cout<<"[4.2] Przez 2: "<<przez2<<" Przez 8: "<<przez8<<endl;

  //4.3
  //najpierw szukamy najdłuższej i najkrótszej
  //to NIE JEST to samo co największa i najmniejsza
  //ale zawęzi obszar poszukiwań

  int dnm=250;
  int dnw=0;

  for(int i=0;i<1000;i++) {
    if(liczby[i].size() > dnw)
      dnw=liczby[i].size();
    if(liczby[i].size() < dnm)
      dnm=liczby[i].size();
  }
  cout<<"[4.3]"<<endl;
  //Ok, mamy już ich długość. Problem w tym że jest ich więcej niż 1
  uint8_t zle[1000]; //w tej tablicy oznaczamy indeksy liczb które na pewno
  //nie będą największe

  //to jest złe, ale działa, więc w sumie nie jest złe
  memset(zle,0,sizeof(zle));
  for(int i=0;i<dnw;i++) {
    bool czy_wogole_na_tej_pozycji_sa_jedynki=false;
    for(int j=0;j<1000 && !czy_wogole_na_tej_pozycji_sa_jedynki;j++) {
      if(!zle[j] && liczby[j].size() == dnw) {
        if(liczby[j][i] == '1')
          czy_wogole_na_tej_pozycji_sa_jedynki=true;
      }
    }
    if(czy_wogole_na_tej_pozycji_sa_jedynki) {
      for(int j=0;j<1000;j++) {
        if(liczby[j].size() == dnw) {
          if(liczby[j][i] == '0')
            zle[j]=1;
        }
      }
    }
  }
  for(int i=0;i<1000;i++) {
    if(!zle[i] && liczby[i].size() == dnw)
      cout<<"indeks największej: "<<i+1<<endl;
  }
  //i to samo dla najmneijszej
  memset(zle,0,sizeof(zle));
  for(int i=0;i<dnm;i++) {
    bool czy_wogole_na_tej_pozycji_sa_zera=false;
    for(int j=0;j<1000 && !czy_wogole_na_tej_pozycji_sa_zera;j++) {
      if(!zle[j] && liczby[j].size() == dnm) {
        if(liczby[j][i] == '0')
          czy_wogole_na_tej_pozycji_sa_zera=true;
      }
    }
    if(czy_wogole_na_tej_pozycji_sa_zera) {
      for(int j=0;j<1000;j++) {
        if(liczby[j].size() == dnm) {
          if(liczby[j][i] == '1')
            zle[j]=1;
        }
      }
    }
  }
  for(int i=0;i<1000;i++) {
    if(!zle[i] && liczby[i].size() == dnm)
      cout<<"indeks najmniejszej: "<<i+1<<endl;
  }
}
